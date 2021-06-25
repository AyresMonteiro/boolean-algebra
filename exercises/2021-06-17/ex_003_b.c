#include <stdio.h>
#include "../../mybytelib.h"

/*
	Aliases of byteStruct bits:

	h -> a
	g -> b
	f -> c
	e -> d
*/

void printInputs(byteStruct inputs) {
	printf(
		"A: %d; B: %d; C: %d; D: %d.\n",
		inputs.h, inputs.g, inputs.f, inputs.e
	);
}

bool equation (byteStruct inputs) {
	bool a = inputs.h, b = inputs.g, c = inputs.f, d = inputs.e;
	
	return (!c || b) && !(!a || d);
}

int main () {
	bool isDifferent = compareTwoEquations(
		16,
		&equation,
		&equation,
		&printInputs
	);
	
	printf("Equal: %s\n", booleans[!isDifferent]);
	return 0;
}

