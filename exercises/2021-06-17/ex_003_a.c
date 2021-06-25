#include <stdio.h>
#include "../../mybytelib.h"

/*
	Aliases of byteStruct bits:

	h -> a
	g -> b
	f -> c
*/

void printInputs(byteStruct inputs) {
	printf("A: %d; B: %d; C: %d.\n", inputs.h, inputs.g, inputs.f);
}

bool equation (byteStruct inputs) {
	bool a = inputs.h, b = inputs.g, c = inputs.f;
	
	return (a && b && c) || (!a && b && !c);
}

int main () {
	bool isDifferent = compareTwoEquations(
		8,
		&equation,
		&equation,
		&printInputs
	);
	
	printf("Equal: %s\n", booleans[!isDifferent]);
	return 0;
}

