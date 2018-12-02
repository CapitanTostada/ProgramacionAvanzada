#include "CCliente.h"

//constructor
CCliente::CCliente(const string& sNombre, int nEdad, int nHoras, int nMinutos, int nSegundos, const string& sFormato,  
				   const string& sDNI): CFicha(sNombre, nEdad, nHoras, nMinutos, nSegundos, sFormato), m_sDNI(sDNI) {}

void CCliente::visualizar()
{
	CFicha::visualizar();
	cout << "DNI: " << m_sDNI << endl;
	cout << "--" << endl;
}

CCliente *CCliente::clonar()
{
	/*CCliente *Cliente;
	Cliente = new(nothrow) CCliente;
	if (Cliente==NULL)
	{
		cout << "Error al reservar memoria" << endl;
		return 0; 
	}

	*Cliente=*this;
	return Cliente; */
	return (new CCliente(*this));
}

CCliente::~CCliente()
{
	//delete [] this; //Duda
}