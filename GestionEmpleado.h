#ifndef GESTIONEMPLEADO_H
#define GESTIONEMPLEADO_H
#include "ListaEmpleado.h"
#include "ArchivoEmpleado.h"

class GestionEmpleado {
public:
	GestionEmpleado();
	~GestionEmpleado();
	
	// Devuelve false (y no lo agrega) si ya existe un empleado con esa cedula
	bool registrarEmpleado(Empleado*);
	Empleado* buscarEmpleado(int cedula);
	string mostrarEmpleados();
	int cantidadEmpleados();
	ListaEmpleado* getEmpleados();
	
	bool guardarEmpleados();
	int cargarEmpleados();
	
private:
	ListaEmpleado* empleados;
	ArchivoEmpleado* archivo;
};

#endif
