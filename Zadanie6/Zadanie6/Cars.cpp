#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "Cars.h"

int getNumberOfCars(char* path) {
	FILE *inputFile = fopen(path, "r");
	int lines = 1;
	if (inputFile != NULL) {
		char c;
		while ((c = fgetc(inputFile)) != EOF) {
			if (c == '\n') {
				lines++;
			}
		}
	}

	return lines;
}

int readCarsFromFile(Car *car, char *path) {
	FILE *inputFile = fopen(path, "r");
	if (inputFile != NULL) {
		int amount = 0;
		char in;
		int step = 1, carIndex = 0;
		//printf("WORD MALLOC\n");
		char word[30];

		//printf("START INPUT\n");
		Car carTemp;
		while (fscanf(inputFile, "%s", &word) != EOF) {
			//printf("WORD %s LENGHT: %d\n",word, strlen(word));
			switch (step) {
			case 1:
				//printf("\nINSERTING BRAND %s\n",word);
				amount++;
				carTemp.brand = (char*)malloc(sizeof(char)*(strlen(word) + 1));
				strcpy(carTemp.brand, word);
				break;
			case 2:
				//printf("INSERTING TYPE %s\n",word);
				carTemp.type = (char*)malloc(sizeof(char)*(strlen(word) + 1));
				strcpy(carTemp.type, word);
				break;
			case 3:
				//printf("INSERTING COLOR %s\n",word);
				carTemp.color = parseColor(word);
				break;
			case 4:
				//printf("INSERTING YEAR %s\n",word);
				carTemp.year = parseYear(word);
				break;
			case 5:
				//printf("INSERTING FUEL %c\n",word[0]);
				carTemp.fuel = word[0];
				break;
			case 6:
				//printf("INSERTING DATE %s\n",word);
				carTemp.evidDate = parseDate(word);
				break;
			case 7:
				//printf("INSERTING LICANSE PLATE %s\n",word);
				carTemp.licansePlate = (char*)malloc(sizeof(char)*(strlen(word) + 1));
				strcpy(carTemp.licansePlate, word);
				break;
			case 8:
				//printf("INSERTING PERFORMANCE %s\n",word);
				carTemp.performance = parsePerformance(word);
				break;
			case 9:
				//printf("INSERTING DRIVEN %s\n",word);
				carTemp.driven = parseDriven(word);
				break;
			}

			step++;
			if (step > 9) {
				step = 1;
				copyCar(&car[amount - 1], &carTemp);
			}
		}
		return amount;
	}

	//printf("ERROR OPENNING FILE.");
	return 0;
}

void copyCar(Car *orig, Car *newCar) {
	orig->brand = newCar->brand;
	orig->type = newCar->type;
	orig->licansePlate = newCar->licansePlate;
	orig->color = newCar->color;
	orig->fuel = newCar->fuel;
	orig->driven = newCar->driven;
	orig->evidDate = newCar->evidDate;
	orig->performance = newCar->performance;
	orig->year = newCar->year;
}

void printList(Car *car, int n) {
	int i;
	for (i = 0; i<n; i++) {
		printCar(&car[i]);
		printf("\n");
	}
}

void printCar(Car *car) {
	printf("%s %s %s %d %c %s %s %d %d", car->brand, car->type, getColor(car->color), car->year, car->fuel, getDate(car->evidDate), car->licansePlate, car->performance, car->driven);
}

