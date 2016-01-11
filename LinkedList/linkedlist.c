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

int add_to_list(LinkedList *list, void *data) {
	Element *temp = (Element *)malloc(sizeof(Element));
	temp->value = data;
	if(list->length == 0){
		list->head = list->tail = temp;
		(list->length)++;
	}
	else{
		list->tail = temp;
		(list->length)++;
	}
	return 0;
}
