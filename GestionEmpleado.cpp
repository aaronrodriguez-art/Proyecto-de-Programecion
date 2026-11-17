#include "GestionEmpleado.h"

GestionEmpleado::GestionEmpleado() {
	this->empleados = new ListaEmpleado;
	this->archivo = new ArchivoEmpleado;
}

GestionEmpleado::~GestionEmpleado() {
	// ListaEmpleado solo borra sus nodos, no los empleados, asi que los borramos aqui antes
	NodoEmpleado* nodo = empleados->getPrimero();
	while (nodo != NULL) {
		delete nodo->getInfo();
		nodo = nodo->getSig();
	}
	delete archivo;
	delete empleados;
}

bool GestionEmpleado::registrarEmpleado(Empleado* e) {
	if (empleados->buscarPorCedula(e->getCedula()) != NULL) {
		return false;
	}
	empleados->insertarInicio(e);
	return true;
}

Empleado* GestionEmpleado::buscarEmpleado(int cedula) {
	return empleados->buscarPorCedula(cedula);
}

string GestionEmpleado::mostrarEmpleados() {
	return empleados->toString();
}

int GestionEmpleado::cantidadEmpleados() {
	return empleados->cuentaNodos();
}

ListaEmpleado* GestionEmpleado::getEmpleados() {
	return empleados;
}

bool GestionEmpleado::guardarEmpleados() {
	return archivo->guardar(empleados);
}

int GestionEmpleado::cargarEmpleados() {
	return archivo->cargar(empleados);
}
