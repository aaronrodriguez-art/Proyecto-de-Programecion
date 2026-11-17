#ifndef PUESTO_H
#define PUESTO_H
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Puesto {
public:
	Puesto();
	Puesto(string nombre, string codigo);
	void setNombre (string nombre);
	void setCodigo (string codigo);
	string getNombre();
	string getCodigo();
	string toString();
	
	~Puesto();
private:
	string nombre;
	string codigo;
};

#endif

