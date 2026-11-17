#ifndef COMPROBANTEPAGO_H
#define COMPROBANTEPAGO_H
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Empleado.h"
#include "Departamento.h"
using namespace std;

class ComprobantePago {
public:
	ComprobantePago();
	ComprobantePago(int codigo, string periodo, Empleado* empleado, Departamento* departamento,
	double salarioBruto, double montoHorasExtra, double bonoNocturno, double deducciones);
	~ComprobantePago();
	
	void setCodigo(int codigo);
	void setPeriodo(string periodo);
	void setSalarioBruto(double salarioBruto);
	void setMontoHorasExtra(double montoHorasExtra);
	void setBonoNocturno(double bonoNocturno);
	void setDeducciones(double deducciones);
	
	int getCodigo();
	string getPeriodo();
	Empleado* getEmpleado();
	Departamento* getDepartamento();
	double getSalarioBruto();
	double getMontoHorasExtra();
	double getBonoNocturno();
	double getDeducciones();
	double getSalarioNeto();
	
	string toString();
	
private:
	void calcularNeto();
	
	int codigo;
	string periodo;
	// el comprobante referencia a empleado y departamento, pero no es dueña (agregacion)
	Empleado* empleado;
	Departamento* departamento;
	double salarioBruto;
	double montoHorasExtra;
	double bonoNocturno;
	double deducciones;
	double salarioNeto;
};

#endif