char *getColor(Color color) {
	//printf("GET COLOR %d\n",color);
	char *colorString;
	switch (color) {
	case RED:
		colorString = (char*)malloc(sizeof(char)*(strlen("red") + 1));
		strcpy(colorString, "red\0");
		return colorString;
	case BLUE:
		colorString = (char*)malloc(sizeof(char)*(strlen("blue") + 1));
		strcpy(colorString, "blue\0");
		return colorString;
	case GREEN:
		colorString = (char*)malloc(sizeof(char)*(strlen("green") + 1));
		strcpy(colorString, "green\0");
		return colorString;
	case SILVER:
		colorString = (char*)malloc(sizeof(char)*(strlen("dark_blue") + 1));
		strcpy(colorString, "silver\0");
		return colorString;
	case BROWN:
		colorString = (char*)malloc(sizeof(char)*(strlen("dark_green") + 1));
		strcpy(colorString, "brown\0");
		return colorString;
	case ORANGE:
		colorString = (char*)malloc(sizeof(char)*(strlen("orange") + 1));
		strcpy(colorString, "orange\0");
		return colorString;
	case YELLOW:
		colorString = (char*)malloc(sizeof(char)*(strlen("yellow") + 1));
		strcpy(colorString, "yellow\0");
		return colorString;
	case WHITE:
		colorString = (char*)malloc(sizeof(char)*(strlen("white") + 1));
		strcpy(colorString, "white\0");
		return colorString;
	case GRAY:
		colorString = (char*)malloc(sizeof(char)*(strlen("gray") + 1));
		strcpy(colorString, "gray\0");
		return colorString;
	case BLACK:
		colorString = (char*)malloc(sizeof(char)*(strlen("black") + 1));
		strcpy(colorString, "black\0");
		return colorString;
	}
	colorString = (char*)malloc(sizeof(char)*(strlen("uknown") + 1));
	strcpy(colorString, "uknown\0");
	return colorString;
}


char *getDate(Date date) {
	//printf("GET DATE\n");
	char *dateString = (char*)malloc(sizeof(char) * 12);
	int index = 0;
	if (date.day>9) {
		dateString[index++] = date.day / 10 + 48;
		dateString[index++] = date.day % 10 + 48;
	}
	else {
		dateString[index++] = date.day % 10 + 48;
	}
	dateString[index++] = '.';
	if (date.month>9) {
		dateString[index++] = date.month / 10 + 48;
		dateString[index++] = date.month % 10 + 48;
	}
	else {
		dateString[index++] = date.month % 10 + 48;
	}
	dateString[index++] = '.';

	int c1 = date.year / 1000;
	int c2 = (date.year - c1 * 1000) / 100;
	int c3 = (date.year - c1 * 1000 - c2 * 100) / 10;
	int c4 = (date.year - c1 * 1000 - c2 * 100) % 10;
	dateString[index++] = c1 + 48;
	dateString[index++] = c2 + 48;
	dateString[index++] = c3 + 48;
	dateString[index++] = c4 + 48;
	dateString[index] = '\0';


	return dateString;
}
char *getDay(int day) {
	char *dayString;
	if (day < 10) {
		dayString = (char*)malloc(sizeof(char) * 2);
		dayString[0] = day + 48;
		dayString[1] = '\0';
	}
	else {
		dayString = (char*)malloc(sizeof(char) * 3);
		dayString[0] = day / 10 + 48;
		dayString[1] = day % 10 + 48;
		dayString[2] = '\0';
	}
	return dayString;
}
char *getMonth(int month) {
	char *monthString;
	if (month < 10) {
		monthString = (char*)malloc(sizeof(char) * 2);
		monthString[0] = month + 48;
		monthString[1] = '\0';
	}
	else {
		monthString = (char*)malloc(sizeof(char) * 3);
		monthString[0] = month / 10 + 48;
		monthString[1] = month % 10 + 48;
		monthString[2] = '\0';
	}
	return monthString;
}
char *getYear(int year) {
	char yearString[5];
	int index = 0;
	int c1 = year / 1000;
	int c2 = (year - c1 * 1000) / 100;
	int c3 = (year - c1 * 1000 - c2 * 100) / 10;
	int c4 = (year - c1 * 1000 - c2 * 100) % 10;
	yearString[index++] = c1 + 48;
	yearString[index++] = c2 + 48;
	yearString[index++] = c3 + 48;
	yearString[index++] = c4 + 48;
	yearString[index] = '\0';
	return yearString;
}

bool findCarBySPZ(Car *car, int n, char *spz) {
	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(car[i].licansePlate, spz) == 0) {
			printCar(&car[i]);
			printf("\n");
			return true;
		}
	}

	printf("NO CAR WITH %s PLATE\n", spz);
	return false;
}

