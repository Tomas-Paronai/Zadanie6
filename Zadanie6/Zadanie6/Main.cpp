#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Cars.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {


	Car *car = (Car*)malloc(sizeof(Car) * getNumberOfCars(argv[1]));
	int n = readCarsFromFile(car, argv[1]);

	printf("FULL LIST:\n");
	printList(car, n);

	printf("\nORDERED:\n");
	orderCarsByDate(car, n);

	printf("\nFROM 2003 - 2010:\n");
	printListBetwenYesrs(car, n, 2003, 2010);

	printf("\nPETROLS:\n");
	printPetrolCars(car, n);

	printf("\nSUMMER:\n");
	printListSummer(car, n);

	printf("\nBLACK CARS:\n");
	printCarsByColor(car, n, BLACK);

	printf("\nAVARAGE VALUE:\n");
	printf("%.2f\n", calculateAverageValue(car, n));

	printf("\nBY PLATE BJ-554CA:\n");
	findCarBySPZ(car, n, "BJ-554CA");

	printf("\n");
	return 0;
}
