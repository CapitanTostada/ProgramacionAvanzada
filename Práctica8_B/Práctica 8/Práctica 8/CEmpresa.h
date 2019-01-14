#if !defined(_EMPRESA_H)
#define _EMPRESA_H


template <class T>
class CEmpresa
{
private:
  T ** m_pElem;
  int m_nElem;
public:
  CEmpresa() : m_nElem(10), m_pElem(NULL) 
  {
	  m_pElem = new T*[m_nElem];

	  for (int i = 0; i < m_nElem; i++)
	  {
		  m_pElem[i] = NULL;
	  }

  };
  CEmpresa(const CEmpresa<T>& a);
  CEmpresa<T>& operator=(const CEmpresa<T>& a);
  ~CEmpresa();
  void AgregarElemento(const T& elem);
  int Tamanyo() const { return m_nElem; }
  T& GetElemento(int nElem) const;
  T& operator[](int nElem) const;
};

#include "CEmpresa.cpp"

// PREGUNTA 14: plantilla para CEmpresa


#endif
