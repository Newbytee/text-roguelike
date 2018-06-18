#include "Utils.h"
#include "Level.h"
#include <iostream>

int main() {
	Utils util;
	Level level;
	bool isRunning = true;
	level.setCurrentLevel(1);

	while (isRunning) {
		level.initLevel(level.getCurrentLevel());
		level.printLevel();
	}	

	system("PAUSE");
	return 0;
}