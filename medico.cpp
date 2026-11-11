#include "medico.h"

medico::medico() : Empleado() {
	this->especialidad = new string("");
	this->anosExperiencia = new int(0);
	this->turnoGuardia = new string("");
}

medico::medico(int cedula, string nombre, int codigo, string especialidad, int anosExperiencia, string turnoGuardia) 
	: Empleado(cedula, nombre, codigo) {
	this->especialidad = new string(especialidad);
	this->anosExperiencia = new int(anosExperiencia);
	this->turnoGuardia = new string(turnoGuardia);
}

medico::~medico() {
	delete especialidad;
	delete anosExperiencia;
	delete turnoGuardia;
}

void medico::setEspecialidad(string especialidad) {
	delete this->especialidad;
	this->especialidad = new string(especialidad);
}

void medico::setAnosExperiencia(int anosExperiencia) {
	delete this->anosExperiencia;
	this->anosExperiencia = new int(anosExperiencia);
}

void medico::setTurnoGuardia(string turnoGuardia) {
	delete this->turnoGuardia;
	this->turnoGuardia = new string(turnoGuardia);
}

string medico::getEspecialidad() {
	return *especialidad;
}

int medico::getAnosExperiencia() {
	return *anosExperiencia;
}

string medico::getTurnoGuardia() {
	return *turnoGuardia;
}

double medico::calcularSalario() {
	double salarioBase = 2500000.0;
	double bonoExperiencia = (*anosExperiencia) * 50000.0;
	double salarioBruto = salarioBase + bonoExperiencia;
	
	double deduccionSeguro = salarioBruto * 0.1067;
	double deduccionImpuestos = salarioBruto * 0.05;
	
	double salarioNeto = salarioBruto - deduccionSeguro - deduccionImpuestos;
	return salarioNeto;
}

string medico::toString() {
	stringstream ss;
	ss << Empleado::toString();
	ss << "Especialidad: " << *especialidad << endl;
	ss << "Años de Experiencia: " << *anosExperiencia << endl;
	ss << "Turno de Guardia: " << *turnoGuardia << endl;
	return ss.str();
}
