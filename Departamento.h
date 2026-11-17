#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include <iostream>
#include <sstream>
#include <fstream>
#include "ListaPuesto.h"

using namespace std;

class Departamento {
public:
	Departamento();
	Departamento(string nombre, string codigo);
	void setNombre(string nombre);
	void setCodigo(string codigo);
	string getNombre();
	string getCodigo();
	string toString();
	void insertarPuesto(Puesto*);
	ListaPuesto* getPuesto();
	~Departamento();
private:
	string nombre;
	string codigo;
	ListaPuesto* puestos;
};

#endif

