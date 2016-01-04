#include "ArrayUtil.h"
#include <stdlib.h>

ArrayUtil create(int typeSize, int length){
	ArrayUtil a;
	a.base = (void *) calloc(length, typeSize);
	a.typeSize = typeSize;
	a.length = length;
	return a;
}

int dereference_And_ArrayUtil(void * a, void * b) {
	char *c = a;
	char *d = b;
	return *c==*d;
}

int areEqual(ArrayUtil a, ArrayUtil b){
	int status=1, size=a.length*a.typeSize;
	if(a.length==b.length && a.typeSize==b.typeSize){
		while(size){
			if(!dereference_And_ArrayUtil(a.base,b.base)){
				return 0;
			}
			a.base++;
			b.base++;
			size--;
		}
		return 1;
	}
	else{
		return 0;
	}
}
