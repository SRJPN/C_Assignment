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
	test_ArrayUtil(list, 4, 5);
}

int main(){
	test_create_creates_new_Array();
	return 0;
}