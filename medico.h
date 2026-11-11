#ifndef MEDICO_H
#define MEDICO_H
#include "Empleado.h"

class medico: public Empleado {
public:
	medico();
	medico(int cedula, string nombre, int codigo, string especialidad, int anosExperiencia, string turnoGuardia );
	
	~medico();
	
	void setEspecialidad (string especialidad);
	void setAnosExperiencia (int anosExperiencia);
	void setTurnoGuardia (string turnoGuardia);
	
	string getEspecialidad();
	int getAnosExperiencia();
	string getTurnoGuardia();
	string toString() override;
	double calcularSalario() override;
	
private:
	string *especialidad;
	int *anosExperiencia;
	string *turnoGuardia;
	
};

#endif
