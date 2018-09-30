#include <iostream>
#include <vector>
#include "funciones.h"
using namespace std;

int main() {
	MatFloat matriz;
	matriz.nFilas = 2;
	matriz.nColumnas = 2;
	opciones seleccion;
	int opcion;
	bool salir = false;

	do {
		cout << "Introduce el numero de la opcion deseada: \n"
			<< "\n\t 1. Construir: selecciona el tamaño de la matriz"
			<< "\n\t 2. Introducir: introduce los valores dentro de la matriz"
			<< "\n\t 3. Imprimir: muestra los valores que tiene la matriz"
			<< "\n\t 4. Salir: sale del programa"
			<< "\n Introduce la opcion deseada: ";
		opcion = comprobarEntrada();
		
	} while (opcion > 4 && opcion < 0);
	seleccion = opciones(--opcion);

	matriz.ppMatrizF = ConstruirMatriz(matriz.nFilas, matriz.nColumnas);

	while (salir == false) {
		switch (seleccion) {
			case Construir:
				cout << "\n Introduzca el numero de filas y columnas \n"
					 << " Filas: ";
				matriz.nFilas = comprobarEntrada();
				cout << " Columnas: ";
				matriz.nColumnas = comprobarEntrada();
				matriz.ppMatrizF = ConstruirMatriz(matriz.nFilas, matriz.nColumnas);
				break;
			case Introducir:
				IntroducirDatos(&matriz);
				break;

			case Imprimir:
				Mostrar(matriz);
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
			}while (opcion > 4 && opcion < 0);
		}
	}
}