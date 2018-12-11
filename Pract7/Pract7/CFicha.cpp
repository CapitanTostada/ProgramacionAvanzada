#include <iostream>
#include "CFicha.h"

using namespace std;

//constructor
CFicha::CFicha(const string& sNombre, int nEdad, int nHoras, int nMinutos, int nSegundos, const string& sFormato):
	m_sNombre(sNombre), m_nEdad(nEdad), m_horaNacio(nHoras, nMinutos, nSegundos, sFormato) {}


void CFicha::AsignarNombre(const string& sNombre)
{
	m_sNombre=sNombre;	
}

string CFicha::ObtenerNombre() const
{
	return (m_sNombre);
}

void CFicha::AsignarEdad(int nEdad)
{
	m_nEdad=nEdad;
}

int CFicha::ObtenerEdad() const
{
	return(m_nEdad);

}

bool CFicha::AsignarNacio(int nHoras, int nMinutos, int nSegundos, const string &sFormato)
{
	return m_horaNacio.AsignarHora(nHoras, nMinutos, nSegundos, sFormato);
}

CHora CFicha::ObtenerNacio() const
{
	return(m_horaNacio);
}

void CFicha::visualizar()	
{
	int hora, minuto, segundo;
	string formato;
	m_horaNacio.ObtenerHora(hora, minuto, segundo, formato);
	cout << "Nombre: " << m_sNombre << endl;
	cout << "Edad: " << m_nEdad << endl;
	cout << "Hora: "<< hora << ":" << minuto << ":" << segundo << "--" << formato << endl;
}

