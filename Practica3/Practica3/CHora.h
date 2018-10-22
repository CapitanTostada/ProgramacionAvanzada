#pragma once
#include <iostream>

class CHora {
private:
	int m_nHoras;
	int m_nMinutos;
	int m_nSegundos;
	char *m_pszFormato;

	bool AsignarFormato(char *pszFormato);
	bool Formato24() const;

public:
	bool EsHoraCorrecta() const;
	CHora(int nHora = 0, int nMinutos = 0, int nSegundos = 0, char* cad = NULL);
	CHora(const CHora& hora);
	~CHora();
	bool AsignarHora(int nHoras, int nMinutos, int nSegundos, char *pszFormato);
	void ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char *pszFormato) const;
	CHora& operator =(CHora* obj);
};

void VisualizarHora(const CHora& hora);
void SubMenu();
int Menu();
