#ifndef ENFERMERO_H
#define ENFERMERO_H
#include "Empleado.h"

class enfermero: public Empleado {
public:
	enfermero();
	enfermero(int cedula, string nombre, int codigo, string areaAsignada, bool estaGuardia);
	
	~enfermero();
	
	void setAreaAsignada(string areaAsignada);
	void setEstaGuardia(bool estaGuardia);
	
	string getAreaAsignada();
	bool getEstaGuardia();
	
	string toString() override;
	double calcularSalario() override;
	
private:
	string *areaAsignada;
	bool *estaGuardia;
};

#endif
