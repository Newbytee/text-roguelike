#include <conio.h>
#include <stdio.h>
#include <ctype.h>

#include "Input.h"

Input::Input() {



}

char Input::getKeypress() {

	char input = _getch();
	input = (tolower(input));

	return input;

}
