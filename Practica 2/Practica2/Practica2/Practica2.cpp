#include <iostream>
#include "CMatFloat.h"
#include "utils.h"
using namespace std;


int main() {
	CMatFloat matriz;
	opciones seleccion;
	int opcion, nFilas, nColumnas;
	bool salir = false;

	do {
		cout << "Introduce el numero de la opcion deseada: \n"
			<< "\n\t 1. Construir1D: selecciona el numero de filas de la matriz"
			<< "\n\t 2. Construir2D: selecciona el tamaño de la matriz de 2D"
			<< "\n\t 3. Introducir: introduce los valores dentro de la matriz"
			<< "\n\t 4. Imprimir: muestra los valores que tiene la matriz"
			<< "\n\t 5. Salir: sale del programa"
			<< "\n Introduce la opcion deseada: ";
		opcion = comprobarEntrada();

	} while (opcion > 5 && opcion < 0);
	seleccion = opciones(--opcion);
	matriz.Iniciar();

	while (salir == false) {
		switch (seleccion) {
		case Construir1D:
			cout << "\n Introduzca el numero de filas: \n";
			nFilas = comprobarEntrada();
			matriz.CrearMatriz(nFilas);
			break;
		case Construir2D:
			cout << "\n Introduzca el numero de filas y columnas \n"
				<< " Filas: ";
			nFilas = comprobarEntrada();
			cout << " Columnas: ";
			nColumnas = comprobarEntrada();
			matriz.CrearMatriz(nFilas, nColumnas);
			break;
		case Introducir:
			matriz.Introducir();
			break;
		case Imprimir:
			matriz.Mostrar();
			break;
		case Salir:
			salir = true;
			break;
		default:
			break;
		}
		if (!salir) {
			do {
				cout << "\nIntroduzca la opcion que quiere hacer a continuacion: ";
				opcion = comprobarEntrada();
				seleccion = opciones(--opcion);
			} while (opcion > 5 && opcion < 0);
		}
	}
}