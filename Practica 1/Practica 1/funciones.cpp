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

void IntroducirDatos(MatFloat *pDestino) {
	cout << "Introduzca los valores de la matriz pulsando enter despues de cada uno\n";
	for (int i = 0; i < pDestino->ppMatrizF.size(); i++) {
		cout << "Fila " << i+1 << ": \n";
		for (int j = 0; j < pDestino->ppMatrizF[i].size(); j++)
			pDestino->ppMatrizF[i][j] = comprobarEntrada();
	}
}

void Mostrar(MatFloat mOrigen) {
	for (int i = 0; i < mOrigen.ppMatrizF.size(); i++) {
		cout << '\n';
		for (int j = 0; j < mOrigen.ppMatrizF[i].size(); j++)
			cout << mOrigen.ppMatrizF[i][j] << ' ';
	}
}

int comprobarEntrada() {
	int error;
	int num;

	do {
		cin >> num;
		error = cin.rdstate() & ios::failbit;
		if (error) {
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cout << "\nIntroduce un numero entero: ";
		}
	} while (error);
	cin.ignore(numeric_limits<int>::max(), '\n');
	return num;
}