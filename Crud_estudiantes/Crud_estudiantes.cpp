#include "Estudiantes.h"
#include <iostream>


using namespace std;


int main() {


	string carnet, nombres, apellidos, direccion, email, fecha_nacimiento;
	int idestudiante = 0, telefono = 0, genero = 0;


	Estudiantes2 l = Estudiantes2(idestudiante,carnet,nombres,apellidos,direccion,telefono, email, fecha_nacimiento, genero);
	l.crear();
	l.leer();
	l.modificar();
	l.eliminar();
	l.menu();

	};