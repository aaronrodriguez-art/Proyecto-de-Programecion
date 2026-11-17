#include "Departamento.h"

Departamento::Departamento() {
	this -> nombre = "";
	this -> codigo = "";
	this -> puestos = new ListaPuesto;
}

// el departamento es dueño de la lista de puestos y cuando se destruye se libera (composicion)
Departamento::~Departamento() {
	
	delete puestos;
}


Departamento::Departamento (string nombre, string codigo) {
	this -> nombre = nombre;
	this -> codigo = codigo;
	this -> puestos = new ListaPuesto;
}

void Departamento::setNombre (string nombre) {
	this -> nombre = nombre;
}

void Departamento::setCodigo (string codigo) {
	this -> codigo = codigo;
}

string Departamento::getNombre ( ) {
	return nombre;
}

string Departamento::getCodigo ( ) {
	return codigo;
}

string Departamento::toString ( ) {
	stringstream d;
	d << "------ INFORMACION DEL DEPARTAMENTO ------" << endl;
	d << "Nombre del departamento: " << nombre << endl;
	d << "Codigo del departamento: " << codigo << endl;
	d << puestos->toString();
	
	return d.str();
}

void Departamento::insertarPuesto (Puesto* p) {
	puestos->insertarInicio(p);
	
}

ListaPuesto * Departamento::getPuesto ( ) {
	return puestos;
}

