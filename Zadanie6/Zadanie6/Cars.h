//enum farby
typedef enum Color {
	BLACK,
	BLUE,
	RED,
	GREEN,
	GRAY,
	YELLOW,
	WHITE,
	SILVER,
	BROWN,
	ORANGE
}Color;

//enum mesiace
enum Month {
	JAN = 1,
	FEB,
	MAR,
	APR,
	MAJ,
	JUN,
	JUL,
	AUG,
	SEP,
	OKT,
	NOV,
	DEC
};

//objekt datum
typedef struct Date {
	int day;
	int month;
	int year;
}Date;

//objekt auto
typedef struct Car {
	char *brand;
	char *type;
	Color color;
	int year;
	char fuel;
	Date evidDate;
	char *licansePlate;
	int performance;
	int driven;
}Car;

//nacita auta zo suboru
int readCarsFromFile(Car *car, char* path);

//vypise zoznam aut
void printList(Car *car, int n);

//najde auto podla SPZ
bool findCarBySPZ(Car *car, int n, char *spz);

//zoradi a vypise auta podla roku od najstarsieho
void orderCarsByDate(Car *car, int n);

// vypise auta ktore maju rok vyroby medzi dvoma zadanymi hodnotami - vcitane nich
void printListBetwenYesrs(Car *car, int n, int beginYear, int endyear);

// vypise zoznam aut, kde datum evidencie je v lete …t.z. mesiace jun, jul, august
void printListSummer(Car *car, int n);

//vypise auta ktore jazdia na benzin
void printPetrolCars(Car *car, int n);

//vypise auta danej farby
void printCarsByColor(Car *car, int n, Color color);

//vypocita priemerny pocet km zo vsetkych aut
float calculateAverageValue(Car *car, int n);

//vygeneruje xml subor
bool generateXML(Car *car, int n);

//zisti pocet aut v subore
int getNumberOfCars(char* path);

//parsuje datum
Date parseDate(char* string);

//parsuje rok
int parseYear(char* string);

//parsuje farbu
Color parseColor(char* string);

//parsuje najazdene km
int parseDriven(char* string);

//parsuje vykon
int parsePerformance(char* string);

//vypise auto
void printCar(Car *car);

//vrati retazec reprezentujucu farbu
char* getColor(Color color);

//vrati retazec vygenerovany z datumu
char *getDate(Date date);

//skopiruje auto
void copyCar(Car *orig, Car *newCar);

//vrati retazec rok
char *getYear(int year);

//vrati retazec den
char *getDay(int day);

//vrati retazec mesiac
char *getMonth(int month);

//vygeneruje XML subor
bool generateXML(Car *car, int n);

//prida dalsi xml element
void nextElement(FILE *file, char *tag, char *value, char *atribute, char *attValue, int level);

//pridat dalsi xml element obsahujuci podelementy
void nextStructElement(FILE *file, char *root_tag, char **child, char **values, int n, char *att, char *attValue, int step);

//odkrokuje urovne xml (nefunguje)
void level(FILE *out, int step);

