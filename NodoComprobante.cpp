#include "NodoComprobante.h"

NodoComprobante::NodoComprobante(ComprobantePago* c, NodoComprobante* s) {
	info = c;
	sig = s;
}

NodoComprobante::~NodoComprobante() {
	
	delete info;
}

void NodoComprobante::setInfo(ComprobantePago* c) { info = c; }
ComprobantePago* NodoComprobante::getInfo() { return info; }
void NodoComprobante::setSig(NodoComprobante* s) { sig = s; }
NodoComprobante* NodoComprobante::getSig() { return sig; }

string NodoComprobante::toStringNodoComprobante() {
	return info->toString();
}
