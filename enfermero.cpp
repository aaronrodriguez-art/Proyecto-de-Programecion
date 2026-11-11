#include "enfermero.h"

enfermero::enfermero() : Empleado() {
	this->areaAsignada = new string("");
	this->estaGuardia = new bool(false);
}

enfermero::enfermero(int cedula, string nombre, int codigo, string areaAsignada, bool estaGuardia) 
	: Empleado(cedula, nombre, codigo) {
	this->areaAsignada = new string(areaAsignada);
	this->estaGuardia = new bool(estaGuardia);
}

enfermero::~enfermero() {
	delete areaAsignada;
	delete estaGuardia;
}

void enfermero::setAreaAsignada(string areaAsignada) {
	delete this->areaAsignada;
	this->areaAsignada = new string(areaAsignada);
}

void enfermero::setEstaGuardia(bool estaGuardia) {
	delete this->estaGuardia;
	this->estaGuardia = new bool(estaGuardia);
}

string enfermero::getAreaAsignada() {
	return *areaAsignada;
}

bool enfermero::getEstaGuardia() {
	return *estaGuardia;
}

double enfermero::calcularSalario() {
	double salarioBase = 1200000.0;
	double bonoGuardia = (*estaGuardia) ? 150000.0 : 0.0;
	double salarioBruto = salarioBase + bonoGuardia;
	
	double deduccionSeguro = salarioBruto * 0.1067;
	double deduccionImpuestos = salarioBruto * 0.02;
	
	double salarioNeto = salarioBruto - deduccionSeguro - deduccionImpuestos;
	return salarioNeto;
}

string enfermero::toString() {
	stringstream ss;
	ss << Empleado::toString();
	ss << "Area Asignada: " << *areaAsignada << endl;
	ss << "Esta en Guardia: " << (*estaGuardia ? "Si" : "No") << endl;
	return ss.str();
}
