#include <vector>
using namespace std;

class CMatFloat {
private:
	vector<vector<float>> m_ppDatosF;
	int m_nFilas;
	int m_nColumnas;
public:
	CMatFloat() {}
	void Iniciar();
	void CrearMatriz(int nFilas=1, int nColumnas=1);
	void Introducir();
	void Mostrar();
	bool existe();
};
