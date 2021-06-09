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

