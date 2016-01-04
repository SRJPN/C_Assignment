#include "ArrayUtil.h"
#include <stdlib.h>
#include <stdio.h>

ArrayUtil create(int typeSize, int length){
	ArrayUtil a;
	a.base = (void *) calloc(length, typeSize);
	a.typeSize = typeSize;
	a.length = length;
	return a;
}

int dereference_And_ArrayUtil_Check(void * a, void * b) {
	char *c = a;
	char *d = b;
	return *c==*d;
}

int areEqual(ArrayUtil a, ArrayUtil b) {
	int status=1, size=a.length*a.typeSize;
	if(a.length==b.length && a.typeSize==b.typeSize){
		while(size){
			if(!dereference_And_ArrayUtil_Check(a.base, b.base)){
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

ArrayUtil resize(ArrayUtil list, int newLength) {
	ArrayUtil newArray = create(list.typeSize, newLength);
	char *a = list.base;
	char *b = newArray.base;
	for(int i=0; i<list.length; i++){
		b[i] = a[i];
	}
	return newArray;
}
