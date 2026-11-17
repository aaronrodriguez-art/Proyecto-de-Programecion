#ifndef NODODEPARTAMENTO_H
#define NODODEPARTAMENTO_H
#include "Departamento.h"
	
class NodoDepartamento {
public:
	NodoDepartamento(Departamento*, NodoDepartamento*);
	~NodoDepartamento();
	void setInfo(Departamento*);
	Departamento* getInfo();
	void setSig(NodoDepartamento*);
	NodoDepartamento* getSig();
	string toStringNodoDepartamento();
private:
	Departamento* info;
	NodoDepartamento* sig;
};

#endif

