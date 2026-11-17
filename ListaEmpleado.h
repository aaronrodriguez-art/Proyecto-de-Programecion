#ifndef LISTAEMPLEADO_H
#define LISTAEMPLEADO_H
#include "NodoEmpleado.h"

class ListaEmpleado {
public:
	ListaEmpleado();
	void insertarInicio(Empleado*);
	void insertarFinal(Empleado*);
	bool eliminaInicio();
	string toString();
	int cuentaNodos();
	bool listaVacia(); 
	NodoEmpleado* getPrimero();
	Empleado* buscarPorCedula(int cedula);
	~ListaEmpleado();
	
private:
	NodoEmpleado *primero;
	NodoEmpleado * actual;
};

#endif

