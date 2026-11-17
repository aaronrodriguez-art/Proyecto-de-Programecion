#ifndef LISTADEPARTAMENTO_H
#define LISTADEPARTAMENTO_H
#include "NodoDepartamento.h"

class ListaDepartamento {
public:
	ListaDepartamento();
	void insertarInicio(Departamento*);
	bool eliminaInicio();
	string toString();
	int cuentaNodos();
	bool listaVacia();
	NodoDepartamento* getPrimero();
	Departamento* buscarPorCodigo(string codigo);
	~ListaDepartamento();
private:
	NodoDepartamento* primero;
	NodoDepartamento* actual;
};

#endif


