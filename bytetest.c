#include <stdio.h>
#include "mybytelib.h"

// h -> a
// g -> b
// f -> c

void printInputs(byteStruct inputs) {
	printf("A: %d; B: %d; C: %d.\n", inputs.h, inputs.g, inputs.f);
}

bool originalEquation (byteStruct inputs) {
	return !(((!(inputs.h && inputs.g) || (inputs.f && inputs.g)) || !((inputs.f) && !inputs.g)) && (inputs.g));
}

bool reducedEquation (byteStruct inputs) {
	return !(((!(inputs.h && inputs.g) || (inputs.f && inputs.g)) || !((inputs.f) && !inputs.g)));
}

int main () {
	const char * booleans[] = {
		"false\0",
		"true\0"
	};
	bool isDifferent = compareTwoEquations(8, &originalEquation, &reducedEquation, &printInputs);	
	printf("Equal: %s\n", booleans[!isDifferent]);
	return 0;
}

