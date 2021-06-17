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

bool originalEquation (byteStruct inputs) {
	bool a = inputs.h, b = inputs.g, c = inputs.f;
	
	return !(((!(a && b) || (c && b)) || !((c) && !b)) && (b));
}

/*
	Reducing equation:

	!(B * (!(!B * C) + ((C * A) + !(A * B))))
	!(B * (B + !C + CA + !A + !B))
	!(B * (!C + CA + !A + 1))
	!(B!C + BCA + B!A + B)
	(!B + C) * (!B + !C + !A) * (!B + A) * !B
	(!B + C) * (!B + !C + !A) * (!B + !BA)
	(!B + !BA + C!B + C!BA) * (!B + !C + !A)
	(!B + !B!C + !B!A + !BA + !BA!C + C!B + C!B!A + C!BA)
	!B(1 + !C + C + !A + A + C!A + A!C + CA)
	!B(1 + 1 + 1 + C!A + !(C!A) + CA)
	!B(1 + 1 + 1 + 1 + CA)
	!B(1 + CA)
	!B(1)
	!B
*/

bool reducedEquation (byteStruct inputs) {
	bool b = inputs.g;

	return !b;
}

int main () {
	bool isDifferent = compareTwoEquations(
		8,
		&originalEquation,
		&reducedEquation,
		&printInputs
	);
	
	printf("Equal: %s\n", booleans[!isDifferent]);
	return 0;
}

