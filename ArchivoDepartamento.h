#ifndef ARCHIVODEPARTAMENTO_H
#define ARCHIVODEPARTAMENTO_H
#include "ListaDepartamento.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class ArchivoDepartamento {
public:
	ArchivoDepartamento();
	~ArchivoDepartamento();
	
	NodoDepartamento* getPrimero();
	
	bool guardarDepartamento(ListaDepartamento* lista);
	void cargarDepartamento(ListaDepartamento* lista);
private:
	
};

#endif

