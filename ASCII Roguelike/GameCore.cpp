#include "GameCore.h"

#include <string>
#include <cstdlib>

GameCore::GameCore() {



}

void GameCore::clearScreen() {

	 printf("%s", (std::string(100, '\n')).c_str());

}