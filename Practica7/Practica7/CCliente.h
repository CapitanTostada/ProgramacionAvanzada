#if !defined( _CCLIENTE_H_ )
#define _CCLIENTE_H_
#include <iostream>
#include "CFicha.h"
#include "MemoryManager.h"
using namespace std;

class CCliente : public CFicha
{
private:
	string m_sDNI;

public:
	//constructor
	CCliente(const string& sNombre=" ", int nEdad=0, int nHoras=12, int nMinutos=0, int nSegundos=0, const string& sFormato="AM",  const string& sDNI=NULL);

	void SetDNI(const string& sDNI){m_sDNI=sDNI;}	
	void visualizar();
	CCliente *clonar();
	~CCliente();
};

#endif