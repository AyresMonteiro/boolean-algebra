#include <stdio.h>
#include "../../mybytelib.h"

/*
	Aliases of byteStruct bits:

	h -> x
	g -> y
	f -> z
*/

void printInputs(byteStruct inputs) {
	printf("X: %d; Y: %d; Z: %d.\n", inputs.h, inputs.g, inputs.f);
}

bool originalEquation (byteStruct inputs) {
	bool x = inputs.h, y = inputs.g, z = inputs.f;

	return (!(z && y) && x) || (!((!z && x) || y) && (y || !x));
}

/*
	Reducing Equation:

	(!(Z * Y) * X) + (!((!Z * X) + Y) * (Y + !X))
	((!Z + !Y) * X) + (!((!Z * X) + Y) * (Y + !X))
	!ZX + !YX + (((Z + !X) * !Y) * (Y + !X))
	!ZX + !YX + ((Z!Y + !X!Y) * (Y + !X))
	!ZX + !YX + Z!Y!X + !X!Y
	!ZX + !Y(X + Z!X + !X)
	!ZX + !Y(X + !X + Z!X)
	!ZX + !Y(1 + Z!X)
	!ZX + !Y(1)
	!ZX + !Y
*/

bool reducedEquation (byteStruct inputs) {
	bool x = inputs.h, y = inputs.g, z = inputs.f;

	return (!z && x) || !y;
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

