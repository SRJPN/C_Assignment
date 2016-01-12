typedef struct {
	void *value;
	void *next;	
	// int index;
} Element;

typedef struct {
	Element *head;
	Element *tail;
	int length;
} LinkedList;

typedef void (*ElementProcessor)(void *);

LinkedList createList(void);

int addToList(LinkedList *,void *);

void *getFirstElement(LinkedList list);

void *getLastElement(LinkedList list);

void forEach(LinkedList, ElementProcessor e);

void * getElementAt(LinkedList, int );

int indexOf(LinkedList, void *);
