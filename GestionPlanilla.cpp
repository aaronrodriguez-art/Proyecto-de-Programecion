#include "GestionPlanilla.h"

// Horas de trabajo al mes (30 dias x 8 horas) y recargo de las horas extra (tiempo y medio)
static const double HORAS_MES = 240.0;
static const double RECARGO_EXTRA = 1.5;

GestionPlanilla::GestionPlanilla(IAlmacenPlanilla* almacen) {
	this->comprobantes = new ListaComprobantes;
	this->almacen = almacen;
	this->proximoCodigo = 1;
}

GestionPlanilla::~GestionPlanilla() {
	delete comprobantes;
	delete almacen;
}

// pone el proximo codigo disponible el contador para el siguiente
int GestionPlanilla::siguienteCodigo() {
	int codigo = proximoCodigo;
	proximoCodigo++;
	return codigo;
}

bool GestionPlanilla::existeComprobante(int cedula, string periodo) {
	NodoComprobante* nodo = comprobantes->getPrimero();
	while (nodo != NULL) {
		ComprobantePago* c = nodo->getInfo();
		if (c->getEmpleado() != NULL && c->getEmpleado()->getCedula() == cedula
			&& c->getPeriodo() == periodo) {
			return true;
		}
		nodo = nodo->getSig();
	}
	return false;
}

// El salario bruto lo da el empleado, las deducciones son lo que se le quita para llegar a su neto, y las horas extra se pagan a (bruto / 240) x 1.5 por hora.
ComprobantePago* GestionPlanilla::generarComprobante(string periodo, Empleado* empleado, Departamento* departamento,
													 double horasExtra, double bonoNocturno) {
	
	if (empleado == NULL) {
		return NULL;
	}
	
	if (horasExtra < 0) {
		horasExtra = 0;
	}
	
	if (bonoNocturno < 0) {
		bonoNocturno = 0;
	}
	
	// aqui se ejecuta el salario correspondiete al empleado (polimorfismo) 
	double bruto = empleado->calcularSalarioBruto();
	
	double montoExtra = horasExtra * (bruto / HORAS_MES) * RECARGO_EXTRA;
	
	double brutoTotal = bruto + montoExtra + bonoNocturno;
	
	double deducciones = empleado->calcularDeducciones(brutoTotal);
	
	ComprobantePago* c = new ComprobantePago(siguienteCodigo(), periodo, empleado, departamento, bruto,
											 montoExtra, bonoNocturno, deducciones);
	
	comprobantes->insertarFinal(c);
	
	return c;
}

ComprobantePago* GestionPlanilla::buscarComprobante(int codigo) {
	return comprobantes->buscarPorCodigo(codigo);
}

bool GestionPlanilla::eliminarComprobante(int codigo) {
	return comprobantes->eliminarPorCodigo(codigo);
}

string GestionPlanilla::mostrarComprobantes() {
	return comprobantes->toString();
}

string GestionPlanilla::mostrarPorCedula(int cedula) {
	return comprobantes->toStringPorCedula(cedula);
}

double GestionPlanilla::totalNetoPeriodo(string periodo) {
	double total = 0;
	NodoComprobante* nodo = comprobantes->getPrimero();
	while (nodo != NULL) {
		if (nodo->getInfo()->getPeriodo() == periodo) {
			total += nodo->getInfo()->getSalarioNeto();
		}
		nodo = nodo->getSig();
	}
	return total;
}

int GestionPlanilla::cantidadComprobantes() {
	return comprobantes->cuentaNodos();
}


// guarda el proximo codigo para evitar repetir numeros comprobantes ya eliminados
bool GestionPlanilla::guardarPlanilla() {
	
	return almacen->guardar(comprobantes);
}


// carga los comprobantes y calcula el siguiente codigo disponible
int GestionPlanilla::cargarPlanilla(ListaEmpleado* empleados, ListaDepartamento* departamentos) {
	
	int cantidad = almacen->cargar(comprobantes, empleados, departamentos);
	
	NodoComprobante* aux = comprobantes->getPrimero();
	
	while (aux != NULL) {
		
		int codigo = aux->getInfo()->getCodigo();
		
		if (codigo >= proximoCodigo) {
			proximoCodigo = codigo + 1;
		}
		
		aux = aux->getSig();
	}
	
	return cantidad;
}

	
