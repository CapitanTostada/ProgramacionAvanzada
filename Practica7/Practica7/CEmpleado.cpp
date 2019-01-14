#include "CEmpleado.h"

//constructor
CEmpleado::CEmpleado(const string& sNombre, int nEdad, int nHoras, int nMinutos, int nSegundos, const string& sFormato,  
					 const string& sCategoria, int nAntiguedad): CFicha(sNombre, nEdad, nHoras, nMinutos, nSegundos, sFormato),
					 m_sCategoria(sCategoria), m_nAntiguedad(nAntiguedad) {}

void CEmpleado::visualizar()	
{
	CFicha::visualizar();
	cout << "Categoria: " << m_sCategoria << endl;
	cout << "Antiguedad: " << m_nAntiguedad << endl;
	cout << "--" << endl;
}

CEmpleado *CEmpleado::clonar()
{
	return (new CEmpleado(*this));
}
