#if !defined( _CEMPLEADO_H_ )
#define _CEMPLEADO_H_
#include <iostream>
#include <string>
#include "CFicha.h"

class CEmpleado : public CFicha
{
private:
	string m_sCategoria;
	int m_nAntiguedad;

public:
	CEmpleado(const string& sNombre="", int nEdad=0, int nHoras=12, int nMinutos=0, int nSegundos=0, const string& sFormato="AM",  const string& sCategoria="", int nAntiguedad=0);
	//~CEmpleado();
	void SetCategoria(const string& sCategoria){m_sCategoria=sCategoria;}  
	void SetAntiguedad(int nAntiguedad){m_nAntiguedad=nAntiguedad;}
	void visualizar();
	CEmpleado *clonar();
	
};

#endif