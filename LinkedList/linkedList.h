typedef struct {
	void *value;
	void *next;	
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
