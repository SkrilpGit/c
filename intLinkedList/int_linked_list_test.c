#include <stdio.h>
#include <assert.h>
#include "int_linked_list.h"

static void test_empty_list()
{
    IntLinkedList *list = int_linked_list_create();
    assert(list);

    assert(int_linked_list_is_empty(list));
    assert(int_linked_list_size(list) == 0);

    int value;

    assert(!int_linked_list_get(list, 0, &value));
    assert(!int_linked_list_pop_front(list, &value));
    assert(!int_linked_list_pop_back(list, &value));
    assert(!int_linked_list_remove_at(list, 0, &value));

    int_linked_list_destroy(list);
}

static void test_push_front()
{
    IntLinkedList *list = int_linked_list_create();

    for (int i = 0; i < 5; i++)
        assert(int_linked_list_push_front(list, i));

    assert(int_linked_list_size(list) == 5);

    int expected[] = {4,3,2,1,0};
    int value;

    for (size_t i = 0; i < 5; i++) {
        assert(int_linked_list_get(list, i, &value));
        assert(value == expected[i]);
    }

    int_linked_list_destroy(list);
}

static void test_push_back()
{
    IntLinkedList *list = int_linked_list_create();

    for (int i = 0; i < 5; i++)
        assert(int_linked_list_push_back(list, i));

    assert(int_linked_list_size(list) == 5);

    int value;
    for (size_t i = 0; i < 5; i++) {
        assert(int_linked_list_get(list, i, &value));
        assert(value == (int)i);
    }

    int_linked_list_destroy(list);
}

static void test_pop_front()
{
    IntLinkedList *list = int_linked_list_create();

    for (int i = 0; i < 5; i++)
        int_linked_list_push_back(list, i);

    int value;

    for (int i = 0; i < 5; i++) {
        assert(int_linked_list_pop_front(list, &value));
        assert(value == i);
    }

    assert(int_linked_list_is_empty(list));

    int_linked_list_destroy(list);
}

static void test_pop_back()
{
    IntLinkedList *list = int_linked_list_create();

    for (int i = 0; i < 5; i++)
        int_linked_list_push_back(list, i);

    int value;

    for (int i = 4; i >= 0; i--) {
        assert(int_linked_list_pop_back(list, &value));
        assert(value == i);
    }

    assert(int_linked_list_is_empty(list));

    int_linked_list_destroy(list);
}

static void test_insert_middle()
{
    IntLinkedList *list = int_linked_list_create();

    int_linked_list_push_back(list, 1);
    int_linked_list_push_back(list, 2);
    int_linked_list_push_back(list, 4);
    int_linked_list_push_back(list, 5);

    assert(int_linked_list_insert(list, 2, 3));

    int expected[] = {1,2,3,4,5};
    int value;

    for (size_t i = 0; i < 5; i++) {
        assert(int_linked_list_get(list, i, &value));
        assert(value == expected[i]);
    }

    int_linked_list_destroy(list);
}

static void test_insert_edges()
{
    IntLinkedList *list = int_linked_list_create();

    assert(int_linked_list_insert(list, 0, 2));
    assert(int_linked_list_insert(list, 0, 1));
    assert(int_linked_list_insert(list, 2, 3));

    int expected[] = {1,2,3};
    int value;

    for (size_t i = 0; i < 3; i++) {
        assert(int_linked_list_get(list, i, &value));
        assert(value == expected[i]);
    }

    int_linked_list_destroy(list);
}

static void test_remove_middle()
{
    IntLinkedList *list = int_linked_list_create();

    for (int i = 0; i < 5; i++)
        int_linked_list_push_back(list, i);

    int removed;

    assert(int_linked_list_remove_at(list, 2, &removed));
    assert(removed == 2);

    int expected[] = {0,1,3,4};
    int value;

    for (size_t i = 0; i < 4; i++) {
        assert(int_linked_list_get(list, i, &value));
        assert(value == expected[i]);
    }

    int_linked_list_destroy(list);
}

static void test_remove_edges()
{
    IntLinkedList *list = int_linked_list_create();

    for (int i = 0; i < 3; i++)
        int_linked_list_push_back(list, i);

    int removed;

    assert(int_linked_list_remove_at(list, 0, &removed));
    assert(removed == 0);

    assert(int_linked_list_remove_at(list, 1, &removed));
    assert(removed == 2);

    int value;
    assert(int_linked_list_get(list, 0, &value));
    assert(value == 1);

    int_linked_list_destroy(list);
}

static void test_clear_and_reuse()
{
    IntLinkedList *list = int_linked_list_create();

    for (int i = 0; i < 10; i++)
        int_linked_list_push_back(list, i);

    int_linked_list_clear(list);

    assert(int_linked_list_is_empty(list));
    assert(int_linked_list_size(list) == 0);

    assert(int_linked_list_push_back(list, 42));

    int value;
    assert(int_linked_list_get(list, 0, &value));
    assert(value == 42);

    int_linked_list_destroy(list);
}

static void test_large_sequence()
{
    IntLinkedList *list = int_linked_list_create();

    for (int i = 0; i < 1000; i++)
        assert(int_linked_list_push_back(list, i));

    assert(int_linked_list_size(list) == 1000);

    int value;

    for (int i = 0; i < 500; i++)
        assert(int_linked_list_pop_front(list, &value));

    assert(int_linked_list_size(list) == 500);

    for (int i = 0; i < 500; i++)
        assert(int_linked_list_pop_back(list, &value));

    assert(int_linked_list_is_empty(list));

    int_linked_list_destroy(list);
}

int main(void)
{
    test_empty_list();
    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
    test_insert_middle();
    test_insert_edges();
    test_remove_middle();
    test_remove_edges();
    test_clear_and_reuse();
    test_large_sequence();

    printf("All linked list tests passed.\n");
    return 0;
}
