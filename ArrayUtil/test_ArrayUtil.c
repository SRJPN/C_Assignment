#include <stdio.h>
#include <assert.h>
#include "ArrayUtil.h"

void test_ArrayUtil (ArrayUtil a, int typeSize, int length){
	assert(a.length==length);
	assert(a.typeSize==typeSize);
}

void test_create_creates_new_Array (){
	ArrayUtil list;
	list = create(23, 5);
	test_ArrayUtil(list, 23, 5);
}

void test_areEqual_returns_1_for_two_equal_ArrayUtils_with_all_elements_zero (){
	ArrayUtil list = create(4, 5);
	ArrayUtil list1 = create(4, 5);
	assert(areEqual(list, list1)==1);
}

void test_areEqual_returns_1_for_two_equal_ArrayUtils_with_elements (){
	ArrayUtil list = create(4, 5);
	int array[] = {1,2,3,4,5};
	insertElements(&list, array);
	ArrayUtil list1 = create(4, 5);
	insertElements(&list1, array);
	assert(areEqual(list, list1)==1);
}
void test_areEqual_returns_0_for_two_ArrayUtils_With_different_length (){
	ArrayUtil list = create(4, 5);
	ArrayUtil list1 = create(4, 6);
	assert(areEqual(list, list1)==0);
}

void test_areEqual_returns_0_for_two_ArrayUtils_With_different_typeSize (){
	ArrayUtil list = create(4, 5);
	ArrayUtil list1 = create(5, 5);
	assert(areEqual(list, list1)==0);
}

void test_resize_returns_ArrayUtil_with_new_size() {
	ArrayUtil list = create(4, 5);
	ArrayUtil list1 = resize(list, 6);
	assert(areEqual(list, list1)==0);
	assert(areEqual(list1,create(4,6))==1);
}

void test_findIndex_returns_minus_1_if_the_element_is_not_found() {
	int array[] = {1,2,3,4,5};
	int a = 6;
	ArrayUtil list = create(4, 5);
	insertElements(&list, array);
	assert(findIndex(list, &a)==-1);
}
void print_list(ArrayUtil a){
	int *base = a.base;
	for(int i=0; i<a.length; i++){
		printf("element at index %d is %d\n",i,base[i] );
	}
}

void test_findIndex_returns_index_if_the_element_is_found() {
	int array[] = {1,2,3,4,5};
	int a = 3;
	ArrayUtil list = create(4, 5);
	insertElements(&list, array);
	assert(findIndex(list, &a)==3);
}

void test_findIndex_returns_index_if_the_element_is_found_once_more() {
	int array[] = {1,2,3,4,5};
	int a = 5;
	ArrayUtil list = create(4, 5);
	insertElements(&list, array);
	assert(findIndex(list, &a)==5);
}

int main(){
	test_create_creates_new_Array();

	test_areEqual_returns_1_for_two_equal_ArrayUtils_with_all_elements_zero();
	test_areEqual_returns_1_for_two_equal_ArrayUtils_with_elements();
	test_areEqual_returns_0_for_two_ArrayUtils_With_different_length();
	test_areEqual_returns_0_for_two_ArrayUtils_With_different_typeSize();

	test_resize_returns_ArrayUtil_with_new_size();

	test_findIndex_returns_minus_1_if_the_element_is_not_found();
	test_findIndex_returns_index_if_the_element_is_found();
	test_findIndex_returns_index_if_the_element_is_found_once_more();
	return 0;
}
