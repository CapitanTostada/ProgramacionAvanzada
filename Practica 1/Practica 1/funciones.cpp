#include <vector>
#include <iostream>
#include "funciones.h"
using namespace std;

vector<vector<float>> ConstruirMatriz(int nFilas, int nColumnas) {
	vector<vector<float>> v_zeros;
	try{
		v_zeros.resize(nFilas, vector<float>(nColumnas));
	}
	catch (exception e){
		cout << "Error al crear el vector: " << e.what();
	}
	return v_zeros;
}

void IntroducirDatos(MatFloat pDestino) {

}

void Mostrar(MatFloat mOrigen) {
	for (int i = 0; i < mOrigen.ppMatrizF.size(); i++) {
		cout << '\n';
		for (int j = 0; j < mOrigen.ppMatrizF[i].size(); j++)
			cout << mOrigen.ppMatrizF[i][j] << ' ';
	}
}