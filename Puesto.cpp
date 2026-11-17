#include "Puesto.h"

Puesto::Puesto() {
	this -> nombre = "";
	this -> codigo = "";
}

Puesto::~Puesto() {
	
}

Puesto::Puesto (string nombre, string codigo) {
	this -> nombre = nombre;
	this -> codigo = codigo;
}

void Puesto::setNombre (string nombre) {
	this -> nombre = nombre;
}

void Puesto::setCodigo (string codigo) {
	this -> codigo = codigo;
}

string Puesto::getNombre ( ) {
	return nombre;
}

string Puesto::getCodigo ( ) {
	return codigo;
}

string Puesto::toString ( ) {
	stringstream x;
	x << "------ INFORMACION DEL PUESTO ------" << endl;
	x << "Nombre del puesto: " << nombre << endl;
	x << "Codigo del puesto: " << codigo << endl;
	
	return x.str();
}
