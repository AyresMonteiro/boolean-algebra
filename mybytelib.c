#include <stdio.h>
#include <stdlib.h>
#include "mybytelib.h"

void printByte(byteStruct byteVar) {
	printf("%d%d%d%d%d%d%d%d",
		byteVar.a,
		byteVar.b,
		byteVar.c,
		byteVar.d,
		byteVar.e,
		byteVar.f,
		byteVar.g,
		byteVar.h
	);
}

bool compareTwoEquations(
	int exclusiveMaxNum,
	bool (*e1) (byteStruct),
	bool (*e2) (byteStruct),
	void (*printInputs) (byteStruct)
) {
	easyReadAndAssignByte byte;
	bool isDifferent = false, f1Result, f2Result;

	for(byte.assignableByte = 0; byte.assignableByte < exclusiveMaxNum; byte.assignableByte++) {
		f1Result = (*e1)(byte.readableByte);
		f2Result = (*e2)(byte.readableByte);

		if(!isDifferent) isDifferent = f1Result != f2Result;
		
		(*printInputs)(byte.readableByte);
		printf("F1: %d\n", f1Result);
		printf("F2: %d\n\n", f2Result);
	}

	return isDifferent;
}

