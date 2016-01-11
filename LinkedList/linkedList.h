typedef struct {
	void *value;
	void *next;	
} Element;

typedef struct {
	Element *head;
	Element *tail;
	int length;
} LinkedList;


LinkedList createList(void);

int addToList(LinkedList *,void *);

void *getFirstElement(LinkedList list);

void *getLastElement(LinkedList list);
