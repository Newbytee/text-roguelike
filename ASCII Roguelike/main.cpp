#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

#include "GameCore.h"

int main() {

	GameCore core;

	core.prepareLevel(1);
	core.printLevel();

	system("PAUSE");
	return 0;

}

