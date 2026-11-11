#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H
#include "Empleado.h"

class administracion: public Empleado {
public:
	administracion();
	administracion(int cedula, string nombre, int codigo, string departamento, bool accesoFinanciero);
	
	~administracion();
	
	void setDepartamento(string departamento);
	void setAccesoFinanciero(bool accesoFinanciero);
	
	string getDepartamento();
	bool getAccesoFinanciero();
	
	string toString() override;
	double calcularSalario() override;
	
private:
	string *departamento;
	bool *accesoFinanciero;
};

#endif
