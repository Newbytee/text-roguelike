#include "Utils.h"

#ifdef _WIN32
#include <conio.h>
#elif linux
#include <unistd.h>
#include <termios.h>
#endif
#include <ctype.h>
#include <iostream>

void Utils::clearScreen() {
	printf("%s", (std::string(100, '\n')).c_str());
	std::cout << std::endl;
}

#ifdef linux
char _getch(void) {
	char buf = 0;
	struct termios old = {0};
	fflush(stdout);

	if (tcgetattr(0, &old) < 0) {
		perror("tcsetattr()");
	}

	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;

	if (tcsetattr(0, TCSANOW, &old) < 0) {
		perror("tcsetattr ICANON");
	}

	if (read(0, &buf, 1) < 0) {
		perror("read()");
	}

	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;

	if (tcsetattr(0, TCSADRAIN, &old) < 0) {
		perror("tcsetattr ~ICANON");
	}

	return buf;
}
#endif

char Utils::getKeyPress() {
	return tolower(_getch());
}
