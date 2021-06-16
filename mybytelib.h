#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct byteStruct {
	unsigned h: 1;
	unsigned g: 1;
	unsigned f: 1;
	unsigned e: 1;
	unsigned d: 1;
	unsigned c: 1;
	unsigned b: 1;
	unsigned a: 1;
} byteStruct;

typedef union easyReadAndAssignByte {
	byteStruct readableByte;
	unsigned assignableByte: 8;
} easyReadAndAssignByte;

void printByte(byteStruct byteVar); 

bool compareTwoEquations(
	int exclusiveMaxNum,
	bool (*e1) (byteStruct),
	bool (*e2) (byteStruct),
	void (*printInputs) (byteStruct)
);

