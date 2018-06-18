#include "Utils.h"
#include <conio.h>
#include <ctype.h>

void Utils::clearScreen() {
	printf("%s", (std::string(100, '\n')).c_str());
}

char Utils::getKeyPress() {
	return tolower(_getch());
}