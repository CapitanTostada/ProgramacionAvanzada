
using namespace std;

template<class T>
CNodoLista<T>::CNodoLista(const T& Obj, CNodoLista<T> *pNodo)
: m_Dato(Obj), m_pSigNodo(pNodo)
{
}

template<class T>
CNodoLista<T>::CNodoLista(const CNodoLista<T> &NodoLista)
{
  *this = NodoLista;
}

template<class T>
CNodoLista<T>& CNodoLista<T>::operator=(const CNodoLista<T>& NodoLista)
{
	m_Dato = NodoLista.GetDato;
	m_pSigNodo = NodoLista.m_pSigNodo;
}

