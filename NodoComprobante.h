#ifndef NODOCOMPROBANTE_H
#define NODOCOMPROBANTE_H
#include "ComprobantePago.h"

class NodoComprobante {
public:
	NodoComprobante(ComprobantePago*, NodoComprobante*);
	~NodoComprobante();
	void setInfo(ComprobantePago*);
	ComprobantePago* getInfo();
	void setSig(NodoComprobante*);
	NodoComprobante* getSig();
	string toStringNodoComprobante();
private:
	ComprobantePago* info;
	NodoComprobante* sig;
};

#endif
