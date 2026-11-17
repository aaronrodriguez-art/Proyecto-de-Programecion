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
Empleado::~Empleado(){
	delete cedula;
	delete nombre;
	delete codigo;
}

double Empleado::calcularDeducciones(double salarioBruto) {
		
		double ccss = salarioBruto * 0.1083;
		double renta = 0;
		
		if (salarioBruto > 4727000) {
			renta = (1347000 - 918000) * 0.10
				+ (2364000 - 1347000) * 0.15
				+ (4727000 - 2364000) * 0.20
				+ (salarioBruto - 4727000) * 0.25;
		}
		else if (salarioBruto > 2364000) {
			renta = (1347000 - 918000) * 0.10
				+ (2364000 - 1347000) * 0.15
				+ (salarioBruto - 2364000) * 0.20;
		}
		else if (salarioBruto > 1347000) {
			renta = (1347000 - 918000) * 0.10
				+ (salarioBruto - 1347000) * 0.15;
		}
		else if (salarioBruto > 918000) {
			renta = (salarioBruto - 918000) * 0.10;
		}
		
		return ccss + renta;
	}
	
	
