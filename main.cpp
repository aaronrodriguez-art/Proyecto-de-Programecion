#include <iostream>
#include <iomanip>
#include <sstream>
#include "GestionDepartamento.h"
#include "GestionEmpleado.h"
#include "GestionPlanilla.h"
#include "ArchivoPlanilla.h"
#include "medico.h"
#include "enfermero.h"
#include "administracion.h"

using namespace std;


string leerTexto(string mensaje) {
	string texto;
	cout << mensaje;
	getline(cin, texto);
	return texto;
}

int leerEntero(string mensaje) {
	while (true) {
		string texto = leerTexto(mensaje);
		if (!cin) {
			return 0; 
		}
		istringstream ss(texto);
		int valor;
		char sobra;
		if ((ss >> valor) && !(ss >> sobra)) {
			return valor;
		}
		cout << "Dato invalido, escriba un numero entero." << endl;
	}
}

// Pide un decimal mayor o igual a 0
double leerDecimal(string mensaje) {
	while (true) {
		string texto = leerTexto(mensaje);
		if (!cin) {
			return 0;
		}
		istringstream ss(texto);
		double valor;
		char sobra;
		if ((ss >> valor) && !(ss >> sobra) && valor >= 0) {
			return valor;
		}
		cout << "Dato invalido, escriba un numero mayor o igual a 0." << endl;
	}
}

bool leerSiNo(string mensaje) {
	while (true) {
		string texto = leerTexto(mensaje + " (s/n): ");
		if (!cin) {
			return false;
		}
		if (texto == "s" || texto == "S") { return true; }
		if (texto == "n" || texto == "N") { return false; }
		cout << "Escriba s o n." << endl;
	}
}

void mostrarMenu() {
	cout << endl;
	cout << "========= PLANILLA HOSPITALARIA =========" << endl;
	cout << " 1. Registrar departamento" << endl;
	cout << " 2. Mostrar departamentos" << endl;
	cout << " 3. Registrar empleado" << endl;
	cout << " 4. Mostrar empleados" << endl;
	cout << " 5. Generar comprobante de pago" << endl;
	cout << " 6. Mostrar todos los comprobantes" << endl;
	cout << " 7. Mostrar comprobantes de un empleado" << endl;
	cout << " 8. Total de la planilla por periodo" << endl;
	cout << " 9. Eliminar comprobante" << endl;
	cout << "10. Guardar datos" << endl;
	cout << " 0. Salir (guarda antes de cerrar)" << endl;
	cout << "=========================================" << endl;
}



bool registrarDepartamento(GestionDepartamento& gestionDep) {
	
	string codigo = leerTexto("Codigo del departamento: ");
	
	if (codigo.find_first_not_of(" \t") == string::npos) {
		cout << "El codigo no puede estar vacio." << endl;
		return false;
	}
	
	if (gestionDep.buscarDepartamento(codigo) != NULL) {
		cout << "Ya existe un departamento con ese codigo." << endl;
		return false;
	}
	
	string nombre = leerTexto("Nombre del departamento: ");
	
	if (nombre.find_first_not_of(" \t") == string::npos) {
		cout << "El nombre del departamento no puede estar vacio." << endl;
		return false;
	}
	
	Departamento* d = new Departamento(nombre, codigo);
	
	while (leerSiNo("Desea agregar un puesto")) {
		
		string codPuesto = leerTexto("  Codigo del puesto: ");
		
		if (codPuesto.find_first_not_of(" \t") == string::npos) {
			cout << "El codigo del puesto no puede estar vacio." << endl;
			delete d;
			return false;
		}
		
		// Buscar si el codigo del puesto ya existe
		NodoPuesto* aux = d->getPuesto()->getPrimero();
		
		bool repetido = false;
		
		while (aux != NULL) {
			if (aux->getInfo()->getCodigo() == codPuesto) {
				repetido = true;
				break;
			}
			
			aux = aux->getSig();
		}
		
		if (repetido) {
			cout << "Ya existe un puesto con ese codigo en este departamento." << endl;
			cout << "Intente nuevamente." << endl;
			continue;
		}
		
		string nomPuesto = leerTexto("  Nombre del puesto: ");
		
		if (nomPuesto.find_first_not_of(" \t") == string::npos) {
			cout << "El nombre del puesto no puede estar vacio." << endl;
			delete d;
			return false;
		}
		
		d->insertarPuesto(new Puesto(nomPuesto, codPuesto));
	}
	
	gestionDep.registrarDepartamento(d);
	
	cout << "Departamento registrado." << endl;
	
	return true;
}


