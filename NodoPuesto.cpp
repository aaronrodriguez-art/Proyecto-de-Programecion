#include "NodoPuesto.h"

NodoPuesto::NodoPuesto(Puesto* p, NodoPuesto* n) {
	info = p;
	sig = n;
}

NodoPuesto::~NodoPuesto() {
}


void NodoPuesto::setInfo (Puesto* p) {
	info = p;
}

Puesto * NodoPuesto::getInfo ( ) {
	return info;
}

void NodoPuesto::setSig (NodoPuesto* n) {
	sig = n;
}

NodoPuesto * NodoPuesto::getSig ( ) {
	return sig;
}

string NodoPuesto::toStringNodoPuesto ( ) {
	return info -> toString ();
}

