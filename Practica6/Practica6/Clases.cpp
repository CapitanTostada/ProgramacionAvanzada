#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Clases.h"

ostream& operator<<(ostream& os, const CMonomio& mono) {
	os << showpos;
	if (!mono.GetExp())
		os << mono.GetCoef();
	else {
		if (mono.GetCoef() != 1)
			os << mono.GetCoef();
		os << noshowpos;
		if (mono.GetExp() == 1)
			os << 'x';
		else
			os << "x^" << mono.GetExp();
	}
	os << noshowpos;
	return os;
}

//********************Clase CPolinomio********************

CPolinomio& CPolinomio::operator<<(const CMonomio& mono)
{
	CTermino *aux;
	CTermino *aux2=NULL;
	aux = m_pCabecera;

	//Si el coeficiente del monomio es 0 no se añade
	if (mono.GetCoef() == 0)
		return *this;

	//Si la lista está vacía
	if (aux == NULL)
	{
		CTermino *nTermino = new (nothrow) CTermino;
		if (nTermino == NULL)
		{
			cout << "Memoria insuficiente\n";
			return *this;
		}

		nTermino->SetMono(mono); //pSig ya está a NULL
		m_pCabecera = nTermino;
		return *this;
	}

	//Buscamos si hay algún elemento con el mismo exponente y lo sumamos
	do
	{
		if (aux->GetExp() == mono.GetExp())
		{
			if (aux->GetCoef() + mono.GetCoef() == 0)
			{
				if (aux == m_pCabecera)
					m_pCabecera = aux->GetSig();
				else
					aux2->SetSig(aux->GetSig());
			}
			else
				aux->SetCoef(aux->GetCoef() + mono.GetCoef());

			return *this;
		}
		else
			aux2 = aux;
		aux = aux->GetSig();

	} while (aux != NULL);

	//Al no haber ningún elemento con ese exponente, lo añadimos
	CTermino *nTermino = new (nothrow) CTermino;
	if (nTermino == NULL)
	{
		cout << "Memoria insuficiente\n";
		return *this;
	}

	nTermino->SetMono(mono);
	aux = m_pCabecera;

	do
	{
		if (nTermino->GetExp() > aux->GetExp())
		{
			nTermino->SetSig(aux);
			if (aux == m_pCabecera)
				m_pCabecera = nTermino;
			else
				aux2->SetSig(nTermino);

			return *this;
		}
		else
			aux2 = aux;
		aux = aux->GetSig();
		if (aux == NULL)
		{
			nTermino->SetSig(aux);
			aux2->SetSig(nTermino);
			return *this;
		}

	} while (aux != NULL);

	cout << "Error, no se ha sumado, ni tampoco insertado" << endl;
	return *this;
}

CPolinomio& CPolinomio::operator=(const CPolinomio& poli)
{

	//Liberar memoria dinámica previa del objeto destino, cómo??
	CTermino *aux;
	aux = poli.m_pCabecera;
	do
	{
		*this << aux->GetMono();		
		//this->operator<<(poli.m_pCabecera->GetMono());
		aux = aux->GetSig();

	} while (aux != NULL);

	return *this;
}

CPolinomio::CPolinomio(const CPolinomio& polinomio)
{
	m_pCabecera = NULL;
	*this = polinomio;	
}

CPolinomio::CPolinomio(double Coef, int Exp)
{
	if (Coef == 0)
		m_pCabecera = NULL;
	else
	{
		m_pCabecera = NULL;
		CMonomio mono(Coef, Exp);
		*this << mono;
	}
}

CPolinomio::CPolinomio(vector<CMonomio> monomio)
{
	int i;
	this->m_pCabecera = NULL;
	for (i = 0; i < monomio.size(); i++)
		*this << monomio[i];
}

CPolinomio::CPolinomio(const CMonomio& monomio)
{
	if (monomio.GetCoef() == 0)
		m_pCabecera = NULL;
	else
		m_pCabecera = NULL;
	*this << monomio;
}

