/* QD8080
Another pointless and silly attempt at emulating an 8080 processor system
Version 0.0 Alpha 1
Asami Tachibana

File: main.c
"Heart and soul of our program."
28 Sept. 2017

*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "internals.h"

int main (int argc, char**argv)
{
	int done = 0;
	int vblankcycles = 0;
	State8080* state = Init8080();

	ReadFileIntoMemoryAt(state, "cpudiag.asm", 0);

	while (done == 0)
	{
		Emulate8080_Op(state, done);
	}

	printf("Exiting.\n");
	return 0;
}
