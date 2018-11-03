#include "ejercicio5.h"
#include "common.h"

void ejercicio5()
{
	printf("===========\n");
	printf("Ejercicio 5\n");
	printf("===========\n");

	int a = 4;
	int b = -4;
	printIntAsBinary(a);
	printIntAsBinary(b);

	//5.1 Sumar a + b
	printIntAsBinary(a + b);

	//5.2 Da 0 lo cual es correcto y es gracias a que se usa el complemento a 2 para representar los negativos.
	//Lo que se hace es sumar ambos numeros en binario y descartar el bit que se arrastra.

	//5.3 binaryFromChar

	//5.4
	char c = (char)255;
	unsigned char uc = (unsigned char)255;

	printf("signed char:%hhd\n",c);
	printCharAsBinary(c);

	printf("unsigned char:%hhu\n", c);
	printCharAsBinary(c);

	//5.5 Tienen la misma representación en base 2 pero el signed es -1 en base 10 y el unsigned es 255.
	//El ordenador los diferencia por el tipo de la variable.

	//5.6
	char d = (char)128; //only to 127
	char e = (char)-128;

	printf("signed char:%d\n", d);
	printCharAsBinary(d);
	printf("signed char:%d\n", e);
	printCharAsBinary(e);

	//5.7 Son el mismo numero. En un signed char el valor positivo mayor que se puede representar es 127
	//porque el bit de la izquierda se usa para el signo. Al intentar meter 128 en un signed char
	//realmente estamos almacenando -128
}