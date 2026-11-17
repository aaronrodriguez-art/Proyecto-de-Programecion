#include "ArchivoDepartamento.h"

ArchivoDepartamento::ArchivoDepartamento() {
	
}

ArchivoDepartamento::~ArchivoDepartamento() {
	
}

bool ArchivoDepartamento::guardarDepartamento (ListaDepartamento * lista) {
	ofstream archivo("departamentos.txt");
	if (!archivo.is_open()) {
		return false;
	}
	NodoDepartamento* actual = lista->getPrimero();
	
	while (actual != NULL) {
		Departamento* d = actual->getInfo();
		
		archivo << d->getCodigo() << endl;
		archivo << d->getNombre() << endl;
		archivo << d->getPuesto()->cuentaNodos() << endl;
		
		NodoPuesto* puestoActual = d->getPuesto()->getPrimero();
		
		while (puestoActual != NULL) {
			Puesto* p = puestoActual->getInfo();
			
			archivo << p->getCodigo() << endl;
			archivo << p->getNombre() << endl;
			
			puestoActual = puestoActual->getSig();
		}
		actual = actual->getSig();
	}
	archivo.flush();
	bool correcto = archivo.good();
	archivo.close();
	
	return correcto && !archivo.fail();
	
}

void ArchivoDepartamento::cargarDepartamento(ListaDepartamento* lista) {
	ifstream archivo("departamentos.txt");
	
	if (!archivo.is_open()) {
		return;
	}
	
	string codigo;
	string nombre;
	int cantidadPuestos;
	

	while (getline(archivo, codigo)) {
		if (!getline(archivo, nombre)) {
			break;
		}
		
		if (!(archivo >> cantidadPuestos)) {
			break;
		}
		
		archivo.ignore(10000, '\n');
		
		Departamento* d = new Departamento(nombre, codigo);
	
	for (int i = 0; i < cantidadPuestos; i++) {
		string codigoPuesto;
		string nombrePuesto;
		
		if (!getline(archivo, codigoPuesto) ||
			!getline(archivo, nombrePuesto)) {
			delete d;
			return;
		}
			
			Puesto* p = new Puesto(nombrePuesto, codigoPuesto);
			d->insertarPuesto(p);
	}
	
	lista->insertarInicio(d);
}
	archivo.close();

}
