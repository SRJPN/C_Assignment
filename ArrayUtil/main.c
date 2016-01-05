#include "test_ArrayUtil.h"

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