void orderCarsByDate(Car *car, int n) {
	Car *ordered = (Car*)malloc(sizeof(Car)*n);
	Car *tempCar = (Car*)malloc(sizeof(Car));
	int i;
	copyCar(tempCar, &car[0]);
	for (i = 0; i < n; i++) {
		copyCar(&ordered[i], &car[i]);
	}

	for (i = 0; i < n - 1; i++) {
		int j = i;
		for (j; j < n; j++) {
			if (ordered[i].evidDate.year > ordered[j].evidDate.year) {
				copyCar(tempCar, &ordered[i]);
				copyCar(&ordered[i], &ordered[j]);
				copyCar(&ordered[j], tempCar);
			}
			else if (ordered[i].evidDate.year == ordered[j].evidDate.year) {
				if (ordered[i].evidDate.month > ordered[j].evidDate.month) {
					copyCar(tempCar, &ordered[i]);
					copyCar(&ordered[i], &ordered[j]);
					copyCar(&ordered[j], tempCar);
				}
				else if (ordered[i].evidDate.month == ordered[j].evidDate.month) {
					if (ordered[i].evidDate.day > ordered[j].evidDate.day) {
						copyCar(tempCar, &ordered[i]);
						copyCar(&ordered[i], &ordered[j]);
						copyCar(&ordered[j], tempCar);
					}
				}
			}
		}
	}

	printList(ordered, n);
}

// vypise auta ktore maju rok vyroby medzi dvoma zadanymi hodnotami - vcitane nich
void printListBetwenYesrs(Car *car, int n, int beginYear, int endyear) {
	for (n - 1; n >= 0; n--) {
		if (car[n].year >= beginYear && car[n].year <= endyear) {
			printCar(&car[n]);
			printf("\n");
		}
	}
}

// vypise zoznam aut, kde datum evidencie je v lete …t.z. mesiace jun, jul, august
void printListSummer(Car *car, int n) {
	for (n - 1; n >= 0; n--) {
		if (car[n].evidDate.month >= JUN && car[n].evidDate.month <= AUG) {
			printCar(&car[n]);
			printf("\n");
		}
	}
}

//vypise auta ktore jazdia na benzin
void printPetrolCars(Car *car, int n) {
	for (n - 1; n >= 0; n--) {
		if (car[n].fuel == 'B') {
			printCar(&car[n]);
			printf("\n");
		}
	}
}

//vypise auta danej farby
void printCarsByColor(Car *car, int n, Color color) {
	for (n - 1; n >= 0; n--) {
		if (car[n].color == color) {
			printCar(&car[n]);
			printf("\n");
		}
	}
}

//vypocita priemerny pocet km zo vsetkych aut
float calculateAverageValue(Car *car, int n) {
	int i = n;
	float avg = 0;
	for (i - 1; i >= 0; i--) {
		avg += car[n].driven;
	}
	return avg / n;
}

//vygeneruje XML subor
bool generateXML(Car *car, int n) {
	FILE *xmlOut = fopen("cars.xml", "w");
	int i;
	if (xmlOut != NULL) {
		fprintf(xmlOut, "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n");
		fprintf(xmlOut, "<cars>\n");
		for (i = 0; i < n; i++) {

			
			fprintf(xmlOut, "\n\t<car id=%d>\n", i + 1); //item start			
			nextElement(xmlOut, "brand", car[i].brand, "type", car[i].type, 2);	//brand & type
			nextElement(xmlOut, "color", getColor(car[i].color), NULL, NULL, 2); //color
			nextElement(xmlOut, "year", getYear(car[i].year),NULL,NULL,2); //year

			char temp[2]; //fuel
			temp[0] = car[i].fuel;
			temp[1] = '\0';
			nextElement(xmlOut, "fuel", temp, NULL, NULL, 2);

			//date
			char **tags = (char**)malloc(sizeof(char*) * 3); //tags
			tags[0] = (char*)malloc(sizeof(char) * 4);
			strcpy(tags[0], "day\0");
			tags[1] = (char*)malloc(sizeof(char) * 6);
			strcpy(tags[1], "month\0");
			tags[2] = (char*)malloc(sizeof(char) * 5);
			strcpy(tags[2], "year\0");
			char **values = (char**)malloc(sizeof(char*) * 3); //values
			values[0] = (char*)malloc(sizeof(char) * (strlen(getDay(car[i].evidDate.day)) + 1));
			strcpy(values[0], getDay(car[i].evidDate.day));
			values[1] = (char*)malloc(sizeof(char) * (strlen(getMonth(car[i].evidDate.month)) + 1));
			strcpy(values[1], getMonth(car[i].evidDate.month));
			values[2] = (char*)malloc(sizeof(char) * (strlen(getYear(car[i].evidDate.year)) + 1));
			strcpy(values[2], getYear(car[i].evidDate.year));
			nextStructElement(xmlOut, "date", tags, values, 3, NULL, NULL, 2); 

			nextElement(xmlOut, "plate", car[i].licansePlate, NULL, NULL, 2); //licanse plate
			fprintf(xmlOut, "\t<performance>%d KW</performance>\n", car[i].performance); //performance
			fprintf(xmlOut, "\t<driven>%d km</driven>\n", car[i].driven); //driven
			fprintf(xmlOut, "\t</car>\n"); //item end
		}
		fprintf(xmlOut, "\n</cars>\n");
		return true;
	}

	return false;
}

