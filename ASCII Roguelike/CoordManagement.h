#pragma once

class CoordManagement {

public:

	CoordManagement();

	int getRelativeXCoord(int x);
	int getRelativeYCoord(int y);
	bool verifyCoords(int x, int y);

};