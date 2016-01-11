#include <assert.h>
#include <stdlib.h>
#include "linkedList.h"

void test_createList_creates_a_new_linkedList_initalised_with_all_values_NULL () {
	LinkedList list = createList();
	assert(list.head == NULL);
	assert(list.tail == NULL);
	assert(list.length == 0);
}