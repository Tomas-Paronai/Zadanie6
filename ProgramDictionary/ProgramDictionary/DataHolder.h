#define SIZE 2
#define  TYPE_SIZE 4

typedef enum CommType {
	IN,
	OUT,
	LOGIC,
	ARITMETIC,
};


typedef struct Command {
	CommType type;
	char **lib;
	char *disc;
	char *syntax;
};

typedef struct Language {
	char *name;
	Command *commands;
	int numberOfCommands;
};
