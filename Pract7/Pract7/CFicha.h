#if !defined( _CFICHA_H_ )
#define _CFICHA_H_
#include <string>
#include "CHora.h"
#include <iostream>
using namespace std;

class CFicha
{
private:
	string m_sNombre;
	int m_nEdad;
	CHora m_horaNacio;

public:
	CFicha(const string& sNombre=" ", int nEdad=0, int nHoras=12, int nMinutos=0, int nSegundos=0, const string& sFormato="AM");
	void AsignarNombre(const string& sNombre);
	string ObtenerNombre() const;
	void AsignarEdad(int nEdad);
	int ObtenerEdad() const;
	bool AsignarNacio(int nHoras, int nMinutos, int nSegundos, const string &sFormato);
	CHora ObtenerNacio() const;
	virtual void visualizar();
	virtual CFicha *clonar()=0;
	virtual ~CFicha(){}
};

#endif


