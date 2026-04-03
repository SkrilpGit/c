#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>
#include "int_linked_list.h"

#define STRESS_COUNT 10000

int main() {
    printf("--- BEGINNING PUNISHING TEST SUITE ---\n");

    // 1. NULL POINTER STABILITY
    // A robust library shouldn't crash if passed NULL (it should just return false)
    printf("Testing NULL pointer safety... \n");
    int dummy_val;
    assert(int_linked_list_size(NULL) == 0);
    assert(int_linked_list_push_back(NULL, 10) == false);
    assert(int_linked_list_get(NULL, 0, &dummy_val) == false);
    // int_linked_list_destroy(NULL); // Uncomment if you expect it to handle NULL
    printf("PASSED\n");

    // 2. OUT-OF-BOUNDS GAUNTLET
    IntLinkedList *list = int_linked_list_create();
    printf("Testing boundary conditions... \n");
    assert(int_linked_list_insert(list, 1, 500) == false); // Insert at 1 in empty list
    assert(int_linked_list_remove_at(list, 0, &dummy_val) == false);
    assert(int_linked_list_get(list, 0, &dummy_val) == false);
    printf("PASSED\n");

    // 3. THE "YOYO" TEST (Head/Tail churn)
    printf("Testing head/tail churn... \n");
    for(int i = 0; i < 100; i++) {
        int_linked_list_push_front(list, i); // [i]
        int_linked_list_pop_back(list, &dummy_val); // []
    }
    assert(int_linked_list_size(list) == 0);
    assert(int_linked_list_is_empty(list) == true);
    printf("PASSED\n");

    // 4. STRESS TEST (Large Data & Order Verification)
    printf("Running stress test (%d elements)... \n", STRESS_COUNT);
    for(int i = 0; i < STRESS_COUNT; i++) {
        assert(int_linked_list_push_back(list, i) == true);
    }
    assert(int_linked_list_size(list) == STRESS_COUNT);

    for(int i = 0; i < STRESS_COUNT; i++) {
        int_linked_list_get(list, i, &dummy_val);
        if(dummy_val != i) {
            printf("FAILED (Value mismatch at index %d)\n", i);
            return 1;
        }
    }
    printf("PASSED\n");

    // 5. INTERLEAVED INSTANCES (Checking for global variable hacks)
    printf("Testing multiple instances... \n");
    IntLinkedList *list2 = int_linked_list_create();
    int_linked_list_push_back(list, 1);
    int_linked_list_push_back(list2, 2);
    assert(int_linked_list_size(list) == STRESS_COUNT + 1);
    assert(int_linked_list_size(list2) == 1);
    int_linked_list_destroy(list2);
    printf("PASSED\n");

    // 6. DEEP CLEAR
    printf("Testing clear/reuse cycle... \n");
    int_linked_list_clear(list);
    assert(int_linked_list_size(list) == 0);
    int_linked_list_push_back(list, 999);
    assert(int_linked_list_get(list, 0, &dummy_val) == true && dummy_val == 999);
    printf("PASSED\n");

    int_linked_list_destroy(list);
    printf("\n--- ALL TESTS PASSED. RUN VALGRIND TO BE SURE ---\n");

    return 0;
}
