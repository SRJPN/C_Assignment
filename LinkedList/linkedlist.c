#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList createList (void) {
	LinkedList a;
	a.head = NULL;
	a.tail = NULL;
	a.length = 0;
	return a;
}

int addToList(LinkedList *list, void *data) {
	Element *temp = (Element *)malloc(sizeof(Element));
	temp->value = data;
	temp->next = NULL;
	if(list->length == 0)
		list->head = list->tail = temp;
	else{
		list->tail->next = temp;
		list->tail = temp;
	}
	(list->length)++;
	return 0;
}

void *getFirstElement(LinkedList list) {
	return list.head;
}

void *getLastElement(LinkedList list) {
	return list.tail;
}

void forEach(LinkedList list, ElementProcessor e) {
	Element *element = list.head;
	while(element!=NULL){
		e(element->value);
		element = element->next;
	};
}

void * getElementAt(LinkedList list, int index) {
	int count = 0;
	Element *temp = list.head;
	if(index<list.length){
		while(count != index){
			temp = temp->next;
			count++;
		};
		return temp->value;
	};
	return NULL;
}

int indexOf(LinkedList list, void * value) {
	Element *temp = list.head;
	for (int i = 0; i < list.length; ++i){
		if(temp->value == value)
			return i;
		temp = temp->next;
	}
	return -1;
}


void * deleteElementAt(LinkedList *list, int index) {
	list->length--;
	Element *previous;
	Element *temp = list->head;
	void *value;
	int count = 0;
	if(index == 0){
		list->head = temp->next;
		free(temp);
		return temp->value;
	}
	while(count != index){
		previous = temp;
		temp = temp->next;
		count++;
	};
	previous->next = temp->next;
	value = temp->value;
	if(index == list->length)
		list->tail = previous;
	free(temp);
	return value;
}

int asArray(LinkedList list, void **dest, int maxElements) {
	int count = 0;
	Element *element = list.head;
	while(count<maxElements && element != NULL){
		*dest = element->value;
		element = element->next;
		count++;
		dest++;
	}
	return count;
}

LinkedList filter(LinkedList list, MatchFunc match, void *hint) {
	LinkedList result = createList();
	Element *element = list.head;
	while(element != NULL){
		if(match(hint,element->value))
			addToList(&result, element->value);
		element = element->next;
	}
	return result;
}

LinkedList reverse(LinkedList list) {
	LinkedList reversed_list = createList();
	void *as_array = (int *)calloc(list.length, 8);
	asArray(list, as_array, list.length);
	as_array += 8*(list.length-1);
	for (int i = 0; i < list.length; ++i){
		addToList(&reversed_list, *(void **)as_array);
		as_array -= 8;
	}
	return reversed_list;
}

LinkedList map(LinkedList list, ConvertFunc convert, void *hint) {
	LinkedList result = createList();
	Element *element = list.head;
	void **tempDest = malloc(8);
	while(element != NULL){
		convert(hint, element->value, tempDest);
		addToList(&result, *tempDest);
		element = element->next;
	}
	free(tempDest);
	return result;
}

void *reduce(LinkedList list, Reducer reducer, void *hint, void *initialValue) {
	Element *element = list.head;
	while(element != NULL){		
		initialValue = reducer(hint, initialValue, element->value);
	}
	return initialValue;
}