bool registrarEmpleado(GestionEmpleado& gestionEmp) {
	cout << "Tipo de empleado:" << endl;
	cout << "  1. Medico" << endl;
	cout << "  2. Enfermero" << endl;
	cout << "  3. Administracion" << endl;
	
	int tipo = leerEntero("Opcion: ");
	
	if (tipo < 1 || tipo > 3) {
		cout << "Tipo invalido." << endl;
		return false;
	}
	
	int cedula = leerEntero("Cedula: ");
	
	if (cedula <= 0) {
		cout << "La cedula debe ser mayor que 0." << endl;
		return false;
	}
	
	if (gestionEmp.buscarEmpleado(cedula) != NULL) {
		cout << "Ya existe un empleado con esa cedula." << endl;
		return false;
	}
	
	string nombre = leerTexto("Nombre: ");
	
	if (nombre.find_first_not_of(" \t") == string::npos) {
		cout << "El nombre no puede estar vacio." << endl;
		return false;
	}
	
	int codigo = leerEntero("Codigo de empleado: ");
	
	if (codigo <= 0) {
		cout << "El codigo debe ser mayor que 0." << endl;
		return false;
	}
	
	Empleado* e = NULL;
	
	if (tipo == 1) {
		string especialidad = leerTexto("Especialidad: ");
		int anos = leerEntero("Anos de experiencia: ");
		
		if (anos < 0) {
			cout << "Los anos de experiencia no pueden ser negativos." << endl;
			return false;
		}
		
		string turno = leerTexto("Turno de guardia (por ejemplo Nocturno): ");
		
		e = new medico(cedula, nombre, codigo, especialidad, anos, turno);
		
	} else if (tipo == 2) {
		string area = leerTexto("Area asignada: ");
		bool guardia = leerSiNo("Esta en guardia");
		
		e = new enfermero(cedula, nombre, codigo, area, guardia);
		
	} else {
		string depto = leerTexto("Departamento: ");
		bool acceso = leerSiNo("Tiene acceso financiero");
		
		e = new administracion(cedula, nombre, codigo, depto, acceso);
	}
	
	gestionEmp.registrarEmpleado(e);
	
	cout << "Empleado registrado." << endl;
	
	return true;
}



bool generarComprobante(GestionEmpleado& gestionEmp, GestionDepartamento& gestionDep, GestionPlanilla& gestionPlan) {
	
	int cedula = leerEntero("Cedula del empleado: ");
	
	Empleado* e = gestionEmp.buscarEmpleado(cedula);
	
	if (e == NULL) {
		cout << "No existe un empleado con esa cedula." << endl;
		return false;
	}
	
	string periodo = leerTexto("Periodo (por ejemplo Noviembre 2026): ");
	
	if (periodo.find_first_not_of(" \t") == string::npos) {
		cout << "El periodo no puede estar vacio." << endl;
		return false;
	}
	
	if (gestionPlan.existeComprobante(cedula, periodo)) {
		cout << "Ese empleado ya tiene un comprobante en ese periodo." << endl;
		return false;
	}
	
	Departamento* d = NULL;
	
	string codDep = leerTexto("Codigo del departamento (Enter si no aplica): ");
	
	// find_first... verifica que no existan espacios o vacios
	if (codDep.find_first_not_of(" \t") != string::npos) {
		d = gestionDep.buscarDepartamento(codDep);
		
		if (d == NULL) {
			cout << "No existe ese departamento." << endl;
			return false;
		}
	}
	
	double horasExtra = leerDecimal("Horas extra trabajadas: ");
	
	if (horasExtra < 0) {
		cout << "Las horas extra no pueden ser negativas." << endl;
		return false;
	}
	
	double bono = leerDecimal("Bono nocturno/guardia (monto, 0 si no hay): ");
	
	if (bono < 0) {
		cout << "El bono nocturno no puede ser negativo." << endl;
		return false;
	}
	
	ComprobantePago* c = gestionPlan.generarComprobante(
														periodo, e, d, horasExtra, bono
														);
	
	if (c == NULL) {
		cout << "No se pudo generar un comprobante." << endl;
		return false;
	}
	
	cout << endl << c->toString() << endl;
	
	return true;
}

