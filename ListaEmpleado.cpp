#include "ListaEmpleado.h"

ListaEmpleado::ListaEmpleado() {
	primero = NULL;
	actual = NULL;
}

void ListaEmpleado::insertarInicio(Empleado* e){  
	primero=new NodoEmpleado(e, primero);
}



string ListaEmpleado::toString() {
	actual = primero;
	stringstream s;
	while (actual != NULL)
	{
		s << actual->toStringNodoEmpleado();
		actual = actual->getSig();
	}
	
	return s.str();
}

int ListaEmpleado::cuentaNodos() {
	actual = primero;
	int can = 0;
	while (actual != NULL)
	{
		can++;
		actual = actual->getSig();
	}
	return can;
}

bool ListaEmpleado::listaVacia() {
	return  (primero == NULL) ? true : false;
}


bool ListaEmpleado::eliminaInicio() {
	if (primero == NULL)  // caso 1: la ListaEmpleado esta vacia
	{
		return false;
	}
	else // caso 2: la ListaEmpleado no esta vacia
	{
		actual = primero;
		primero = primero->getSig();
		delete actual;
		return true;
	}
}
ListaEmpleado::~ListaEmpleado() {
	while (!listaVacia())
	{eliminaInicio(); }
}
