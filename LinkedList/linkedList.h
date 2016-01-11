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

int add_to_list(LinkedList *,void *);
