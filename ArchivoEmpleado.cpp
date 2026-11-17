#include "ArchivoEmpleado.h"

static void limpiar(string& linea) {
	if (!linea.empty() && linea[linea.size() - 1] == '\r') {
		linea.erase(linea.size() - 1);
	}
}

static int aEntero(string texto) {
	istringstream ss(texto);
	int valor = 0;
	ss >> valor;
	return valor;
}

ArchivoEmpleado::ArchivoEmpleado() {
	this->nombreArchivo = "empleados.txt";
}

ArchivoEmpleado::ArchivoEmpleado(string nombreArchivo) {
	this->nombreArchivo = nombreArchivo;
}

ArchivoEmpleado::~ArchivoEmpleado() {
	
}

// Formato: una linea por dato.
// Primero el tipo (1 = medico, 2 = enfermero, 3 = administracion), luego cedula, nombre y codigo,
// y despues los datos propios de cada tipo (los si/no se guardan como 1 o 0).
bool ArchivoEmpleado::guardar(ListaEmpleado* empleados) {
	ofstream archivo(nombreArchivo.c_str());
	if (!archivo.is_open()) {
		return false;
	}
	
	NodoEmpleado* nodo = empleados->getPrimero();
	while (nodo != NULL) {
		Empleado* e = nodo->getInfo();
		
		medico* m = dynamic_cast<medico*>(e);
		enfermero* en = dynamic_cast<enfermero*>(e);
		administracion* a = dynamic_cast<administracion*>(e);
		
		if (m != NULL) {
			archivo << 1 << endl;
		} else if (en != NULL) {
			archivo << 2 << endl;
		} else if (a != NULL) {
			archivo << 3 << endl;
		} else {
			nodo = nodo->getSig();
			continue;
		}
		
		archivo << e->getCedula() << endl;
		archivo << e->getNombre() << endl;
		archivo << e->getCodigo() << endl;
		
		if (m != NULL) {
			archivo << m->getEspecialidad() << endl;
			archivo << m->getAnosExperiencia() << endl;
			archivo << m->getTurnoGuardia() << endl;
		} else if (en != NULL) {
			archivo << en->getAreaAsignada() << endl;
			archivo << (en->getEstaGuardia() ? 1 : 0) << endl;
		} else {
			archivo << a->getDepartamento() << endl;
			archivo << (a->getAccesoFinanciero() ? 1 : 0) << endl;
		}
		nodo = nodo->getSig();
	}
	archivo.close();
	return true;
}

// Devuelve cuantos empleados se cargaron
int ArchivoEmpleado::cargar(ListaEmpleado* empleados) {
	ifstream archivo(nombreArchivo.c_str());
	if (!archivo.is_open()) {
		return 0;
	}
	
	int cargados = 0;
	string tipo, cedula, nombre, codigo, dato1, dato2, dato3;
	
	while (getline(archivo, tipo)) {
		limpiar(tipo);
		if (tipo.empty()) {
			continue;
		}
		if (!getline(archivo, cedula) || !getline(archivo, nombre) || !getline(archivo, codigo)) {
			break;
		}
		limpiar(cedula); limpiar(nombre); limpiar(codigo);
		
		int t = aEntero(tipo);
		if (t == 1) {
			if (!getline(archivo, dato1) || !getline(archivo, dato2) || !getline(archivo, dato3)) {
				break;
			}
			limpiar(dato1); limpiar(dato2); limpiar(dato3);
			empleados->insertarFinal(new medico(aEntero(cedula), nombre, aEntero(codigo), dato1, aEntero(dato2), dato3));
			cargados++;
		} else if (t == 2) {
			if (!getline(archivo, dato1) || !getline(archivo, dato2)) {
				break;
			}
			limpiar(dato1); limpiar(dato2);
			empleados->insertarFinal(new enfermero(aEntero(cedula), nombre, aEntero(codigo), dato1, aEntero(dato2) == 1));
			cargados++;
		} else if (t == 3) {
			if (!getline(archivo, dato1) || !getline(archivo, dato2)) {
				break;
			}
			limpiar(dato1); limpiar(dato2);
			empleados->insertarFinal(new administracion(aEntero(cedula), nombre, aEntero(codigo), dato1, aEntero(dato2) == 1));
			cargados++;
		} else {
			break; // tipo desconocido, el archivo esta danado
		}
	}
	archivo.close();
	return cargados;
}
