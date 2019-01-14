
#include "CCliente.h"

using namespace std;

// PREGUNTA 8: AgregarContrato de CCliente

void CCliente::AgregarContrato(const CContrato & contrato)
{
	m_Contratos.push_back(contrato);
}



// PREGUNTA 5: operator<< para resolver: cout << unCliente

ostream& operator<<(ostream& os, CCliente& c)
{
	os << "Nombre: "<< c.m_Nombre << endl;
	for (int i=0; i<c.m_Contratos.size();i++)
		os << c.m_Contratos[i] << endl;
	return os;
}



// PREGUNTA 9: total += seguros[i]

CCliente:: operator long() const
{
	long numero=0;
	for (int i = 0; i<m_Contratos.size(); i++)
	{
		numero += 1;
	}
		
	return numero;
}