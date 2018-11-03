#include "ejercicio6.h"
#include "common.h"

void ejercicio6()
{
	printf("===========\n");
	printf("Ejercicio 6\n");
	printf("===========\n");

	//6.1
	float point2 = 0.2f;
	printf("%1.16f\n", point2);

	//6.2 Tiene un error de representacion

	//6.3
	float f = 0.1f;

	//6.4
	float sum = 0;
	for (int i = 0; i < 100; i++)
	{
		sum += f;
	}

	float product = f * 100;

	//6.5 No son iguales. En el caso del bucle cada vez que se suma 0.1 se añade el error de representar 0.1 al resultado
	printf("%1.15f\n", sum);
	printf("%1.15f\n", product);

	//6.6 Se podrían comparar considerando que son iguales si su diferencia es menor que una tolerancia definida.
	float tolerance = 0.00001;

	if (fabs(sum - product) < tolerance)
	{
		printf("Iguales\n");
	}
	else
	{
		printf("Distintos\n");
	}

}