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

void printList(LinkedList list){

	for (int i = 0; i < list.length; ++i){
		/* code */
	}
}

void test_deleteElementAt_deletes_the_element_at_the_given_index_and_returns_the_address_of_the_value_in_the_deleted_element () {
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6};

	for (int i = 0; i < 6; ++i){
		addToList(&list, &array[i]);
	}

	void *value = deleteElementAt(&list, 3);

	assert(*(int *)value == 4);
}

void test_deleteElementAt_deletes_the_first_element_and_rewrites_head_if_first_element_is_choosen_to_delete () {
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6};

	for (int i = 0; i < 6; ++i){
		addToList(&list, &array[i]);
	}

	void *value = deleteElementAt(&list, 0);

	assert(*(int *)value == 1);

	assert(*(int *)(list.head->value) == 2);
}

void test_deleteElementAt_deletes_the_last_element_and_rewrites_tail_if_last_element_is_choosen_to_delete () {
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6};

	for (int i = 0; i < 6; ++i){
		addToList(&list, &array[i]);
	}

	void *value = deleteElementAt(&list, 5);

	assert(*(int *)value == 6);

	assert(*(int *)(list.tail->value) == 5);
}

void test_asArray_copies_address_of_all_the_values_to_the_destination_given () {
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6};

	for (int i = 0; i < 6; ++i){
		addToList(&list, &array[i]);
	}

	void *dest = (int *)calloc(6,8);

	int countOfCopied = asArray(list, dest, 6);
	for (int i = 0; i < 6; ++i){
		assert(**(int **)dest == array[i]);
		dest+=8;
	}
}

void test_asArray_copies_address_of_all_the_values_to_the_destination_given_and_returns_the_count_of_copied_values () {
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6};

	for (int i = 0; i < 6; ++i){
		addToList(&list, &array[i]);
	}

	void *dest = (int *)calloc(6,8);

	int countOfCopied = asArray(list, dest, 6);
	assert(countOfCopied == 6);
}

void test_asArray_copies_address_of_the_values_in_the_list_to_the_given_destination_until_the_given_limit () {
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6};

	for (int i = 0; i < 6; ++i){
		addToList(&list, &array[i]);
	}

	void *dest = (int *)calloc(2,8);

	int countOfCopied = asArray(list, dest, 2);
	assert(countOfCopied == 2);
	for (int i = 0; i < 2; ++i){
		assert(**(int **)dest == array[i]);
		dest+=8;
	}
}

int isEven (void* hint, void* item) {
	return (*(int *)item)%2 == 0;
}

int isOdd (void* hint, void* item) {
	return !isEven(hint, item);
}

void test_filter_filters_all_the_values_in_the_list_that_satisfies_given_criteria_and_returns_new_list () {
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6};
	int result_array[] = {2,4,6};

	for (int i = 0; i < 6; ++i){
		addToList(&list, &array[i]);
	}

	LinkedList result = filter(list, isEven);

	void *dest = (int *)calloc(3,8);

	int countOfCopied = asArray(result, dest, 3);
	assert(countOfCopied == 3);
	for (int i = 0; i < result.length; ++i){
		assert(**(int **)dest == result_array[i]);
		dest+=8;
	}
}

void test_filter_filters_all_the_values_in_the_list_that_satisfies_given_criteria_and_returns_new_list_using_isOdd () {
	LinkedList list = createList();
	int array[] = {1,2,3,4,5,6};
	int result_array[] = {1,3,5};

	for (int i = 0; i < 6; ++i){
		addToList(&list, &array[i]);
	}

	LinkedList result = filter(list, isOdd);

	void *dest = (int *)calloc(3,8);

	int countOfCopied = asArray(result, dest, 3);
	assert(countOfCopied == 3);
	for (int i = 0; i < result.length; ++i){
		assert(**(int **)dest == result_array[i]);
		dest+=8;
	}
}
