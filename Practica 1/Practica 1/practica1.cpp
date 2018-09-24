#include <iostream>
#include <vector>
#include "funciones.h"
using namespace std;

int main() {
	int nColumnas = 3;
	int nFilas = 2;
	vector<vector<float>> matriz;
	int i,j;

	matriz = ConstruirMatriz(nFilas,nColumnas);
	for (i = 0; i < matriz.size(); i++) {
		for (j = 0; j < matriz[i].size(); j++)
			cout << matriz[i][j] << '\n';
	}

}