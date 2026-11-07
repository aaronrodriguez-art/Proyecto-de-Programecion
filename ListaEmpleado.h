#ifndef LISTAEMPLEADO_H
#define LISTAEMPLEADO_H
#include "NodoEmpleado.h"

class ListaEmpleado {
public:
	ListaEmpleado();
	void insertarInicio(Empleado*);
	bool eliminaInicio();
	string toString();
	int cuentaNodos();
	bool listaVacia(); 
	~ListaEmpleado();
	
private:
	NodoEmpleado *primero;
	NodoEmpleado * actual;
};

#endif

