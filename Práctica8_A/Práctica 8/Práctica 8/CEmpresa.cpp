#if !defined(_EMPRESA_CPP)
#define _EMPRESA_CPP

#include <iostream>
#include "MemoryManager.h"

using namespace std;

template<class T>
CEmpresa<T>::CEmpresa(const CEmpresa<T> &a) {
	m_nElem = 10;
	m_pElem = new T*[m_nElem];

	for (int i = 0; i < m_nElem; i++)
	{
		m_pElem[i] = NULL;
	}
	*this = a;
}

// Operador =
template<class T>
CEmpresa<T>& CEmpresa<T>:: operator=(const CEmpresa<T>& a)
{
	m_nElem = 10;
	for (int i = 0; i < m_nElem; i++)
	{
		delete m_pElem[i];
		m_pElem[i] = NULL;
	}

	for (int i = 0; (i < m_nElem) && (a.m_pElem[i] != NULL); i++)
	{
		m_pElem[i] = new T;
		*m_pElem[i]=*a.m_pElem[i];
	}
	return *this;
}

// Destructor

template<class T>
CEmpresa<T>::~CEmpresa()
{
	for (int i = 0; i < m_nElem; i++)
	{
		delete m_pElem[i];
	}
	delete [] m_pElem;
}

// AgregarElemento

template<class T>
void CEmpresa<T>::AgregarElemento(const T& elem)
{
	int i;
	for (i = 0; i < m_nElem && m_pElem[i]!=NULL; i++);
	m_pElem[i] = new T;
	*m_pElem[i] = elem;
}

// GetElemento

template<class T>
T& CEmpresa<T>::GetElemento(int nElem) const
{
	return *m_pElem[nElem];
}

// Operador de indexación: []

template<class T>
T& CEmpresa<T>::operator[](int nElem) const

{
	return *m_pElem[nElem];
}


#endif
