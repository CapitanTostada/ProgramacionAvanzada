#include "CHora.h"
#include <cstdio>
#include <iostream>
#include <locale>
#include "../../Practica 2/Practica2/Practica2/utils.h"
using namespace std;

bool CHora::AsignarFormato(char* pszFormato) {
	if (pszFormato != NULL && strlen(pszFormato) < 10) {
		delete m_pszFormato;
		m_pszFormato = new char[9];

		converMayus(pszFormato);

		if (pszFormato != 0 && m_pszFormato != 0)
			strcpy_s(m_pszFormato, 9, pszFormato);
		return true;
	}
	else
		return false;
}

bool CHora::Formato24() const {
	if (m_pszFormato == "24 HORAS")
		return true;
	return false;
}

bool CHora::EsHoraCorrecta() const {
	if (Formato24() == true) {
		if (ComprobarLimites(0, 23, m_nHoras) && ComprobarLimites(0, 59, m_nMinutos) && ComprobarLimites(0, 59, m_nSegundos))
			return true;
		else
			return false;
	}
	else if (m_pszFormato == "AM" || m_pszFormato == "PM") {
		if (ComprobarLimites(1, 12, m_nHoras) && ComprobarLimites(0, 59, m_nMinutos) && ComprobarLimites(0, 59, m_nSegundos))
			return true;
		else
			return false;
	}
	else
		return false;
}


CHora::CHora() {
	Iniciar();
}

CHora::~CHora() {
	Destruir();
}

void CHora::Iniciar() {
	m_nHoras = 0;
	m_nMinutos = 0;
	m_nSegundos = 0;
	m_pszFormato = NULL;
}

bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, char *pszFormato) {
	if (AsignarFormato(pszFormato)) {
		m_nHoras = nHoras;
		m_nMinutos = nMinutos;
		m_nSegundos = nSegundos;
		if (EsHoraCorrecta())
			return true;
	}
	Iniciar();
	return false;
}

void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char *pszFormato) const {
	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;
	if(pszFormato != 0 && m_pszFormato != 0)
		strcpy_s(pszFormato, 9, m_pszFormato);
}

void CHora::Destruir() {
	delete m_pszFormato;
	Iniciar();
}

void VisualizarHora(const CHora& hora) {
	int nHoras, nMinutos, nSegundos;
	char* pszFormato = NULL;

	hora.ObtenerHora(nHoras, nMinutos, nSegundos, pszFormato);
	if (pszFormato != NULL) {
		cout << "Son las: " << nHoras
			<< ":" << nMinutos
			<< ":" << nSegundos
			<< " " << pszFormato;
	}
	else
		cout << "Ponga antes una hora";
}