#ifndef ARCHIVOEMPLEADO_H
#define ARCHIVOEMPLEADO_H
#include <iostream>
#include <sstream>
#include <fstream>
#include "ListaEmpleado.h"
#include "medico.h"
#include "enfermero.h"
#include "administracion.h"
using namespace std;

class ArchivoEmpleado {
public:
	ArchivoEmpleado();
	ArchivoEmpleado(string nombreArchivo);
	~ArchivoEmpleado();
	bool guardar(ListaEmpleado* empleados);
	int cargar(ListaEmpleado* empleados);
private:
	string nombreArchivo;
};

#endif
