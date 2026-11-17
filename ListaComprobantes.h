#ifndef LISTACOMPROBANTES_H
#define LISTACOMPROBANTES_H
#include "NodoComprobante.h"

class ListaComprobantes {
public:
	ListaComprobantes();
	~ListaComprobantes();
	void insertarInicio(ComprobantePago*);
	void insertarFinal(ComprobantePago*);
	bool eliminaInicio();
	bool eliminarPorCodigo(int codigo);
	ComprobantePago* buscarPorCodigo(int codigo);
	string toString();
	string toStringPorCedula(int cedula);
	int cuentaNodos();
	bool listaVacia();
	NodoComprobante* getPrimero();
private:
	NodoComprobante* primero;
	NodoComprobante* actual;
};

#endif
