#include "Dictionary.h"

void printData(char languageIndex, char commandIndex, Language *data) {
	int l_index = languageIndex - '0';
	int c_index = commandIndex - '0';
	if (data != NULL) {
		if (l_index < 0) {
			printf("Select language:\n");
			int i;
			for (i = 0; i < SIZE; i++) {
				printf("%d. ", i);
				printf("%s\n", data[i].name);
			}
		}
		else if (c_index < 0 && l_index >= 0) {
			printf("You have selected %s\n", data[l_index].name);
		}
		else {
			printf("You have selected %s and %s\n", data[l_index].name, getTypeString(c_index));
		}
	}
}

char *getTypeString(int index) {
	CommType type[] = { IN,OUT,LOGIC,ARITMETIC };
	switch (type[index]) {
	case IN: return "Input";
	case OUT: return "Output";
	case LOGIC: return "Logic";
	case ARITMETIC: return "Aritmetic";
	}
	return "Empty";
}