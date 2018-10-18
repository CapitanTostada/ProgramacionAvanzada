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
	if (strcmp(m_pszFormato, "24 HORAS") == 0)
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
	else if (strcmp(m_pszFormato,"AM") == 0 || strcmp(m_pszFormato,"PM") == 0) {
		if (ComprobarLimites(1, 12, m_nHoras) && ComprobarLimites(0, 59, m_nMinutos) && ComprobarLimites(0, 59, m_nSegundos))
			return true;
		else
			return false;
	}
	else
		return false;
}


CHora::CHora() {
	m_nHoras = 0;
	m_nMinutos = 0;
	m_nSegundos = 0;
	m_pszFormato = NULL;
}

CHora::~CHora() {
	delete m_pszFormato;
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
	this->~CHora();
	return false;
}

void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char *pszFormato) const {
	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;
	if (pszFormato != 0 && m_pszFormato != 0)
		strcpy_s(pszFormato, 9, m_pszFormato);
	else
		*pszFormato = 0;
}

void VisualizarHora(const CHora& hora) {
	int nHoras, nMinutos, nSegundos;
	char* pszFormato = new char[9]; 

	hora.ObtenerHora(nHoras, nMinutos, nSegundos, pszFormato);
	if (pszFormato != NULL && *pszFormato != 0) {
		cout << "Son las: " << nHoras
			<< ":" << nMinutos
			<< ":" << nSegundos
			<< " " << pszFormato;
	}
	else
		cout << "Ponga una hora";
}