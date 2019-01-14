#include <iostream>
#include <string>
#include "CFicha.h"
#include "CEmpleado.h"
#include "CCliente.h"
#include "CRegistroDiario.h"
#include "CHora.h"
#include "utils.h"
using namespace std;

CFicha *leerPersona(int tipo);

int main ()
{
	char Menu[][100]={"Introducir empleado", "Introducir cliente", "Buscar por nombre", "Mostrar registro diario", 
		"Mostrar empleados", "Copia de seguridad del registro diario", "Restaurar copia de seguridad", "Salir"};

	int sel=0, flag;
	string Nombre;
	CRegistroDiario RegistroDiario;
	CRegistroDiario copia_registro;

	while (sel!=8)
	{
		utils::CUtils::CrearMenu(Menu, 8);
		flag=0;
		cout << "Introduzca opcion\n";
		if (!utils::CUtils::LeerDato(sel))
			return 0;
		system("cls");

		switch (sel)
		{
		case 1:
			if(RegistroDiario.AgregarPersona(leerPersona(1)))
				cout << "Empleado agregado" << endl;
			break;
		case 2:
			if (RegistroDiario.AgregarPersona(leerPersona(0)))
				cout << "Cliente agregado" << endl;
			break;
		case 3:
			int i;
			i=0;
			if (RegistroDiario.RegistroVacio())
				cout << "Registro Vacio" << endl;
			else
			{
				Nombre=RegistroDiario[0]->ObtenerNombre();
				cout << "Introduzca el nombre de la persona" << endl;
				utils::CUtils::LeerDato(Nombre);
				while (1)
				{
					if(RegistroDiario[i]==NULL || i==(RegistroDiario.GetNumElementosMax()-1))
					{
						cout <<"No se encontro el nombre" << endl;
						break;
					}
				
					else if (RegistroDiario[i]->ObtenerNombre() == Nombre)	//OJO
					{
						cout << Nombre << " se encuentra en el registro" << endl;
						if (RegistroDiario.EsEmpleado(RegistroDiario[i]))
							cout << Nombre << " es un empleado" << endl;
						else
							cout << Nombre << " es un cliente" << endl;
						break;
					}
					i++;
				}
			}
			break;
		case 4:
			if (RegistroDiario.RegistroVacio())
				cout << "Registro Vacio" << endl;
			else
				RegistroDiario.VisualizarRegistro();
			break;
		case 5:
			if (RegistroDiario.RegistroVacio())
				cout << "Registro Vacio" << endl;
			else
				RegistroDiario.VisualizarEmpleados();
			break;
		case 6:
			if (RegistroDiario.RegistroVacio())
				cout << "Registro Vacio" << endl;
			else
			{
				copia_registro=RegistroDiario;
				cout << "Copia de seguridad realizada" << endl;
			}
			break;
		case 7:
			if (!copia_registro.RegistroVacio())
			{
				for (i=0; i<RegistroDiario.GetNumElementosMax(); i++)
					delete [] RegistroDiario[i];
				RegistroDiario=copia_registro;	
				cout << "Copia restaurada con exito" << endl;
			}
			else
				cout << "No existe copia de seguridad" << endl;
			break;
		case 8:
			break;	

		default:
			cout << "Orden incorrecta" << endl;
			break;
		}	
	}
	return 0;
}


CFicha *leerPersona(int tipo)
{
	CFicha *persona;
	string nombre, Formato, Categoria, DNI;
	int Edad, Horas, Minutos, Segundos, Antiguedad;

	cout << "Introduzca nombre" << endl;
	utils::CUtils::LeerDato(nombre);

	cout << "Introduzca edad" << endl;
	utils::CUtils::LeerDato(Edad);

	cout << "Introduzca Hora: HH:MM:SS-FF" << endl;
	utils::CUtils::LeerDato(Horas);
	utils::CUtils::LeerDato(Minutos);
	utils::CUtils::LeerDato(Segundos);
	utils::CUtils::LeerDato(Formato);

	if (tipo==1)
	{
		cout << "Introduzca Categoria" << endl;
		utils::CUtils::LeerDato(Categoria);
		cout << "Introduzca Antiguedad" << endl;
		utils::CUtils::LeerDato(Antiguedad);
		persona = new CEmpleado(nombre, Edad, Horas, Minutos, Segundos, Formato, Categoria, Antiguedad);
	}
	else
	{
		cout << "Introduzca DNI" << endl;
		utils::CUtils::LeerDato(DNI);
		persona = new CCliente(nombre, Edad, Horas, Minutos, Segundos, Formato, DNI);
	}
	return persona;
}