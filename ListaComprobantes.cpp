#include "ListaComprobantes.h"

ListaComprobantes::ListaComprobantes() {
	primero = NULL;
	actual = NULL;
}

ListaComprobantes::~ListaComprobantes() {
	while (!listaVacia()) {
		eliminaInicio();
	}
}

void ListaComprobantes::insertarInicio(ComprobantePago* c) {
	primero = new NodoComprobante(c, primero);
}

// crea un nodo y lo enlaza al final, si la lista esta vacia el nuevo nodo queda como primero (lista enlazada)
void ListaComprobantes::insertarFinal(ComprobantePago* c) {
	NodoComprobante* nuevo = new NodoComprobante(c, NULL);
	if (primero == NULL) {
		primero = nuevo;
	} else {
		actual = primero;
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(nuevo);
	}
}

bool ListaComprobantes::eliminaInicio() {
	if (primero == NULL) {
		return false;
	}
	actual = primero;
	primero = primero->getSig();
	delete actual;
	actual = NULL;
	return true;
}

bool ListaComprobantes::eliminarPorCodigo(int codigo) {
	NodoComprobante* anterior = NULL;
	actual = primero;
	while (actual != NULL && actual->getInfo()->getCodigo() != codigo) {
		anterior = actual;
		actual = actual->getSig();
	}
	if (actual == NULL) {
		return false; 
	}
	if (anterior == NULL) {
		primero = actual->getSig(); 
	} else {
		anterior->setSig(actual->getSig()); 
	}
	delete actual;
	actual = NULL;
	return true;
}

ComprobantePago* ListaComprobantes::buscarPorCodigo(int codigo) {
	actual = primero;
	while (actual != NULL) {
		if (actual->getInfo()->getCodigo() == codigo) {
			return actual->getInfo();
		}
		actual = actual->getSig();
	}
	return NULL;
}

string ListaComprobantes::toString() {
	stringstream s;
	actual = primero;
	while (actual != NULL) {
		s << actual->toStringNodoComprobante() << endl;
		actual = actual->getSig();
	}
	return s.str();
}

string ListaComprobantes::toStringPorCedula(int cedula) {
	stringstream s;
	actual = primero;
	while (actual != NULL) {
		Empleado* e = actual->getInfo()->getEmpleado();
		if (e != NULL && e->getCedula() == cedula) {
			s << actual->toStringNodoComprobante() << endl;
		}
		actual = actual->getSig();
	}
	return s.str();
}

int ListaComprobantes::cuentaNodos() {
	int can = 0;
	actual = primero;
	while (actual != NULL) {
		can++;
		actual = actual->getSig();
	}
	return can;
}

bool ListaComprobantes::listaVacia() {
	return primero == NULL;
}

NodoComprobante* ListaComprobantes::getPrimero() {
	return primero;
}
