#include "ejercicio3.h"
#include "common.h"

void ejercicio3()
{
	printf("===========\n");
	printf("Ejercicio 3\n");
	printf("===========\n");

	//Raiz cuadrada de -1: NAN
	int x = -1;
	printf("%f\n", sqrt(x));

	//Dividir 0 (int) entre int zero: Exception Integer division by zero
	int i = 0;
	int zero = 0;
	//printf("%d\n", i / zero);

	//Dividir 1.0f entre 0.0f: INF
	float f = 1.0f;
	float zerof = 0.0f;
	printf("%f\n", f / zerof);
}