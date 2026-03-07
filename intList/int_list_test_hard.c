#include <stdio.h>
#include <assert.h>
#include "int_list.h"

static void test_resize()
{
    IntList *list = int_list_create(1);
    assert(list);

    // Force multiple resizes
    for (int i = 0; i < 1000; i++) {
        assert(int_list_push_back(list, i));
    }

    assert(int_list_size(list) == 1000);

    int value;
    for (int i = 0; i < 1000; i++) {
        assert(int_list_get(list, i, &value));
        assert(value == i);
    }

    int_list_destroy(list);
}

static void test_insert_shift()
{
    IntList *list = int_list_create(2);

    int_list_push_back(list, 1);
    int_list_push_back(list, 2);
    int_list_push_back(list, 3);
    int_list_push_back(list, 4);

    // Insert in the middle
    assert(int_list_insert(list, 2, 99));

    int expected[] = {1, 2, 99, 3, 4};
    int value;

    for (size_t i = 0; i < 5; i++) {
        assert(int_list_get(list, i, &value));
        assert(value == expected[i]);
    }

    int_list_destroy(list);
}

static void test_remove_shift()
{
    IntList *list = int_list_create(4);

    for (int i = 0; i < 5; i++) {
        int_list_push_back(list, i);
    }

    int removed;
    assert(int_list_remove_at(list, 2, &removed));
    assert(removed == 2);

    int expected[] = {0, 1, 3, 4};
    int value;

    for (size_t i = 0; i < 4; i++) {
        assert(int_list_get(list, i, &value));
        assert(value == expected[i]);
    }

    int_list_destroy(list);
}

static void test_pop_all()
{
    IntList *list = int_list_create(4);

    for (int i = 0; i < 10; i++) {
        int_list_push_back(list, i);
    }

    int value;

    for (int i = 9; i >= 0; i--) {
        assert(int_list_pop_back(list, &value));
        assert(value == i);
    }

    assert(int_list_is_empty(list));

    int_list_destroy(list);
}

static void test_bounds()
{
    IntList *list = int_list_create(4);

    int value;

    // Invalid access
    assert(!int_list_get(list, 0, &value));
    assert(!int_list_set(list, 0, 10));
    assert(!int_list_remove_at(list, 0, &value));

    int_list_push_back(list, 1);

    // Out-of-range
    assert(!int_list_get(list, 2, &value));
    assert(!int_list_insert(list, 3, 5));

    int_list_destroy(list);
}

static void test_clear()
{
    IntList *list = int_list_create(4);

    for (int i = 0; i < 20; i++) {
        int_list_push_back(list, i);
    }

    int_list_clear(list);

    assert(int_list_size(list) == 0);
    assert(int_list_is_empty(list));

    // Ensure list still usable
    assert(int_list_push_back(list, 42));

    int value;
    assert(int_list_get(list, 0, &value));
    assert(value == 42);

    int_list_destroy(list);
}

int main()
{
    test_resize();
    test_insert_shift();
    test_remove_shift();
    test_pop_all();
    test_bounds();
    test_clear();

    printf("All advanced tests passed.\n");
    return 0;
}
