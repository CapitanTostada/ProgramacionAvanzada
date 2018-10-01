#include <vector>
using namespace std;

#ifndef CMATFLOAT_H
#define CMATFLOAT_H

class CMatFloat {
private:
	vector<vector<float>> m_ppDatosF;
	int m_nFilas;
	int m_nColumnas;
public:
	bool existe();
	void Iniciar();
	void CrearMatriz(int nFilas=1, int nColumnas=1);
	void Introducir();
	void Mostrar();
};
#endif 