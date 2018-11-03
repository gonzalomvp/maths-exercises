#include "ejercicio2.h"
#include "common.h"

void ejercicio2()
{
	printf("===========\n");
	printf("Ejercicio 2\n");
	printf("===========\n");

	//Obten un numero entero con valor 1010 base2
	std::string str = "1010";
	int x = intFromBinary(str);

	//2.1 Aplicale el operador NOT e indica los numeros base2 y base10 antes y después
	printf("Antes del NOT\nBase2: ");
	printIntAsBinary(x);
	printf("Base10: %d\n", x);

	int xNOT = ~x;
	printf("Despues del NOT\nBase2: ");
	printIntAsBinary(xNOT);
	printf("Base10: %d\n", xNOT);

	//2.2 Aplicale el operador << con varios parametros
	printf("Desplazamientos\n");
	printf("<<1:");
	printIntAsBinary(x<<1);
	printf("<<2:");
	printIntAsBinary(x<<2);
	printf("<<5:");
	printIntAsBinary(x<<5);
	printf("<<6:");
	printIntAsBinary(x<<6);

	//2.3 Obtener un entero con signo y sin signo a partir del número de 32 bits con todos los bits a 1
	int number = intFromBinary("11111111111111111111111111111111");
	unsigned int unsignedNumber = intFromBinary("11111111111111111111111111111111");

	printf("signed=%d\n", number);
	printf("unsigned=%d\n", unsignedNumber);

	//2.3.1 Desplazamientos a izq y derecha
	printf("<<\n");

	//Ambos completan con 0s al desplazar a la izquierda
	printIntAsBinary(number << 1);
	printIntAsBinary(unsignedNumber << 1);

	printf(">>\n");
	//El signed completa con 1s al desplazar a la derecha
	printIntAsBinary(number >> 1);
	
	//El unsigned completa con 0s al desplazar a la derecha
	printIntAsBinary(unsignedNumber >> 1);

	//2.3.2 Sumar una unidad al número anterior con signo
	printf("Sumar 1 al numero anterior con signo\n");
	printIntAsBinary(number + 1);

	//Restar una unidad al número 0 sin signo
	printf("Restar una unidad al numero 0 sin signo\n");
	unsignedNumber = intFromBinary("00000000000000000000000000000000");
	printIntAsBinary(unsignedNumber - 1);

	//2.3.3 Obtener los canales RGB de numero 0xCC6699

	int pink = 0xCC6699;

	int R_MASK = 0xFF0000;
	int G_MASK = 0x00FF00;
	int B_MASK = 0x0000FF;

	int RChannel = (pink & R_MASK) >> 16;
	int GChannel = (pink & G_MASK) >> 8;
	int BChannel = (pink & B_MASK);

	printf("Canal Rojo=%d\n", RChannel);
	printf("Canal Verde=%d\n", GChannel);
	printf("Canal Azul=%d\n", BChannel);
}

