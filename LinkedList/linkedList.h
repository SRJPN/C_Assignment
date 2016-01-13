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

typedef int (MatchFunc)(void* hint, void* item);

typedef void (ConvertFunc)(void* hint, void* sourceItem, void* destinationItem);

LinkedList createList(void);

int addToList(LinkedList *,void *);

void *getFirstElement(LinkedList list);

void *getLastElement(LinkedList list);

void forEach(LinkedList, ElementProcessor e);

void * getElementAt(LinkedList, int );

int indexOf(LinkedList, void *);

void * deleteElementAt(LinkedList *, int);

int asArray(LinkedList, void **, int maxElements);

LinkedList  filter(LinkedList, MatchFunc, void *);

LinkedList reverse(LinkedList);

LinkedList map(LinkedList, ConvertFunc, void * );