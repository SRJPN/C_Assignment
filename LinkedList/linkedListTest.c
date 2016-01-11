#include <assert.h>
#include <stdlib.h>
#include "linkedList.h"

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