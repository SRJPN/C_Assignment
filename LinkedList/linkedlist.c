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
	// temp->index = list->length;
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
	Element *previous;
	Element *temp = list->head;
	void *value;
	int count = 0;
	if(index<list->length){
		while(count != index){
			previous = temp;
			temp = temp->next;
			count++;
		};
		previous->next = temp->next;
		value = temp->value;
		free(temp);
		return value;
	};
	return NULL;
}