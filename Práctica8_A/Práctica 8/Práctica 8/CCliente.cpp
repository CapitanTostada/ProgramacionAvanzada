#include "CCliente.h"
#include <iostream>
using namespace std;

// PREGUNTA 8: AgregarContrato de CCliente

void CCliente::AgregarContrato(const CContrato & contrato)
{
	m_Contratos.AgregarObjeto(contrato);
}



// PREGUNTA 5: operator<< para resolver: cout << unCliente

ostream& operator<<(ostream& os, CCliente& c)
{
	os << "Nombre: "<< c.m_Nombre << endl;
	c.m_Contratos.Restart();
	while (c.m_Contratos.TieneMas())
		os << c.m_Contratos.GetActual() << endl;
	return os;
}



// PREGUNTA 9: total += seguros[i]

CCliente:: operator long() const
{
	long numero=0;
	m_Contratos.Restart();
	while (m_Contratos.TieneMas())
	{
		numero += 1;
		m_Contratos.GetActual();
	}
		
	return numero;
}