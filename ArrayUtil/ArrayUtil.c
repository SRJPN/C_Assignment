#include "ArrayUtil.h"
#include <stdlib.h>

ArrayUtil create(int typeSize, int length){
	ArrayUtil a;
	a.base = (void *) malloc(typeSize);
	a.typeSize = typeSize;
	a.length = length;
	return a;
}