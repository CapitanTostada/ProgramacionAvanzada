#include <vector>
using namespace std;

vector<vector<float>> ConstruirMatriz(int nFilas, int nColumnas);
void Mostrar(MatFloat mOrigen);

struct MatFloat {
	int nFilas;
	int nColumnas;
	vector<vector<float>> ppMatrizF;
};