void mostrarComprobantes(GestionPlanilla& gestionPlan) {
	if (gestionPlan.cantidadComprobantes() == 0) {
		cout << "No hay comprobantes registrados." << endl;
		return;
	}
	cout << gestionPlan.mostrarComprobantes();
}

void mostrarComprobantesEmpleado(GestionPlanilla& gestionPlan) {
	int cedula = leerEntero("Cedula del empleado: ");
	string texto = gestionPlan.mostrarPorCedula(cedula);
	if (texto.empty()) {
		cout << "Ese empleado no tiene comprobantes." << endl;
	} else {
		cout << texto;
	}
}

void totalPeriodo(GestionPlanilla& gestionPlan) {
	string periodo = leerTexto("Periodo: ");
	cout << "Total neto a pagar en " << periodo << ": " << gestionPlan.totalNetoPeriodo(periodo) << endl;
}

bool eliminarComprobante(GestionPlanilla& gestionPlan) {
	int codigo = leerEntero("Codigo del comprobante a eliminar: ");
	if (gestionPlan.eliminarComprobante(codigo)) {
		cout << "Comprobante eliminado." << endl;
		return true;
	}
		cout << "No existe un comprobante con ese codigo." << endl;
		return false;
	}

void guardarTodo(GestionDepartamento& gestionDep, GestionEmpleado& gestionEmp, GestionPlanilla& gestionPlan) {
	bool okDep = gestionDep.guardarDepartamento();
	bool okEmp = gestionEmp.guardarEmpleados();
	bool okPlan = gestionPlan.guardarPlanilla();
	if (okDep && okEmp && okPlan) {
		cout << "Datos guardados." << endl;
	} else {
		cout << "No se pudo guardar alguno de los archivos." << endl;
	}
}

// ================= main =================

int main() {
	cout << fixed << setprecision(2);
	
	GestionDepartamento gestionDep;
	GestionEmpleado gestionEmp;
	GestionPlanilla gestionPlan(new ArchivoPlanilla("planilla.txt"));
	
	// El orden importa: los comprobantes apuntan a empleados y departamentos,
	// asi que esos se cargan primero.
	gestionDep.cargarDepartamento();
	gestionEmp.cargarEmpleados();
	gestionPlan.cargarPlanilla(gestionEmp.getEmpleados(), gestionDep.getDepartamentos());
	
	int opcion = -1;
	while (opcion != 0 && cin) {
		mostrarMenu();
		opcion = leerEntero("Opcion: ");
		cout << endl;
		
		switch (opcion) {
			case 1: 
			if (registrarDepartamento(gestionDep)) {
			guardarTodo(gestionDep, gestionEmp, gestionPlan);
			}
			break;
			
			case 2: cout << gestionDep.mostrarDepartamento(); break;
			case 3: 
			if (registrarEmpleado(gestionEmp)) { 
			guardarTodo(gestionDep, gestionEmp, gestionPlan);
			}
			break;
			case 4: cout << gestionEmp.mostrarEmpleados(); break;
			case 5:
			if (generarComprobante(gestionEmp, gestionDep, gestionPlan)) {
			guardarTodo(gestionDep, gestionEmp, gestionPlan);
			}
			break;
			case 6: mostrarComprobantes(gestionPlan); break;
			case 7: mostrarComprobantesEmpleado(gestionPlan); break;
			case 8: totalPeriodo(gestionPlan); break;
			case 9:
			if (eliminarComprobante(gestionPlan)) {
			guardarTodo(gestionDep, gestionEmp, gestionPlan);
			}
			break;
			case 10: guardarTodo(gestionDep, gestionEmp, gestionPlan); break;
			case 0: break;
			default: cout << "Opcion invalida." << endl;
		}
	}
	
	guardarTodo(gestionDep, gestionEmp, gestionPlan);
	cout << "Hasta luego." << endl;
	return 0;
}
