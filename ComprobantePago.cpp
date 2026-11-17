#include "ComprobantePago.h"

ComprobantePago::ComprobantePago() {
	codigo = 0;
	periodo = "";
	empleado = NULL;
	departamento = NULL;
	salarioBruto = 0;
	montoHorasExtra = 0;
	bonoNocturno = 0;
	deducciones = 0;
	salarioNeto = 0;
}

ComprobantePago::ComprobantePago(int codigo, string periodo, Empleado* empleado, Departamento* departamento,
	double salarioBruto, double montoHorasExtra, double bonoNocturno, double deducciones) {
	this->codigo = codigo;
	this->periodo = periodo;
	this->empleado = empleado;
	this->departamento = departamento;
	this->salarioBruto = salarioBruto;
	this->montoHorasExtra = montoHorasExtra;
	this->bonoNocturno = bonoNocturno;
	this->deducciones = deducciones;
	calcularNeto();
}

ComprobantePago::~ComprobantePago() {
	
}

void ComprobantePago::calcularNeto() {
	salarioNeto = salarioBruto + montoHorasExtra + bonoNocturno - deducciones;
}

void ComprobantePago::setCodigo(int codigo) { this->codigo = codigo; }
void ComprobantePago::setPeriodo(string periodo) { this->periodo = periodo; }
void ComprobantePago::setSalarioBruto(double salarioBruto) { this->salarioBruto = salarioBruto; calcularNeto(); }
void ComprobantePago::setMontoHorasExtra(double montoHorasExtra) { this->montoHorasExtra = montoHorasExtra; calcularNeto(); }
void ComprobantePago::setBonoNocturno(double bonoNocturno) { this->bonoNocturno = bonoNocturno; calcularNeto(); }
void ComprobantePago::setDeducciones(double deducciones) { this->deducciones = deducciones; calcularNeto(); }

int ComprobantePago::getCodigo() { return codigo; }
string ComprobantePago::getPeriodo() { return periodo; }
Empleado* ComprobantePago::getEmpleado() { return empleado; }
Departamento* ComprobantePago::getDepartamento() { return departamento; }
double ComprobantePago::getSalarioBruto() { return salarioBruto; }
double ComprobantePago::getMontoHorasExtra() { return montoHorasExtra; }
double ComprobantePago::getBonoNocturno() { return bonoNocturno; }
double ComprobantePago::getDeducciones() { return deducciones; }
double ComprobantePago::getSalarioNeto() { return salarioNeto; }

string ComprobantePago::toString() {
	stringstream s;
	s << fixed << setprecision(2);
	s << "------ COMPROBANTE DE PAGO ------" << endl;
	s << "Codigo: " << codigo << endl;
	s << "Periodo: " << periodo << endl;
	if (empleado != NULL) {
		s << "Empleado: " << empleado->getNombre() << " (cedula " << empleado->getCedula() << ")" << endl;
	}
	if (departamento != NULL) {
		s << "Departamento: " << departamento->getNombre() << endl;
	}
	s << "Salario bruto: " << salarioBruto << endl;
	s << "Horas extra: " << montoHorasExtra << endl;
	s << "Bono nocturno/guardia: " << bonoNocturno << endl;
	s << "Deducciones: " << deducciones << endl;
	s << "Salario neto: " << salarioNeto << endl;
	return s.str();
}
