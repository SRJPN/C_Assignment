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