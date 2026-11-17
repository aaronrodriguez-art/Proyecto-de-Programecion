#include "GestionDepartamento.h"

GestionDepartamento::GestionDepartamento() {
	this->departamentos = new ListaDepartamento;
	this->archivo = new ArchivoDepartamento;
}

GestionDepartamento::~GestionDepartamento() {
	delete archivo;
	delete departamentos;
}

void GestionDepartamento::registrarDepartamento(Departamento* d) {
	departamentos->insertarInicio(d);
}

string GestionDepartamento::mostrarDepartamento() {
	return departamentos->toString();
}

bool GestionDepartamento::guardarDepartamento() {
	return archivo->guardarDepartamento(departamentos);
}

void GestionDepartamento::cargarDepartamento() {
	archivo->cargarDepartamento(departamentos);
}

Departamento* GestionDepartamento::buscarDepartamento(string codigo) {
	return departamentos->buscarPorCodigo(codigo);
}

ListaDepartamento* GestionDepartamento::getDepartamentos() {
	return departamentos;
}
