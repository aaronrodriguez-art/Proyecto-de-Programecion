#ifndef NodoEmpleadoEMPLEADO_H
#define NodoEmpleadoEMPLEADO_H
#include "Empleado.h"

class NodoEmpleado {
	
private:
	Empleado*  info;
	NodoEmpleado * sig;
public:
	NodoEmpleado(Empleado*, NodoEmpleado*);
	~NodoEmpleado();
	void setInfo(Empleado*);
	Empleado* getInfo();
	void setSig(NodoEmpleado*);
	NodoEmpleado* getSig();
	string toStringNodoEmpleado();
};

#endif

