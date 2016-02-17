
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

#include "DataHolder.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>



typedef enum Level {
	LANG = 1,
	TYPE,
	COMM,
	DET
};

void printData(char languageIndex, char commandIndex, Language *data);

char *getTypeString(int index);
