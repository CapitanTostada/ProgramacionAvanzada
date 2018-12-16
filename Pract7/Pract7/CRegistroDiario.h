#include <iostream>
#include "CEmpleado.h"
#include "CCliente.h"
using namespace std;

class CRegistroDiario
{
private:
	int nElementosMax;
	CFicha **personas; 

public:
	CRegistroDiario(int ElementosMax=10);
	~CRegistroDiario();
	CRegistroDiario(const CRegistroDiario& RegistroDiario);
	CRegistroDiario& operator=(const CRegistroDiario& RegistroDiario);
	bool AgregarPersona(CFicha *Ficha);
	void VisualizarRegistro();
	static bool EsEmpleado(CFicha *personas);
	void VisualizarEmpleados();
	CFicha *operator[](int i) const;
	bool RegistroLleno();
	bool RegistroVacio();
	int GetNumElementosMax(){return nElementosMax;}
};