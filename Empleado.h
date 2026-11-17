#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class Empleado {
public:
	Empleado();
	Empleado(int cedula,string nombre,int codigo);
	
	void setCedula(int cedula);
	void setNombre(string nombre);
	void setCodigo(int codigo);
	
	int getCedula();
	string getNombre();
	int getCodigo();
	virtual string toString();
	
	// metodos virtuales puros para que cada tipo de empleado calcule su propio salario
	virtual double calcularSalario() = 0;
	virtual double calcularSalarioBruto() = 0;
	
	double calcularDeducciones(double salarioBruto);
	
	virtual ~Empleado();
	
	
protected:
	int *cedula;
	string *nombre;
	int *codigo;
	
};

#endif

