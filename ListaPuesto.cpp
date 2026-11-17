#include "ListaPuesto.h"

ListaPuesto::ListaPuesto() {
	primero = NULL;
	actual = NULL;
}

ListaPuesto::~ListaPuesto() {
	while (!listaVacia()) {
		eliminaInicio();
	}
}


void ListaPuesto::insertarInicio (Puesto* p) {
	primero = new NodoPuesto(p, primero);
}

bool ListaPuesto::eliminaInicio ( ) {
	if (primero == NULL) {
		return false;
	}else{
		actual = primero;
		Puesto* puesto = actual -> getInfo();
		primero = primero -> getSig();
		delete puesto;
		delete actual;
		return true;
	}
}

string ListaPuesto::toString ( ) {
	actual = primero;
	stringstream s;
	while (actual != NULL) {
		s << actual -> toStringNodoPuesto();
		actual = actual -> getSig();
	}
	
	return s.str();
}

int ListaPuesto::cuentaNodos ( ) {
	actual = primero;
	int can =0;
	while (actual != NULL) {
		can++;
		actual = actual -> getSig();
	}
	return can;
}

bool ListaPuesto::listaVacia ( ) {
	return (primero == NULL) ? true : false;
}

NodoPuesto * ListaPuesto::getPrimero ( ) {
	return primero;
}

