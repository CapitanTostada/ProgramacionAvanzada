
#include <iostream>
#include "CIndiceIncorrecto.h"
#include "MemoryManager.h"

using namespace std;

template<class T>
CLista<T>::CLista()
: m_Primero (NULL), m_Actual (NULL), m_Ultimo (NULL)
{
}

template<class T>
CLista<T>::CLista(const T& Obj)
: m_Primero(NULL), m_Actual(NULL), m_Ultimo(NULL)
{
	AgregarObjeto(Obj);
}


template <class T>
CLista<T>::CLista(const CLista<T> &Lista)
{
	*this = Lista;
}



template <class T>
CLista<T>& CLista<T>::operator=(const CLista<T>& Lista)
{
  Vaciar();
  if(!Lista.EstaVacia())
  {
    m_Actual = m_Ultimo = m_Primero = new CNodoLista<T>(Lista.GetPrimero());
    while(Lista.TieneMas())
    {
      m_Actual->SetSigNodo(new CNodoLista<T>(Lista.GetActual()));
      m_Ultimo = m_Actual = m_Actual->GetSigNodo();
    }
  }
  return *this;
}

template <class T>
void CLista<T>::AgregarObjeto(const T& Obj)
{
  if(EstaVacia())
    m_Primero = m_Actual = m_Ultimo = new CNodoLista<T>(Obj);
  else
  {
    m_Ultimo->SetSigNodo(new CNodoLista<T>(Obj));
    m_Ultimo = m_Ultimo->GetSigNodo();
  }
}

template <class T>
T& CLista<T>::GetActual() const
{
  CNodoLista<T> *temp = m_Actual;
  const_cast<CLista<T>*>(this)->m_Actual = m_Actual->GetSigNodo();
  return temp->GetDato();
}

template <class T>
T& CLista<T>::GetPrimero() const
{
  // PREGUNTA 11
  const_cast<CLista<T>*>(this)->m_Actual = m_Primero->GetSigNodo();
  return m_Primero->GetDato();
}


// PREGUNTA 2: operator[] de CLista. Lanza CIndiceIncorrecto.
template <class T>
T& CLista<T>:: operator[](const int& indice)
{
	CNodoLista<T> *auxiliar = m_Primero;
	int elementos;
	for (elementos = 0; auxiliar != NULL; elementos++)
		auxiliar = auxiliar->m_pSigNodo;
	if (indice < 0 || indice >= elementos)
	{
		throw CIndiceIncorrecto::CIndiceIncorrecto();
	}
		
	else
	{
		auxiliar = m_Primero;
		for (elementos = 0; elementos!=indice; elementos++)
			auxiliar = auxiliar->m_pSigNodo;
		return auxiliar->m_Dato;
	}
}



// PREGUNTA 1: CLista<T>::Vaciar

template <class T> void CLista<T>::Vaciar()
{
	CNodoLista<T> *auxiliar1 = m_Primero;
	CNodoLista<T> *auxiliar2 = m_Primero;

	while (auxiliar1 != NULL)
	{
		auxiliar2 = auxiliar1;
		auxiliar1 = auxiliar1->m_pSigNodo;
		delete auxiliar2;	
	}

	m_Primero = NULL;
	m_Actual = NULL;
	m_Ultimo = NULL;
}


template<class T> void CLista<T>::Restart() const
{
  const_cast<CLista *>(this)->m_Actual = m_Primero;
}

template<class T>
CLista<T>::~CLista()
{
  Vaciar();
}
