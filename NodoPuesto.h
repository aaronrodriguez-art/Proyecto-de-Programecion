#ifndef NODOPUESTO_H
#define NODOPUESTO_H
#include "Puesto.h"

class NodoPuesto {
public:
	NodoPuesto(Puesto*, NodoPuesto*);
	~NodoPuesto();
	void setInfo(Puesto*);
	Puesto* getInfo();
	void setSig(NodoPuesto*);
	NodoPuesto* getSig();
	string toStringNodoPuesto();
private:
	Puesto* info;
	NodoPuesto* sig;
};

#endif

