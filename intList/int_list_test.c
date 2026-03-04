#include <stdio.h>
#include <assert.h>
#include "int_list.h"

int main(void) {
    // Create a new list
    IntList *list = int_list_create(2);
    assert(list != NULL);
    assert(int_list_size(list) == 0);
    assert(int_list_is_empty(list));

    // Push back some elements
    assert(int_list_push_back(list, 10));
    assert(int_list_push_back(list, 20));
    assert(int_list_size(list) == 2);

    int value;
    assert(int_list_get(list, 0, &value));
    printf("Element 0: %d\n", value); // Should print 10

    assert(int_list_get(list, 1, &value));
    printf("Element 1: %d\n", value); // Should print 20

    // Set a value
    assert(int_list_set(list, 1, 25));
    assert(int_list_get(list, 1, &value));
    printf("Updated Element 1: %d\n", value); // Should print 25

    // Insert at index 1
    assert(int_list_insert(list, 1, 15));
    assert(int_list_get(list, 1, &value));
    printf("Inserted Element 1: %d\n", value); // Should print 15

    // Remove at index 0
    assert(int_list_remove_at(list, 0, &value));
    printf("Removed Element 0: %d\n", value); // Should print 10

    // Pop back
    assert(int_list_pop_back(list, &value));
    printf("Popped back: %d\n", value); // Should print 25

    // Clear list
    int_list_clear(list);
    assert(int_list_size(list) == 0);
    assert(int_list_is_empty(list));

    // Destroy list
    int_list_destroy(list);

    printf("All tests passed!\n");
    return 0;
}
