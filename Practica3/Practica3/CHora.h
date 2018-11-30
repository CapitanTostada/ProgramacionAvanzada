#pragma once
#include <iostream>
#include <string>
using namespace std;

class CHora {
private:
	int m_nHoras;
	int m_nMinutos;
	int m_nSegundos;
	string m_pszFormato;

	bool AsignarFormato(string pszFormato);
	bool Formato24() const;

public:
	bool EsHoraCorrecta() const;
	CHora(int nHora = 0, int nMinutos = 0, int nSegundos = 0, string cad = NULL);
	CHora(const CHora& hora);
	~CHora();
	bool AsignarHora(int nHoras, int nMinutos, int nSegundos, char *pszFormato);
	void ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char *pszFormato) const;
	CHora& operator =(CHora* obj);
};

void VisualizarHora(const CHora& hora);
void SubMenu();
int Menu();
