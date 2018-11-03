#include "ejercicio4.h"
#include "common.h"

void ejercicio4()
{
	printf("===========\n");
	printf("Ejercicio 4\n");
	printf("===========\n");

	int x = 456;

	printf("modulo 1 de %d: %d\n", x, x % 1);
	printf("modulo 10 de %d: %d\n", x, x % 10);
	printf("modulo 1000 de %d: %d\n", x, x % 1000);


	for (size_t i = 0; i <= 10; i++)
	{
		printf("modulo 2 de %d: %d\n", i, i % 2);
	}
}