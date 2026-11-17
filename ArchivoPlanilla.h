#ifndef ARCHIVOPLANILLA_H
#define ARCHIVOPLANILLA_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "IAlmacenPlanilla.h"
using namespace std;

class ArchivoPlanilla : public IAlmacenPlanilla {
public:
	ArchivoPlanilla();
	ArchivoPlanilla(string nombreArchivo);
	~ArchivoPlanilla();
	bool guardar(ListaComprobantes* comprobantes);
	int cargar(ListaComprobantes* comprobantes, ListaEmpleado* empleados, ListaDepartamento* departamentos);
private:
	string nombreArchivo;
};

#endif
