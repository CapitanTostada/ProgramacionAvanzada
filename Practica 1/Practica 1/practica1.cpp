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

	cout << "Introduce el numero de la opcion deseada: \n"
		<< "\n\t 1. Construir: selecciona el tamaño de la matriz"
		<< "\n\t 2. Introducir: introduce los valores dentro de la matriz"
		<< "\n\t 3. Imprimir: muestra los valores que tiene la matriz"
		<< "\n\t 4. Salir: sale del programa"
		<< "\n Introduce la opcion deseada: ";
	cin >> opcion;
	seleccion = opciones(--opcion);

	while (salir == false) {
		switch (seleccion) {
			case Construir:
				cout << "\n Introduzca el numero de filas y columnas \n"
					 << " Filas: ";
				cin >> matriz.nFilas;
				cout << " Columnas: ";
				cin >> matriz.nColumnas;
				matriz.ppMatrizF = ConstruirMatriz(matriz.nFilas, matriz.nColumnas);
				break;
			case Introducir:
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
			cout << "\n Introduzca la opcion que quiere hacer a continuacion: ";
			cin >> opcion;
			seleccion = opciones(--opcion);
		}
	}
}