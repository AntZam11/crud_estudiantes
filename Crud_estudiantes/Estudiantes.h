#pragma once
#include <iostream>
#include "ConexionDB.h"
#include "mysql.h"
#include <string>
#include "Crud_estudiantes.h"

using namespace std;
class Estudiantes  {

protected: string carnet, nombres, apellidos, direccion, email, fecha_nacimiento;
		 int idestudiante, telefono, genero;




protected:
	Estudiantes() {
	}

	Estudiantes (int id, string car, string nom, string ape, string dir, int tel, string mail,string fech, int gen){

		idestudiante = id;
		carnet = car;
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		email = mail;
		fecha_nacimiento = fech;
		genero = gen;
	}
};

class Estudiantes2 : Estudiantes {
public:
	Estudiantes2() {

	}

	Estudiantes2(int id, string car, string nom, string ape, string dir, int tel, string mail,
		string fech, int gen) : Estudiantes(id, car, nom, ape, dir, tel, mail, fech, gen) {
	}

	void setId_estudiantes(int id) { idestudiante = id; }
	void setCarnet(string car) { carnet = car; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setEmail(string mail) { email = mail; }
	void setFecha_nacimiento(string fech) { fecha_nacimiento = fech; }
	void setGenero(int gen) { genero = gen; }

	int getId_estudiantes() { return idestudiante; }
	string getCarnet() { return carnet; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getEmail() { return email; }
	string getFecha_nacimiento() { return fecha_nacimiento; }
	int getGenero() { return genero; }

	void crear() {
		int q_estado;
		ConexionDB cn = ConexionDB();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string id = to_string(idestudiante);
			string tel = to_string(telefono);
			string gen = to_string(genero);
			string insert = "INSERT INTO estudiantes(id_estudiante,carnet,nombres,apellidos,direccion,telefono,email,fecha_nacimiento,genero)VALUES("+id+",'" + carnet + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + tel + ",'" + email + "','" + fecha_nacimiento + "'," + gen + ");";
			
			const char* i = insert.c_str();                               
			q_estado = mysql_query(cn.getconectar(), i);                        
			if (!q_estado) {
				cout << "Ingreso Exitoso..." << endl;

			}
			else {
				cout << "xxxxError al Ingresar Informacion xxxx" << endl;
			}

		}
		else {
			cout << "xxxxError al Ingresar Informacion xxxx" << endl;
		}
		cn.cerrar_conexion();

	}

	void leer() {
		int q_estado;
		ConexionDB cn = ConexionDB();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string estudiante = "select * from estudiantes";          							
			const char* c = estudiante.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "--------------Estudiantes-------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << ";" << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << endl;
				}

			}
		}
		else {
			cout << "xxxxError al Ingresar Informacion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void modificar() {
		int q_estado;
		ConexionDB cn = ConexionDB();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string id = to_string(idestudiante);
			string tel = to_string(telefono);
			string gen = to_string(genero);
			string update = "UPDATE estudiantes SET idestudiantes = " + id + ",carnet='" + carnet + "',nombres='" + nombres + "',apellidos='" + apellidos + "',direccion='" + direccion + "',telefono=" + tel + ",email='" + email + "',fecha_nacimiento='" + fecha_nacimiento + "',genero=" + gen + " where  id_estudiantes = " + id + ";";
			const char* i = update.c_str();                               //esta linea ejecuta el insert into.
			q_estado = mysql_query(cn.getconectar(), i);                         //esta linea ejecuta el insert into.
			if (!q_estado) {
				cout << "Ingreso Exitoso..." << endl;

			}
			else {
				cout << "xxxxError al Ingresar Informacion xxxx" << endl;
			}

		}
		else {
			cout << "xxxxError al Ingresar Informacion xxxx" << endl;
		}
		cn.cerrar_conexion();

	}

	void eliminar() {
		int q_estado;
		ConexionDB cn = ConexionDB();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string id = to_string(idestudiante);
			string delet = "DELETE from estudiantes where  idestudiantes = " + id + " ;";
			const char* i = delet.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso..." << endl;

			}
			else {
				cout << "xxxxError al Ingresar Informacion xxxx" << endl;
			}

		}
		else {
			cout << "xxxxError al Ingresar Informacion xxxx" << endl;
		}
		cn.cerrar_conexion();

	}
	void menu() {
		int opc;
		do {
			system("cls");
			cout << "----------MENU---------\n";
			cout << "\n 1. Ingresar Estudiante " << endl;
			cout << "\n 2. Modificar " << endl;
			cout << "\n 3. eliminar" << endl;
			cout << "\n 4. ver " << endl;
			cout << "\n ----Ingrese una Opcion----" << endl;
			cin >> opc;

			switch (opc) {
			case 1:
				crear();
				cout << "Ingrese Id Estudiante:\n";
				cin >> idestudiante;
				cout << "Ingrese Carnet de Estudiante:\n";
				cin >> carnet;
				cout << "Ingrese nombres de Estudiantes:\n";
				cin >> nombres;
				cout << "Ingrese Apellidos:\n";
				cin >> apellidos;
				cout << "Ingrese Direccion:\n";
				cin >> direccion;
				cout << "Ingresar Telefono:\n";
				cin >> telefono;
				cout << "Ingrese Email:\n";
				cin >> email;
				cout << "Ingrese Fecha de Nacimiento:\n";
				cin >> fecha_nacimiento;
				cout << "Ingrese Genero:\n";
				cin >> genero;
				
				break;


			case 2:
				modificar();
				cout << "Ingrese Id Estudiante:\n";
				cin >> idestudiante;
				cout << "Ingrese Carnet de Estudiante:\n";
				cin >> carnet;
				cout << "Ingrese nombres de Estudiantes:\n";
				cin >> nombres;
				cout << "Ingrese Apellidos:\n";
				cin >> apellidos;
				cout << "Ingrese Direccion:\n";
				cin >> direccion;
				cout << "Ingresar Telefono:\n";
				cin >> telefono;
				cout << "Ingrese Email:\n";
				cin >> email;
				cout << "Ingrese Fecha de Nacimiento:\n";
				cin >> fecha_nacimiento;
				cout << "Ingrese Genero:\n";
				cin >> genero;

				break;

			case 3:
				eliminar();
				cout << "Id de registro que desea eliminar:\n" << endl;
				cin >> idestudiante;

				break;

			case 4:

				leer();

				break;
			}

			system("pause");
			break;
		} while (opc <= 4);

		menu();

		 }
	
	};
