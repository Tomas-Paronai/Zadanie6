#include "Dictionary.h"


int main() {
	Language *data = (Language*)malloc(sizeof(Language) * 2);
	Command command1, command2, command3, command4;
	command1.type = IN;
	command2.type = OUT;
	command3.type = ARITMETIC;
	command4.type = IN;

	char *name = "java\0";
	data[0].name = (char*)malloc(sizeof(char)*(strlen(name) + 1));
	strcpy(data[0].name, name);
	data[0].commands = (Command*)malloc(sizeof(Command) * 2);
	data[0].commands[0] = command1;
	data[0].commands[1] = command2;
	data[0].numberOfCommands = 2;

	char name2[] = "C++\0";
	data[1].name = (char*)malloc(sizeof(char)*(strlen(name2) + 1));
	strcpy(data[1].name, name2);
	data[1].commands = (Command*)malloc(sizeof(Command) * 2);
	data[1].commands[0] = command3;
	data[1].commands[1] = command4; 
	data[1].numberOfCommands = 2;

	char c;
	int level = 1;
	char language, type, command;
	do {
		if (level == LANG) {
			printData(0, 0, data);
		}
		else if (level == TYPE) {
			if (c != '0') {
				language = c;
			}			
			printData(c, 0, data);
			int i;
			for (i = 0; i < 4; i++) {
				printf("%d. %s\n", i, getTypeString(i));
			}
		}
		else if (level == COMM) {
			if (c != '0') {
				type = c;
			}
			printData(language, c, data);
		}
		else if (level == DET) {

		}
		


		c = _getch(); //get user input
		if (level == LANG && c-'0' > -1 && c-'0s' < SIZE) {
			level++;
		}
		else if(level == TYPE && c - '0' > -1 && c - '0' < TYPE_SIZE){
			level++;
		}
		else if (level > 1 && tolower(c) == 'b') {
			level--;
			c = '0';
		}
		
		system("cls");
	} while (tolower(c) != 'q');


	return 0;
}