void nextElement(FILE *file, char *tag, char *value, char *atribute, char *attValue,  int step) {
	level(file, step);
	fprintf(file, "<%s ", tag);

	if (atribute != NULL && attValue != NULL) {
		fprintf(file, "%s=%s", atribute, attValue);
	}

	fprintf(file, ">%s</%s>\n",value, tag);
}

void nextStructElement(FILE *file, char *root_tag, char **child, char **values, int n, char *att, char *attValue, int step) {
	level(file,step);
	fprintf(file, "<%s ", root_tag);

	if (att != NULL && attValue != NULL) {
		fprintf(file, "%s=%s", att, attValue);
	}
	fprintf(file, ">\n");
	int i = 0;
	for (i; i < n; i++) {
		nextElement(file, child[i], values[i], NULL, NULL, step + 1);
	}
	level(file, step);
	fprintf(file, "</%s>\n", root_tag);
}

void level(FILE *out,int step) {
	for (step; step <= 0; step--) {
		fprintf(out, "\t");
	}
}

Date parseDate(char* string) {
	Date date;
	int day, month, year;
	char in[4];
	int index = 0, i, step = 1, temp = 0;
	for (i = 0; i<strlen(string); i++) {
		if (string[i] == '.') {
			step++;
			temp = 0;
			continue;
		}
		if (step == 1) {
			temp += string[i] - 48;
			if (string[i + 1] != '.') {
				temp *= 10;
			}
			date.day = temp;
		}
		else if (step == 2) {
			temp += string[i] - 48;
			if (string[i + 1] != '.') {
				temp *= 10;
			}
			date.month = temp;
		}
		else {
			temp += string[i] - 48;
			if (string[i + 1] != '\0') {
				temp *= 10;
			}
			date.year = temp;
		}
	}

	return date;
}
int parseYear(char* string) {
	int year = 0;
	int i;
	for (i = 0; i<strlen(string); i++) {
		year += string[i] - 48;
		if (string[i + 1] != '\0') {
			year *= 10;
		}
	}

	return year;
}
Color parseColor(char* string) {
	Color color;

	if (strcmp(string, "red") == 0) {
		color = RED;
		return color;
	}
	else if (strcmp(string, "green") == 0) {
		color = GREEN;
		return color;
	}
	else if (strcmp(string, "blue") == 0) {
		color = BLUE;
		return color;
	}
	else if (strcmp(string, "silver") == 0) {
		color = SILVER;
		return color;
	}
	else if (strcmp(string, "brown") == 0) {
		color = BROWN;
		return color;
	}
	else if (strcmp(string, "orange") == 0) {
		color = ORANGE;
		return color;
	}
	else if (strcmp(string, "yellow") == 0) {
		color = YELLOW;
		return color;
	}
	else if (strcmp(string, "gray") == 0) {
		color = GRAY;
		return color;
	}
	else if (strcmp(string, "black") == 0) {
		color = BLACK;
		return color;
	}
	else {
		color = WHITE;
		return color;
	}

	return color;
}
int parseDriven(char* string) {
	int driven = 0;
	int i;
	for (i = 0; i<strlen(string); i++) {
		driven += string[i] - 48;
		if (string[i + 1] != '\0') {
			driven *= 10;
		}
	}

	return driven;
}

int parsePerformance(char* string) {
	int performance = 0;
	int i;
	for (i = 0; i<strlen(string); i++) {
		performance += string[i] - 48;
		if (string[i + 1] != '\0') {
			performance *= 10;
		}
	}

	return performance;
}
