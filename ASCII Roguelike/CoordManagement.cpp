#include "CoordManagement.h"
#include "Player.h"
#include "GameCore.h"

#include <iostream>

CoordManagement::CoordManagement() {

	

}

int CoordManagement::getRelativeXCoord(int x) {

	Player player;

	x += player.getPlayerX();

	return x;

}

int CoordManagement::getRelativeYCoord(int y) {

	Player player;

	y += player.getPlayerY();

	return y;

}

int CoordManagement::getRelativeCoord(int coord, std::string type, char coordType) {

	if (type == "player") {

		Player player;

		if (coordType == 'x') {

			coord += player.getPlayerX();

			return coord;

		} else if (coordType == 'y') { 
		
			coord += player.getPlayerY();

			return coord;
		
		}

	}

	return 0;

	//TODO: apply same logic for "enemies"

}

bool CoordManagement::verifyCoords(int x, int y) {

	GameCore core;

	std::cout << x << "\t" << y;

	if (y < 0) {

		return true;

	} else if (y > core.getStaticLevelHeight()) {

		std::cout << core.getStaticLevelHeight();

		return true;

	}

	if (x < 0) {

		return false;

	} else if (x > core.getLevelWidth(y)) {

		return false;

	}
	
	return true;
	
}