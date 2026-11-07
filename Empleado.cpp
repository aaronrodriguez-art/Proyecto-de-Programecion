#include "Empleado.h"

Empleado::Empleado() {
	
	this->cedula=new int();
	this->nombre=new string();
	this->codigo=new int();

}

Empleado::Empleado(int cedula,string nombre,int codigo){
	
	this->cedula=new int(cedula);
	this->nombre=new string (nombre);
	this->codigo=new int (codigo);
	
}

void Empleado::setCedula(int cedula) {delete this-> cedula; this-> cedula = new int(cedula);}
void Empleado::setNombre(string nombre) {delete this-> nombre; this-> nombre = new string(nombre);}
void Empleado::setCodigo(int codigo) {delete this-> codigo; this-> codigo = new int(codigo);}

int Empleado:: getCedula(){return *cedula; }
string Empleado:: getNombre(){return * nombre; }
int Empleado:: getCodigo(){return *codigo; }

string Empleado::toString(){
	stringstream ss;
	ss << "----------Empleado----------"<<endl;
	ss << "Cedula: " << *cedula << endl;
	ss << "Nombre: " << *nombre << endl;
	ss << "Codigo: " << *codigo << endl;
	
	return ss.str();
	
}
void Empleado::autoGuardar(ofstream& estFile) {
	cout << "    <<Guardando>>" << endl;
	cout << toString() << endl;
	estFile << cedula  << endl
		<< nombre << endl
		<< codigo << endl;
}

Empleado*  Empleado::autoLeer(ifstream& estFile) {
	
	string nombre;
	int cedula,codigo; 
	int tipoEmpleado;//saber cual clase asigna
	
	
	if (!(estFile >> cedula)) { return NULL; }
	if (!(estFile >> nombre)) { return NULL; }
	if (!(estFile >> codigo)) { return NULL; }
	
	cout << "   --Cargando registro" << endl;
	if (tipoEmpleado == 1) { // Es Médico
		string especialidad;
		int anosExperiencia;
		string turnoGuardia;
		
		estFile >> especialidad >> anosExperiencia >> turnoGuardia;
		
		return new medico(cedula, nombre, codigo, especialidad, anosExperiencia, turnoGuardia);
	} 
	else if (tipoEmpleado == 2) { // Es Enfermero
		string areaAsignada;
		bool estaGuardia;
		
		estFile >> areaAsignada >> estaGuardia;
		
		return new enfermero(cedula, nombre, codigo, areaAsignada, estaGuardia);
	} 
	else {//es administracion
		string departamento;
		bool accesoFinanciero;
		
		estFile >> departamento >> accesoFinanciero;
		
		return new administracion(cedula, nombre, codigo, departamento, accesoFinanciero);
	}
}

Empleado::~Empleado(){
	delete cedula;
	delete nombre;
	delete codigo;
}
