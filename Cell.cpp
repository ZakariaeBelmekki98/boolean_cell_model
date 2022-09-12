#include "Cell.h"


void init_cell(Cell* cell, bool A, bool G, bool P, bool m, bool neg){
	cell->Activator = A;
	cell->Gene = G;
	cell->Protein = P;
	cell->mRNA = m;
	cell->negative = neg;
}

void init_cell(Cell* dst, Cell* src){
	dst->Activator = src->Activator;
	dst->Gene = src->Gene;
	dst->Protein = src->Protein;
	dst->mRNA = src->mRNA;
	dst->cell_memory = src->cell_memory;
	dst->negative = src->negative;
}

bool transcribe(Cell *cell){
	if(cell->negative){	
		if(cell->Gene && !cell->Protein) return true;
		else return false;
	} else {
		if(cell->Gene && cell->Protein) return true;
		else return false;
	}
}

bool translate(Cell *cell){
	if(cell->mRNA && cell->Activator){
		return true;
	} else return false;

}

void simulate_cell(Cell *cell, size_t iterations){
	Cell cell_mem;
	for(int i=0; i<iterations; i++){
		init_cell(&cell_mem, cell);
		cell->cell_memory = &cell_mem;
		bool trc = transcribe(cell->cell_memory);
		bool trl = translate(cell->cell_memory);
		if(trc) {
			cell->mRNA= true;
		} else{
			cell->mRNA = false;
		}
			
		if(trl) {
			cell->mRNA = false;
			cell->Protein = true;
		} else{
			cell->Protein = false;
		}

		std::cout << "----------------------------------------------------------------\n";
		std::cout << "iter\t"<< i <<"\tGene\tActivator\n\t\t" << cell->Gene << "\t" << cell->Activator << "\n";
		std::cout << "mRNA\t" << cell->cell_memory->mRNA << "\tTrc\tTrl\n";
		std::cout << "Protein\t" << cell->cell_memory->Protein << "\t" <<  trc <<"\t" << trl << "\n";	
		if(*cell == *(cell->cell_memory)) {
			std::cout << "System converged\n"; 
			break;
		}
	}
}
