typedef struct arrayUtil{
	void * base;
	int typeSize;
	int length;
} ArrayUtil;

typedef int(MatchFunc)(void * hint, void * item);

typedef void (ConvertFunc)(void* hint, void* sourceItem, void* destinationItem);

typedef void (OperationFunc)(void* hint, void* item);

typedef void* (ReducerFunc)(void* hint, void* previousItem, void* item);

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

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems);

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);

void addOne(void *hint, void *source, void *dest) ;

void addWith(void *hint, void *source, void *dest) ;

void forEach(ArrayUtil util, OperationFunc* operation, void* hint);

void addOneForEach(void* hint, void* item) ;

void addWithForEach(void* hint, void* item) ;

void * reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue);

void * totalReducer(void* hint, void* previousItem, void* item) ;

void * sumOfMultiples(void* hint, void* previousItem, void* item) ;


