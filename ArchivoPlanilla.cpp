#include "ArchivoPlanilla.h"

// ---- funciones auxiliares (solo se usan en este archivo) ----

// Le quita el \r del final a una linea (pasa cuando el archivo viene de Windows)
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

static double aDecimal(string texto) {
	istringstream ss(texto);
	double valor = 0;
	ss >> valor;
	return valor;
}

// ---- clase ----

ArchivoPlanilla::ArchivoPlanilla() {
	this->nombreArchivo = "planilla.txt";
}

ArchivoPlanilla::ArchivoPlanilla(string nombreArchivo) {
	this->nombreArchivo = nombreArchivo;
}

ArchivoPlanilla::~ArchivoPlanilla() {
	
}

// Formato: cada comprobante ocupa 8 lineas codigo, periodo, cedula del empleado, codigo del departamento ("-" si no tiene), salario bruto, horas extra, bono nocturno, deducciones
bool ArchivoPlanilla::guardar(ListaComprobantes* comprobantes) {
	ofstream archivo(nombreArchivo.c_str());
	if (!archivo.is_open()) {
		return false;
	}
	archivo << fixed << setprecision(2);
	
	NodoComprobante* nodo = comprobantes->getPrimero();
	while (nodo != NULL) {
		ComprobantePago* c = nodo->getInfo();
		
		int cedula = (c->getEmpleado() != NULL) ? c->getEmpleado()->getCedula() : 0;
		string codDep = (c->getDepartamento() != NULL) ? c->getDepartamento()->getCodigo() : "-";
		
		archivo << c->getCodigo() << endl;
		archivo << c->getPeriodo() << endl;
		archivo << cedula << endl;
		archivo << codDep << endl;
		archivo << c->getSalarioBruto() << endl;
		archivo << c->getMontoHorasExtra() << endl;
		archivo << c->getBonoNocturno() << endl;
		archivo << c->getDeducciones() << endl;
		
		nodo = nodo->getSig();
	}
	archivo.close();
	return true;
}

// Devuelve cuantos comprobantes se cargaron.
// El comprobante guarda punteros a un Empleado y a un Departamento, y esos no se
// guardan en este archivo, solo su cedula y su codigo. Por eso los empleados y los
// departamentos tienen que estar cargados ANTES de llamar a esta funcion.
int ArchivoPlanilla::cargar(ListaComprobantes* comprobantes, ListaEmpleado* empleados, ListaDepartamento* departamentos) {
	ifstream archivo(nombreArchivo.c_str());
	if (!archivo.is_open()) {
		return 0;
	}
	
	int cargados = 0;
	string codigo, periodo, cedula, codDep, bruto, extra, bono, deducciones;
	
	while (getline(archivo, codigo)) {
		if (!getline(archivo, periodo) || !getline(archivo, cedula) || !getline(archivo, codDep)
			|| !getline(archivo, bruto) || !getline(archivo, extra) || !getline(archivo, bono)
			|| !getline(archivo, deducciones)) {
			break;
		}
		limpiar(codigo); limpiar(periodo); limpiar(cedula); limpiar(codDep);
		limpiar(bruto); limpiar(extra); limpiar(bono); limpiar(deducciones);
		
		Empleado* e = empleados->buscarPorCedula(aEntero(cedula));
		if (e == NULL) {
			continue; // el empleado ya no existe, se salta este comprobante
		}
		Departamento* d = NULL;
		if (codDep != "-") {
			d = departamentos->buscarPorCodigo(codDep);
		}
		
		comprobantes->insertarFinal(new ComprobantePago(aEntero(codigo), periodo, e, d,
			aDecimal(bruto), aDecimal(extra), aDecimal(bono), aDecimal(deducciones)));
		cargados++;
	}
	archivo.close();
	return cargados;
}



