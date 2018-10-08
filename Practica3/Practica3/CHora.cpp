#include "CHora.h"
#include <cstdio>
#include <locale>
#include "../../Practica 2/Practica2/Practica2/utils.h"
using namespace std;

class CHora {
private:
	int m_nHoras;
	int m_nMinutos;
	int m_nSegundos;
	char *m_pszFormato;

	bool AsignarFormato(char *pszFormato) {
		int i = 0;
		if (*pszFormato != NULL && strlen(pszFormato) < 10) {
			delete m_pszFormato;
			m_pszFormato = new char[9];
			while (pszFormato[i] != '\0') {
				toupper(pszFormato[i]);
				i++;
			}
			strcpy(m_pszFormato, pszFormato);
			return true;
		}
		else
			return false;

	}
	bool Formato24() const {
		if (m_pszFormato == "24 HORAS")
			return true;
		return false;
	}

protected:
	bool EsHoraCorrecta() const {
		if (Formato24() == true) {
			if (ComprobarLimites(0, 24, m_nHoras) && ComprobarLimites(0, 60, m_nMinutos) && ComprobarLimites(0, 60, m_nSegundos))
				return true;
			else
				return false;
		}
		else if (m_pszFormato == "AM" || m_pszFormato == "PM") {
			if (ComprobarLimites(0, 12, m_nHoras) && ComprobarLimites(0, 60, m_nMinutos) && ComprobarLimites(0, 60, m_nSegundos))
				return true;
			else
				return false;
		}
		else
			return false;
	}

public:
	void Iniciar() {
		m_nHoras = 0;
		m_nMinutos = 0;
		m_nSegundos = 0;
		m_pszFormato = NULL;
	}
	bool AsignarHora(int nHoras, int nMinutos, int nSegundos, char *pszFormato) {
		if (AsignarFormato(pszFormato)) {
			m_nHoras = nHoras;
			m_nMinutos = nMinutos;
			m_nSegundos = nSegundos;
			if (EsHoraCorrecta)
				return true;
		}
		Iniciar();
		return false;
	}
	void ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char *pszFormato) const {
		nHoras = m_nHoras;
		nMinutos = m_nMinutos;
		nSegundos = m_nSegundos;
		strcpy(pszFormato, m_pszFormato);
	}
	void Destruir() {
		delete m_pszFormato;
		Iniciar();
	}
};