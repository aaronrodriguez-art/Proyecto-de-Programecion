#include "NodoEmpleado.h"

NodoEmpleado::NodoEmpleado(Empleado*  e, NodoEmpleado* s) {
	info = e;
	sig = s;
}
NodoEmpleado:: ~NodoEmpleado() {
	cout << "Se ha destruido un NodoEmpleado" << endl;
}
void NodoEmpleado::setInfo(Empleado* e) { info = e; }
Empleado*  NodoEmpleado::getInfo() { return info; }
void NodoEmpleado::setSig(NodoEmpleado* s) { sig = s; }
NodoEmpleado* NodoEmpleado::getSig() { return sig; }

string NodoEmpleado::toStringNodoEmpleado() {
	return  info->toString();
}


