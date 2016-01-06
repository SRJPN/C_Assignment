#include "ArrayUtil.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
	free(a);
	return newArray;
}

void insertElements(ArrayUtil * list, void * array) {
	char *arrayByBit = array;
	char *baseByBit = list->base;
	for(int i=0; i<(list->length)*(list->typeSize); i++){
			baseByBit[i]=arrayByBit[i];
	} 
}

int isSame(char *a, char *b, int length){
	while(length){
		if(a[length-1]!=b[length-1])
			return 0;
		length--;
	}
	return 1;
}

int findIndex(ArrayUtil util, void* element) {
	for(int i=0; i<util.length; i++){
		if(isSame(element, util.base+(i*util.typeSize), util.typeSize))
			return i;
	} 
	return -1;
}

void dispose(ArrayUtil util) {
	free(util.base);
}

void * findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	void *item;
	for(int i=0; i<util.length; i++){
		item = util.base+(util.typeSize*i);
		if(match(hint, item))
			return item;
	}
	return NULL;
}

int count(ArrayUtil util, MatchFunc* match, void* hint){
	void *item;
	int count=0;
	for(int i=0; i<util.length; i++){
		item = util.base+(util.typeSize*i);
		if(match(hint, item))
			count++;
	}
	return count;
}

void * findLast(ArrayUtil util, MatchFunc* match, void* hint){
	void *element;
	for(int i=util.length-1; i>=0; i--){
		element = util.base+(util.typeSize*i);
		if (match(hint, element)==1)
			return element;
	}
	return NULL;
}

int isEven(void * hint, void * item){
	return *((int *)item)%2==0;
}

int isDivisible(void * hint, void * item){
	return *((int *) item) % *((int *) hint) == 0;
}

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems) {
	void *item;
	int count = 0;
	for (int i = 0; i < util.length && maxItems>0; ++i){
		item = util.base+(util.typeSize*i);
		if(match(hint, item)==1){
			count++;
			*destination = item;
			destination++;
			maxItems--;
		}
	}
	return count;
}
