#include <vector>
#include <iostream>
#include "utils.h"
#include "CMatFloat.h"
using namespace std;

//Devuelve true si no existe y false si existe
bool CMatFloat::existe() {
	return m_ppDatosF.empty();
}

void CMatFloat::Iniciar() {
	m_ppDatosF.clear();
}

void CMatFloat::CrearMatriz(int nFilas, int nColumnas) {
	m_ppDatosF.clear();
	m_ppDatosF.resize(nFilas, vector<float>(nColumnas));
}

void CMatFloat::Introducir() {
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

void CMatFloat::Mostrar() {
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
