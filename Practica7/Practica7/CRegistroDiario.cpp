#include "CRegistroDiario.h"

CRegistroDiario::CRegistroDiario(int ElementosMax):nElementosMax(ElementosMax)
{
	int i;
	personas = new CFicha *[nElementosMax];
	if (personas ==NULL)
	{
		cout << "Memoria insuficiente\n"; 
		return;
	}

	for (i=0; i<nElementosMax; i++)
		personas[i]=NULL;
}

CRegistroDiario::~CRegistroDiario()
{
	int i; 
	for (i=0; i<nElementosMax; i++)
		delete [] personas[i];

	delete[] personas; //OJO
}

CRegistroDiario::CRegistroDiario(const CRegistroDiario& RegistroDiario)
{
	int i;
	for (i=0; i<RegistroDiario.nElementosMax; i++)
		if (RegistroDiario.personas[i]=NULL)
			this->personas[i]=RegistroDiario.personas[i]->clonar();
		else
			this->personas[i]=NULL;
}

CRegistroDiario& CRegistroDiario::operator=(const CRegistroDiario& RegistroDiario)
{
	int i;
	for (i=0; i<RegistroDiario.nElementosMax; i++)
		if (RegistroDiario.personas[i]!=NULL)
			this->personas[i]=RegistroDiario.personas[i]->clonar();
		else
			this->personas[i]=NULL;

	return *this;
}

bool CRegistroDiario::AgregarPersona(CFicha *Ficha)
{
	int i=0;
	if (!RegistroLleno())
	{
		while(personas[i]!=NULL || i==nElementosMax)
			i++;
		if (i==nElementosMax)
			return false;
		else{
			personas[i]=Ficha->clonar();
			delete [] Ficha;	//liberar memoria delete []
			return true;
		}
	}
	else{
		cout << "Registro lleno" << endl;
		return false;}
}

void CRegistroDiario::VisualizarRegistro()
{
	int i=0;
	while (personas[i]!=NULL && i<nElementosMax){
		personas[i]->visualizar();
		i++;
	}
}

bool CRegistroDiario::EsEmpleado(CFicha *personas)
{
	if (personas==dynamic_cast<CEmpleado*>(personas)!=0)
		return true;
	else if (personas==dynamic_cast<CCliente*>(personas)!=0)
		return false;
	else{
		cout << "Error al hacer conversión descendente" << endl;
		return false;
	}
}

void CRegistroDiario::VisualizarEmpleados()
{
	int i=0;
	while ( personas[i]!=NULL && i<nElementosMax)
	{
		if (personas[i]==dynamic_cast<CEmpleado*>(personas[i])!=0)
			personas[i]->visualizar();
		i++;
	}
}

CFicha *CRegistroDiario::operator[](int i) const
{
	if (i>=0 && i<nElementosMax)
		return personas[i];
	else{
		cout << "Indice fuera de los limites" << endl;
		return 0;
	}
}

bool CRegistroDiario::RegistroLleno()
{
	if (personas[nElementosMax-1]==NULL)
		return false;
	else
		return true;
}

bool CRegistroDiario::RegistroVacio()
{
	if (personas[0]==NULL)
		return true;
	else
		return false;
}