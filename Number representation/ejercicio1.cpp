#include "ejercicio1.h"
#include "common.h"

void ejercicio1()
{
	printf("===========\n");
	printf("Ejercicio 1\n");
	printf("===========\n");

	//que numero entero en base 10 corresponde al numero en base 2 1010? Es el 10
	std::string str = "1010";
	int x = intFromBinary(str);
	printIntAsBinary(x);
	printf("%s en base2 es en base10: %d\n", str.c_str(), x);

}

