#include <stdio.h>
#include <assert.h>
#include "ArrayUtil.h"

void test_create_creates_new_Array (){
	ArrayUtil list;
	list = create(23, 5);
	assert(list.length==5);
	assert(list.typeSize==23);
	dispose(list);
}

void test_areEqual_returns_1_for_two_equal_ArrayUtils_with_all_elements_zero (){
	ArrayUtil list = create(4, 5);
	ArrayUtil list1 = create(4, 5);
	assert(areEqual(list, list1)==1);
	dispose(list);
	dispose(list1);
}

void test_areEqual_returns_1_for_two_equal_ArrayUtils_with_elements (){
	ArrayUtil list = create(4, 5);
	int array[] = {1,2,3,4,5};
	insertElements(&list, array);
	ArrayUtil list1 = create(4, 5);
	insertElements(&list1, array);
	assert(areEqual(list, list1)==1);
	dispose(list);
	dispose(list1);
}

void test_areEqual_returns_0_for_two_ArrayUtils_With_different_length (){
	ArrayUtil list = create(4, 5);
	ArrayUtil list1 = create(4, 6);
	assert(areEqual(list, list1)==0);
	dispose(list);
	dispose(list1);
}

void test_areEqual_returns_0_for_two_ArrayUtils_With_different_typeSize (){
	ArrayUtil list = create(4, 5);
	ArrayUtil list1 = create(5, 5);
	assert(areEqual(list, list1)==0);
	dispose(list);
	dispose(list1);
}

void test_resize_returns_ArrayUtil_with_new_size() {
	ArrayUtil list = create(4, 5);
	ArrayUtil list1 = resize(list, 6);
	assert(areEqual(list, list1)==0);
	assert(areEqual(list1,create(4,6))==1);
	dispose(list);
	dispose(list1);
}

void test_findIndex_returns_minus_1_if_the_element_is_not_found() {
	int array[] = {1,2,3,4,5};
	int a = 6;
	ArrayUtil list = create(4, 5);
	insertElements(&list, array);
	assert(findIndex(list, &a)==-1);
	dispose(list);
}

void test_findIndex_returns_index_if_the_element_is_found() {
	int array[] = {1,2,3,4,5};
	int a = 3;
	ArrayUtil list = create(4, 5);
	insertElements(&list, array);
	assert(findIndex(list, &a)==2);
	dispose(list);
}

void test_findIndex_returns_index_if_the_element_is_found_once_more() {
	int array[] = {1,2,3,4,5};
	int a = 5;
	ArrayUtil list = create(4, 5);
	insertElements(&list, array);
	assert(findIndex(list, &a)==4);
	dispose(list);
}

void test_findFirst_returns_pointer_of_the_first_element_matches_criteria () {
	int array[] = {1,2,3,4,5};
	int a = 5;
	int *element;
	ArrayUtil util = create(4, 5);
	insertElements(&util, array);
	element = findFirst(util, &isEven, NULL);
	assert(*element==2);
	dispose(util);
}

void test_findFirst_returns_NULL_if_none_of_the_elements_matches_criteria () {
	int array[] = {1,7,3,9,5};
	int *element;
	ArrayUtil util = create(4, 5);
	insertElements(&util, array);
	element = findFirst(util, &isEven, NULL);
	assert(element==NULL);
	dispose(util);
}

void test_findLast_returns_pointer_of_the_first_element_from_last_that_matches_criteria() {
	int array[] = {1,2,3,4,5};
	int a = 5;
	int *element;
	ArrayUtil util = create(4, 5);
	insertElements(&util, array);
	element = findLast(util, isEven, NULL);
	assert(*element==4);
	dispose(util);
}

void test_findLast_returns_NULL_if_none_of_the_elements_matches_criteria () {
	int array[] = {1,7,3,9,5};
	int *element;
	ArrayUtil util = create(4, 5);
	insertElements(&util, array);
	element = findLast(util, isEven, NULL);
	assert(element==NULL);
	dispose(util);
}

void test_findFirst_returns_pointer_of_the_first_element_matches_criteria_for_isDivisible () {
	int array[] = {1,2,3,4,5};
	int a = 2;
	int *element;
	ArrayUtil util = create(4, 5);
	insertElements(&util, array);
	element = findFirst(util, &isDivisible, &a);
	assert(*element==2);
	dispose(util);
}

void test_findFirst_returns_NULL_if_none_of_the_elements_matches_criteria_for_isDivisible () {
	int array[] = {1,2,3,4,5};
	int a = 7;
	int *element;
	ArrayUtil util = create(4, 5);
	insertElements(&util, array);
	element = findFirst(util, &isDivisible, &a);
	assert(element==NULL);
	dispose(util);
}

void test_findLast_returns_pointer_of_the_first_element_from_last_that_matches_criteria_for_isDivisible() {
	int array[] = {1,2,3,4,5};
	int a = 5;
	int *element;
	ArrayUtil util = create(4, 5);
	insertElements(&util, array);
	element = findLast(util, isDivisible, &a);
	assert(*element==5);
	dispose(util);
}

void test_findLast_returns_NULL_if_none_of_the_elements_matches_criteria_for_isDivisible () {
	int array[] = {1,2,3,4,5};
	int *element;
	int a = 7;
	ArrayUtil util = create(4, 5);
	insertElements(&util, array);
	element = findLast(util, isDivisible, &a);
	assert(element==NULL);
	dispose(util);
}

void test_count_returns_count_of_the_number_of_elements_that_matches_given_criteria() {
	int array[] = {1,2,3,4,5};
	int element;
	ArrayUtil util = create(4, 5);
	insertElements(&util, array);
	element = count(util, isEven, NULL);
	assert(element==2);
	dispose(util);
}

void test_count_returns_count_of_the_number_of_elements_that_matches_given_criteria_for_isDivisible() {
	int array[] = {1,2,3,4,5};
	int element;
	int a = 2;
	ArrayUtil util = create(4, 5);
	insertElements(&util, array);
	element = count(util, isDivisible, &a);
	assert(element==2);
	dispose(util);
}

void test_count_returns_ZERO_if_none_of_the_elements_matches_given_criteria() {
	int array[] = {1,3,5,7,9};
	int element;
	ArrayUtil util = create(4, 5);
	insertElements(&util, array);
	element = count(util, isEven, NULL);
	assert(element==0);
	dispose(util);
}
