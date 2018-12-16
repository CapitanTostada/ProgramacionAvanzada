#include <iostream>
#include <string>
#include "CHora.h"
using namespace std;

bool CHora::Formato24() const
{
	if (m_pszFormato == "24")
		return true;
	else
		return false;
}

bool CHora::EsHoraCorrecta() const
{
	bool formatoCorrecto, horaCorrecta, minutoCorrecto, segundoCorrecto;

	formatoCorrecto=(m_pszFormato=="24") || (m_pszFormato=="PM") || (m_pszFormato=="AM");
	if(Formato24())
		horaCorrecta = (m_nHoras<=24) && (m_nHoras>=0);
	else
		horaCorrecta = (m_nHoras<=12) && (m_nHoras>=0);

	minutoCorrecto = (m_nMinutos<=59) && (m_nMinutos>=0);
	segundoCorrecto = (m_nSegundos<=59) || (m_nSegundos>=0);

	return formatoCorrecto && horaCorrecta && minutoCorrecto && segundoCorrecto;
}

//Constructor
CHora::CHora(int nHoras, int nMinutos, int nSegundos, const string pszFormato)
{
	m_nHoras=nHoras;
	m_nMinutos=nMinutos;
	m_nSegundos=nSegundos;
	m_pszFormato = pszFormato;
}

//Constructor copia
CHora::CHora(const CHora& hora) :
	m_nHoras(hora.m_nHoras), m_nMinutos(hora.m_nMinutos), m_nSegundos(hora.m_nSegundos), m_pszFormato(hora.m_pszFormato) {}


bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, const string pszFormato) 
{
	m_nHoras=nHoras;
	m_nMinutos=nMinutos;
	m_nSegundos=nSegundos;
	m_pszFormato = pszFormato;

	return (EsHoraCorrecta());
}

void CHora::ObtenerHora (int& nHoras, int& nMinutos, int& nSegundos, string& pszFormato) const
{
	int i;
	nHoras=m_nHoras;
	nMinutos=m_nMinutos;
	nSegundos=m_nSegundos;
	pszFormato = m_pszFormato;	
}