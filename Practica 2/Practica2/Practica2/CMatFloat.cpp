#include <vector>
#include <iostream>
#include "utils.h"
using namespace std;

class CMatFloat {
private:
	vector<vector<float>> m_ppDatosF;
	int m_nFilas;
	int m_nColumnas;

public:
	CMatFloat() {
		Iniciar();
		m_nFilas = 0;
		m_nColumnas = 0;
	}

	//Devuelve true si no existe y false si existe
	bool existe() {
		return m_ppDatosF.empty();
	}

	void Iniciar() {
		m_ppDatosF.clear();
	}

	void CrearMatriz(int nFilas, int nColumnas) {
		m_ppDatosF.resize(nFilas, vector<float>(nColumnas));
	}

	void Introducir() {
		if (!this->existe()) {
			cout << "Introduzca los valores de la matriz pulsando enter despues de cada uno\n";
			for (int i = 0; i < m_ppDatosF.size(); i++) {
				cout << "Fila " << i + 1 << ": \n";
				for (int j = 0; j < m_ppDatosF[i].size(); j++)
					m_ppDatosF[i][j] = comprobarEntrada();
			}
		}
		else
			cout << "La matriz no está inicializada";
	}

	void Mostrar() {
		if (!this->existe()) {
			for (int i = 0; i < m_ppDatosF.size(); i++) {
				cout << '\n';
				for (int j = 0; j < m_ppDatosF[i].size(); j++)
					cout << m_ppDatosF[i][j] << ' ';
			}
		}
		else
			cout << "La matriz no está inicializada";
	}

};