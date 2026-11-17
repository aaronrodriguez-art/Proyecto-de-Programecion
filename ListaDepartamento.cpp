#include "ListaDepartamento.h"

ListaDepartamento::ListaDepartamento ( ) {
	primero = NULL;
	actual = NULL;
}

void ListaDepartamento::insertarInicio (Departamento* d) {
	primero = new NodoDepartamento(d, primero);
}

bool ListaDepartamento::eliminaInicio ( ) {
	if (primero == NULL) {
		return false;
	} else {
		actual = primero;
		primero = primero->getSig();
		
		Departamento* d = actual->getInfo();
		
		delete d;
		delete actual;
		
		actual = NULL;
		
		return true;
	}
}

string ListaDepartamento::toString ( ) {
	actual = primero;
	stringstream s;
	while (actual != NULL) {
		s << actual -> toStringNodoDepartamento();
		actual = actual -> getSig();
	}
	
	return s.str();
}


int ListaDepartamento::cuentaNodos ( ) {
	actual = primero;
	int can =0;
	while (actual != NULL) {
		can++;
		actual = actual -> getSig();
	}
	return can;
}

bool ListaDepartamento::listaVacia ( ) {
	return (primero == NULL) ? true : false;
}

ListaDepartamento::~ListaDepartamento ( ) {
	while (!listaVacia()) {
		eliminaInicio();
	}
}

NodoDepartamento * ListaDepartamento::getPrimero ( ) {
	return primero;
}

Departamento* ListaDepartamento::buscarPorCodigo(string codigo) {
	NodoDepartamento* aux = primero;
	while (aux != NULL) {
		if (aux->getInfo()->getCodigo() == codigo) {
			return aux->getInfo();
		}
		aux = aux->getSig();
	}
	return NULL;
}
