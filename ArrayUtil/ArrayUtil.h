typedef struct arrayUtil{
	void * base;
	int typeSize;
	int length;
} ArrayUtil;

ArrayUtil create(int typeSize, int length);

int areEqual(ArrayUtil, ArrayUtil);

ArrayUtil resize(ArrayUtil, int);