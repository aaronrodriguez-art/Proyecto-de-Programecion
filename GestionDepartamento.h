#ifndef GESTIONDEPARTAMENTO_H
#define GESTIONDEPARTAMENTO_H
#include "ListaDepartamento.h"
#include "ArchivoDepartamento.h"

class GestionDepartamento {
public:
	GestionDepartamento();
	void registrarDepartamento(Departamento*);
	Departamento* buscarDepartamento(string codigo);
	ListaDepartamento* getDepartamentos();
	string mostrarDepartamento();
	bool guardarDepartamento();
	void cargarDepartamento();
	~GestionDepartamento();
private:
	ListaDepartamento* departamentos;
	ArchivoDepartamento* archivo;
};

#endif

