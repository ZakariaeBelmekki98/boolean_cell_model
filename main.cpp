#include <iostream>
#include "Cell.h"

int main(){
	Cell cell;
	init_cell(&cell, 0, 1, 1, 1, false);
	simulate_cell(&cell, 4);
	return 1;
}
