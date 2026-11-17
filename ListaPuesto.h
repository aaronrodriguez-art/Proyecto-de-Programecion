#ifndef LISTAPUESTO_H
#define LISTAPUESTO_H
#include "NodoPuesto.h"

class ListaPuesto {
public:
	ListaPuesto();
	void insertarInicio(Puesto*);
	bool eliminaInicio();
	string toString();
	int cuentaNodos();
	bool listaVacia();
	NodoPuesto* getPrimero();
	~ListaPuesto();
private:
	NodoPuesto* primero;
	NodoPuesto* actual;
};

#endif

