#pragma once

#include <string>

class CoordManagement {

public:

	CoordManagement();

	int getRelativeXCoord(int x);
	int getRelativeYCoord(int y);
	int getRelativeCoord(int coord, std::string type, char coordType);
	bool verifyCoords(int x, int y);

};