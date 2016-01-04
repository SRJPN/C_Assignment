#include <stdio.h>
#include <assert.h>
#include "ArrayUtil.h"

void test_ArrayUtil (ArrayUtil a, int typeSize, int length){
	assert(a.length==length);
	assert(a.typeSize==typeSize);
}

void test_create_creates_new_Array (){
	ArrayUtil list;
	list = create(4, 5);
	test_ArrayUtil(list, 4, 5	);
}

void test_areEqual_returns_1_for_two_equal_ArrayUtils (){
	ArrayUtil list = create(4, 5);
	ArrayUtil list1 = create(4, 5);
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

int main(){
	test_create_creates_new_Array();
	test_areEqual_returns_1_for_two_equal_ArrayUtils();
	test_areEqual_returns_0_for_two_ArrayUtils_With_different_length();
	test_areEqual_returns_0_for_two_ArrayUtils_With_different_typeSize();
	return 0;
}