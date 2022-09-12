#include <iostream>

typedef struct Cell{
	Cell* cell_memory = NULL;
	bool Activator;
	bool Gene;
	bool Protein;
	bool mRNA;

	bool operator==(const Cell& cell){
		if(Activator == cell.Activator && Gene == cell.Gene && Protein == cell.Protein && mRNA == cell.mRNA) return true;
		else return false;
	}
	// Autoregulatory properties: True for negative feedback autoregulatory system and False for 
	// negeative autoregulatory system
	bool negative = true;
}Cell;

void init_cell(Cell* cell, bool A, bool G, bool P, bool m, bool neg);
void init_cell(Cell* dst, Cell* src);
bool transcribe(Cell* cell);
bool translate(Cell* cell);
void simulate_cell(Cell* cell, size_t iterations);
