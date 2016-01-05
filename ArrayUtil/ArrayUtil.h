typedef struct arrayUtil{
	void * base;
	int typeSize;
	int length;
} ArrayUtil;

typedef int(MatchFunc)(void * hint, void * item);

ArrayUtil create(int typeSize, int length);

int areEqual(ArrayUtil, ArrayUtil);

ArrayUtil resize(ArrayUtil, int);

void insertElements(ArrayUtil * list, void * array);

int findIndex(ArrayUtil util, void* element);

void dispose(ArrayUtil util);

void * findFirst(ArrayUtil util, MatchFunc* match, void* hint);

int isEven(void * hint, void * item);

void * findLast(ArrayUtil util, MatchFunc* match, void* hint);

int isDivisible(void * hint, void * item);

int count(ArrayUtil util, MatchFunc* match, void* hint);