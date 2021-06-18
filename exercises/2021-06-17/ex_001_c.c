#include <stdio.h>
#include "../../mybytelib.h"

/*
	Aliases of byteStruct bits:

	h -> a
	g -> b
	f -> a
	e -> d
*/

void printInputs(byteStruct inputs) {
	bool a = inputs.h, b = inputs.g, c = inputs.f, d = inputs.e;
	printf("A: %d; B: %d; C: %d; D: %d.\n", a, b, c, d);
}

bool originalEquation (byteStruct inputs) {
	bool a = inputs.h, b = inputs.g, c = inputs.f, d = inputs.e;
	
	return !((!(d && b) && (c || !a)) || c) && !(((d && c) || (d && !b)) && !(a || (!d && b)));
}

/*
	Reducing Equation:

	!((!(DB) * (C + !A)) + C) * !(((D * C) + (D * !B)) * !(A + (!D * B)))
	!(((!D + !B) * (C + !A)) + C) * !((DC + D!B) * !(A + !DB))
	!(!DC + !D!A + !BC + !B!A + C) * !((DC + D!B) * (!A * (D + !B)))
	!(!D!A + !B!A + C(!D + !B + 1)) * !((DC + D!B) * (!AD + !A!B))
	!(!D!A + !B!A + C) * !(DC!A + DC!A!B + D!B!A)
	((D + A) * (B + A) * !C) * ((!D + !C + A) * (!D + !C + A + B) * (!D + B + A))
	((DB + DA + AB + A) * !C) * ((!D + !D!C + !DA + !DB + !C + !CA + !CB + A + AB) * (!D + B + A))
	((DB + A(D + B + 1)) * !C) * ((!D(1 + !C + A + B) + !C(1 + B) + A(!C + 1 + B)) * (!D + B + A))
	((DB + A) * !C) * ((!D + !C + A) * (!D + B + A))
	(DB!C + !CA) * (!D + !DB + !DA + !C!D + !CB + !CA + A!D + AB + A)
	(DB!C + !CA) * (!D(1 + B + A + !C) + !CB + A(!C + D + B + 1))
	(DB!C + !CA) * (!D + !CB + A)
	(DB!C + DB!CA + !CA!D + !CAB + !CA)
	(DB!C(1 + A) + !CA(!D + B + 1))
	(DB!C + !CA)
	!C(DB + A)
*/

bool reducedEquation (byteStruct inputs) {
	bool a = inputs.h, b = inputs.g, c = inputs.f, d = inputs.e;

	return !c && ((d && b) || a);
}

int main () {
	bool isDifferent = compareTwoEquations(
		16,
		&originalEquation,
		&reducedEquation,
		&printInputs
	);
	
	printf("Equal: %s\n", booleans[!isDifferent]);
	return 0;
}

