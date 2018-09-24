#include <vector>
#include <iostream>
using namespace std;

vector<vector<float>> ConstruirMatriz(int nFilas, int nColumnas) {
	vector<vector<float>> v_zeros;
	int i,j;
	try{
		v_zeros.resize(nFilas, vector<float>(nColumnas));
	}
	catch (...){
		cout << "Error al crear el vector";
	}
	return v_zeros;
}

void Mostrar(MatFloat mOrigen) {

}