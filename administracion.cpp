#include "administracion.h"
administracion::administracion() : Empleado() {
	this->departamento = new string("");
	this->accesoFinanciero = new bool(false);
}

administracion::administracion(int cedula, string nombre, int codigo, string departamento, bool accesoFinanciero) 
	: Empleado(cedula, nombre, codigo) {
	this->departamento = new string(departamento);
	this->accesoFinanciero = new bool(accesoFinanciero);
}

administracion::~administracion() {
	delete departamento;
	delete accesoFinanciero;
}

void administracion::setDepartamento(string departamento) {
	delete this->departamento;
	this->departamento = new string(departamento);
}

void administracion::setAccesoFinanciero(bool accesoFinanciero) {
	delete this->accesoFinanciero;
	this->accesoFinanciero = new bool(accesoFinanciero);
}

string administracion::getDepartamento() {
	return *departamento;
}

bool administracion::getAccesoFinanciero() {
	return *accesoFinanciero;
}

double administracion::calcularSalarioBruto() {
	double salarioBase = 900000.0;
	double bonoAcceso = (*accesoFinanciero) ? 80000.0 : 0.0;
	return salarioBase + bonoAcceso;
}

double administracion::calcularSalario() {
	double salarioBruto = calcularSalarioBruto();
	double deducciones = calcularDeducciones(salarioBruto);
	double salarioNeto = salarioBruto - deducciones;
	
	return salarioNeto;
}

string administracion::toString() {
	stringstream ss;
	ss << Empleado::toString();
	ss << "Departamento: " << *departamento << endl;
	ss << "Acceso Financiero: " << (*accesoFinanciero ? "Si" : "No") << endl;
	return ss.str();
}
