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
	void setCalcularSalario(double Salario);
	
	int getCedula();
	string getNombre();
	int getCodigo();
	string toString();
	
	virtual double calcularSalario() = 0;
	virtual ~Empleado();
	
	void autoGuardar(ofstream&);
	static Empleado* autoLeer(ifstream&);
	
protected:
	int *cedula;
	string *nombre;
	int *codigo;
	
};

#endif

