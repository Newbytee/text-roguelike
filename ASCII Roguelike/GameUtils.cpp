#include "GameUtils.h"

#include <string>
#include <cstdlib>

GameUtils::GameUtils() {



}

void GameUtils::clearScreen() {

	 printf("%s", (std::string(100, '\n')).c_str());

}