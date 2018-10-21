#include "CHora.h"
#include <cstdio>
#include <iostream>
#include "../../Practica 2/Practica2/Practica2/utils.h"
using namespace std;

int main() {
	CHora Fecha;
	Lista seleccion;
	int opcion;
	bool salir = false, correcta = false;
	char* pszFormato = NULL;
	int nHoras, nMinutos, nSegundos;
	int num;
	CHora* p = NULL;
	opcion = Menu();
	seleccion = Lista(--opcion);

	while (salir == false) {
		switch (seleccion) {
		case Local:
			SubMenu();
			break;
		case Dinamico:
			p = new CHora;
			break;
		case Copia: {
			if (p == NULL)
				cout << "Cree antes el objeto dinamicamente\n";
			else
				CHora fecha2(*p);
			break;
		}
		case Asignacion: {
			CHora fecha3 = *p;
			break;
		}
		case Terminar:
			delete p;
			salir = true;
			break;
		default:
			break;
		}
		if (!salir) {
			do {
				opcion = Menu();
				seleccion = Lista(--opcion);
			} while (opcion > 5 && opcion < 0);
		}
	}
}