CPolinomio::~CPolinomio()
{
	CTermino *aux;
	if (m_pCabecera != NULL)
	{
		aux = m_pCabecera->GetSig();
		do
		{
			delete m_pCabecera;
			m_pCabecera = aux;
			if (aux != NULL)
				aux = m_pCabecera->GetSig();

		} while (aux != NULL);
	}
}

void CPolinomio::MostrarPoli(ostream& os) const
{
	const CTermino* pPos = m_pCabecera;

	if (pPos)
		do
		{
			os << pPos->GetMono() << ' ';
			pPos = pPos->GetSig();
		} while (pPos);
	else
		os << "0 ";
}

ostream& operator <<(ostream& os, const CPolinomio& Poli)
{
	Poli.MostrarPoli(os);
	return os;
}

int CPolinomio::Grado() const
{
	if (m_pCabecera != NULL)
		return(m_pCabecera->GetExp());
	else
		return 0;
}


bool CPolinomio::operator==(const CPolinomio& P2)
{
	if (this->m_pCabecera == NULL || P2.m_pCabecera == NULL)
	{
		cout << "Error ==, Polinomio vacio" << endl;
		return false;
	}
	else if (this->Grado() == P2.Grado())
		return true;
	else
		return false;
}

bool CPolinomio::operator<(const CPolinomio& P2)
{
	if (this->m_pCabecera == NULL || P2.m_pCabecera == NULL)
	{
		cout << "Error ==, Polinomio vacio" << endl;
		return false;
	}
	else if (this->Grado() < P2.Grado())
		return true;
	else
		return false;
}

bool CPolinomio::operator>(const CPolinomio& P2)
{
	if (this->m_pCabecera == NULL || P2.m_pCabecera == NULL)
	{
		cout << "Error ==, Polinomio vacio" << endl;
		return false;
	}
	else if (this->Grado() > P2.Grado())
		return true;
	else
		return false;
}

CPolinomio& CPolinomio::operator-()
{
	if (this->m_pCabecera == NULL)
	{
		cout << "Polinomio Vacio" << endl;
		return *this;
	}
	CTermino *aux;
	aux = this->m_pCabecera;
	do
	{
		aux->SetCoef(-aux->GetCoef());
		aux = aux->GetSig();
	} while (aux != NULL);
	return *this;
}

const CPolinomio CPolinomio::operator+(const CPolinomio &P)
{
	CTermino *aux;
	aux = P.m_pCabecera;
	do
	{
		*this << aux->GetMono();
		aux = aux->GetSig();

	} while (aux != NULL);
	return *this;
}

const CPolinomio CPolinomio::operator-(const CPolinomio &P)
{
	CTermino *aux;
	aux = P.m_pCabecera;
	do
	{
		*this << -(aux->GetMono());
		aux = aux->GetSig();

	} while (aux != NULL);
	return *this;
}

CPolinomio& CPolinomio::operator+=(const CPolinomio& P)
{
	return *this = *this + P;

}

CPolinomio& CPolinomio::operator-=(const CPolinomio& P)
{
	CPolinomio aux, aux2;
	aux = *this - P;
	*this = aux2;
	return *this = aux;
}

double CPolinomio::operator[](int exp) const
{
	if (this->m_pCabecera == NULL)
	{
		cout << "Polinomio Vacio" << endl;
		return 0;
	}
	CTermino *aux;
	aux = this->m_pCabecera;
	do
	{
		if (exp == this->m_pCabecera->GetExp())
			return this->m_pCabecera->GetCoef();
		else
			aux = aux->GetSig();
	} while (aux != NULL);
	return 0;
}

double CPolinomio::operator()(double x) const
{
	if (this->m_pCabecera == NULL)
	{
		cout << "Polinomio Vacio" << endl;
		return 0;
	}
	CTermino *aux;
	aux = this->m_pCabecera;
	double valor = 0;
	do
	{
		valor = valor + aux->GetCoef()*(pow(x, aux->GetExp()));
		aux = aux->GetSig();
	} while (aux != NULL);

	return valor;

}