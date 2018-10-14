#include "CHora.h"
#include <cstdio>
#include <iostream>
#include "../../Practica 2/Practica2/Practica2/utils.h"
using namespace std;

int main() {
	CHora Fecha;
	Lista seleccion;
	int opcion;
	bool salir = false;
	char* pszFormato = NULL;
	int nHoras, nMinutos, nSegundos;

	do {
		cout << "Menu de opciones: "
			<< "\n\t 1. Introducir hora: introduce la hora"
			<< "\n\t 2. Visualizar hora: muestra la hora"
			<< "\n\t 3. Salir: sale del programa"
			<< "\nIntroduce la opcion deseada: ";
		opcion = comprobarEntrada();
	} while (opcion > 3 && opcion < 0);
	seleccion = Lista(--opcion);

	while (salir == false) {
		switch (seleccion) {
		case Poner:
			cout << "\nPor favor introduzca la hora:";
			nHoras = comprobarEntrada();
			cout << "\nPor favor introduzca la minutos:";
			nMinutos = comprobarEntrada();
			cout << "\nPor favor introduzca la segundos:";
			nSegundos = comprobarEntrada();
			cout << "\nPor favor introduzca el formato(AM, PM, 24 HORAS):";
			pszFormato = LeerCadena(9);
			Fecha.AsignarHora(nHoras, nMinutos, nSegundos, pszFormato);
			break;
		case Visualizar:
			VisualizarHora(Fecha);
			break;
		case Terminar:
			salir = true;
			break;
		default:
			break;
		}
		if (!salir) {
			do {
				cout << "\nIntroduzca la opcion que quiere hacer a continuacion: ";
				opcion = comprobarEntrada();
				seleccion = Lista(--opcion);
			} while (opcion > 3 && opcion < 0);
		}
	}
}
