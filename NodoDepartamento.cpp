#include "NodoDepartamento.h"


NodoDepartamento::NodoDepartamento (Departamento* d, NodoDepartamento * s) {
	info = d;
	sig = s;
}

NodoDepartamento::~NodoDepartamento ( ) {
}

void NodoDepartamento::setInfo (Departamento* d) {
	info = d;
}

Departamento * NodoDepartamento::getInfo ( ) {
	return info;
}

void NodoDepartamento::setSig (NodoDepartamento* s) {
	sig = s;
}

NodoDepartamento * NodoDepartamento::getSig ( ) {
	return sig;
}

string NodoDepartamento::toStringNodoDepartamento ( ) {
	return info -> toString();
}

