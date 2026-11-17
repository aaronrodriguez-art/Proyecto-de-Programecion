#ifndef GESTIONPLANILLA_H
#define GESTIONPLANILLA_H
#include <sstream>
#include <iomanip>
#include "IAlmacenPlanilla.h"

class GestionPlanilla {
public:
	// Recibe el almacen ya creado y se queda con el: lo borra en el destructor
	GestionPlanilla(IAlmacenPlanilla* almacen);
	~GestionPlanilla();
	
	bool existeComprobante(int cedula, string periodo);
	ComprobantePago* generarComprobante(string periodo, Empleado* empleado, Departamento* departamento,
		double horasExtra, double bonoNocturno);
	ComprobantePago* buscarComprobante(int codigo);
	bool eliminarComprobante(int codigo);
	
	string mostrarComprobantes();
	string mostrarPorCedula(int cedula);
	double totalNetoPeriodo(string periodo);
	int cantidadComprobantes();
	
	bool guardarPlanilla();
	int cargarPlanilla(ListaEmpleado* empleados, ListaDepartamento* departamentos);
	
private:
	int siguienteCodigo();
	
	ListaComprobantes* comprobantes;
	IAlmacenPlanilla* almacen;
	// guarda el siguiente codigo disponible para los comprobantes
	int proximoCodigo;
};

#endif
