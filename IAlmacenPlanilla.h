#ifndef IALMACENPLANILLA_H
#define IALMACENPLANILLA_H
#include "ListaComprobantes.h"
#include "ListaEmpleado.h"
#include "ListaDepartamento.h"

// esta interfaz define las operaciones de almacenamiento y ArchivoPlanilla los implementa
class IAlmacenPlanilla {
public:
	
	virtual ~IAlmacenPlanilla() {}
	
	virtual bool guardar(ListaComprobantes* comprobantes) = 0;
	
	virtual int cargar(ListaComprobantes* comprobantes, ListaEmpleado* empleados, ListaDepartamento* departamentos) = 0;
	
};

#endif
