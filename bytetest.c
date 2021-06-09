#include <stdio.h>
#include "mybytelib.h"

int main () {
	easyReadAndAssignByte test = {assignableByte: 126};
	printByte(test.readableByte);
	putchar('\n');
	return 0;
}

