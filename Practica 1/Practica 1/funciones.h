#include <vector>
using namespace std;

vector<vector<float>> ConstruirMatriz(int nFilas  = 2, int nColumnas = 2);

struct MatFloat {
	int nFilas;
	int nColumnas;
	vector<vector<float>> ppMatrizF;
};

void Mostrar(MatFloat mOrigen);

enum opciones {
	Construir,
	Introducir,
	Imprimir,
	Salir
};
