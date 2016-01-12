#include <assert.h>
#include <stdlib.h>
#include "linkedList.h"
#include <stdio.h>

void test_createList_creates_a_new_linkedList_initalised_with_all_values_NULL () {
	LinkedList list = createList();
	assert(list.head == NULL);
	assert(list.tail == NULL);
	assert(list.length == 0);
}

void test_addToList_adds_the_given_data_to_the_list () {
	LinkedList list = createList();
	int a = 5;
	addToList(&list, &a);
	assert(list.head != NULL);
	assert(list.tail != NULL);
}

void test_addToList_adds_the_given_data_to_the_list_also_increments_the_length () {
	LinkedList list = createList();
	int a = 5;
	addToList(&list, &a);
	assert(list.length == 1);
	addToList(&list, &a);
	assert(list.length == 2);
}

void test_getFirstElement_gives_the_address_of_first_element_in_the_list () {
	LinkedList list = createList();
	int a = 5;
	addToList(&list, &a);
	Element *element = getFirstElement(list);
	assert(*(int *)(element->value) == 5);
}

void test_getLastElement_gives_the_address_of_last_element_in_the_list () {
	LinkedList list = createList();
	int a = 5;
	int b = 10;
	addToList(&list, &a);
	addToList(&list, &b);
	Element *element = getLastElement(list);
	assert(*(int *)(element->value) == 10);
}

void add2 (void *value) {
	*(int *)value += 2;
}

void test_forEach_goes_through_the_list_and_performs_the_given_action_on_each_element () {
	LinkedList list = createList();
	int a = 5;
	int b = 10;
	addToList(&list, &a);
	addToList(&list, &b);

	forEach(list, add2);

	Element *element = getFirstElement(list);
	assert(*(int *)(element->value) == 7);

	element = getLastElement(list);
	assert(*(int *)(element->value) == 12);

}

void test_getElementAt_gives_the_address_of_the_element_at_given_index () {
	LinkedList list = createList();
	int a = 5;
	int b = 10;
	void *element;
	addToList(&list, &a);
	addToList(&list, &b);

	element = getElementAt(list, 1);

	assert(*(int *)element == 10);
}

void test_getElementAt_gives_the_NULL_for_a_given_invalid_index () {
	LinkedList list = createList();
	int a = 5;
	int b = 10;
	void *element;
	addToList(&list, &a);
	addToList(&list, &b);

	element = getElementAt(list, 9);

	assert(element == NULL);
}

void test_indexOf_returns_the_index_of_given_address_of_the_value () {
	LinkedList list = createList();
	int a = 5;
	int b = 10;
	void *element;
	addToList(&list, &a);
	addToList(&list, &b);

	int index = indexOf(list, &b);

	assert(index == 1);
}

void test_indexOf_returns_the_minus_one_of_given_address_of_the_value_if_the_value_is_not_found () {
	LinkedList list = createList();
	int a = 5;
	int b = 10;
	int c = 15;
	void *element;
	addToList(&list, &a);
	addToList(&list, &b);

	int index = indexOf(list, &c);

	assert(index == -1);
}