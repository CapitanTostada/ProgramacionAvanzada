#include <vector>
#include <iostream>
using namespace std;

class CMonomio
{
private:
	double m_dCoeficiente;
	int m_nExponente;

public:
	friend ostream& operator<<(ostream& os, const CMonomio& Mono);

	CMonomio(double dCoef = 0, int nExp = 0) :
		m_dCoeficiente(dCoef), m_nExponente(nExp) {}

	double GetCoef() const { return m_dCoeficiente; }
	int GetExp() const { return m_nExponente; }

	void SetCoef(double dCoef) { m_dCoeficiente = dCoef; }
	void SetExp(int nExp) { m_nExponente = nExp; }

	CMonomio operator-() const
	{
		return CMonomio(-m_dCoeficiente, m_nExponente);
	}
};

class CTermino
{
private:
	CMonomio m_Monomio;
	CTermino *m_pSig;

public:
	CTermino(double dCoef = 0, int nExp = 0, CTermino *pSig = NULL)
		:m_Monomio(dCoef, nExp), m_pSig(pSig) {}

	CTermino(const CMonomio& monomio, CTermino *pSig = NULL)
		:m_Monomio(monomio), m_pSig(pSig) {}

	CTermino(const CTermino& termino, CTermino *pSig = NULL)
		:m_Monomio(termino.m_Monomio), m_pSig(pSig) {}

	double GetCoef() const { return m_Monomio.GetCoef(); }
	int GetExp() const { return m_Monomio.GetExp(); }
	CMonomio GetMono() const { 
		return m_Monomio; 
	}
	CTermino * GetSig() const { return m_pSig; }

	void SetCoef(double dCoef) { m_Monomio.SetCoef(dCoef); }
	void SetExpo(int nExp) { m_Monomio.SetExp(nExp); }
	void SetMono(const CMonomio& mono) { m_Monomio = mono; }
	void SetSig(CTermino * pSig) { m_pSig = pSig; }
};

class CPolinomio {
private:
	CTermino * m_pCabecera;

public:
	friend ostream& operator <<(ostream& os, const CPolinomio& Poli);
	int Grado() const;

	//Introducir constructores
	CPolinomio() :m_pCabecera(NULL) {}
	CPolinomio(const CPolinomio& poli);
	CPolinomio(vector<CMonomio> monomio);
	CPolinomio(const CMonomio& mono);
	CPolinomio(double dCoef, int nExp = 0);

	~CPolinomio();

	CPolinomio& operator<<(const CMonomio& mono);
	CPolinomio& operator=(const CPolinomio& poli);

	CPolinomio& operator-();

	const CPolinomio operator+(const CPolinomio &P);
	const CPolinomio operator-(const CPolinomio &P);
	CPolinomio& operator+=(const CPolinomio& P);
	CPolinomio& operator-=(const CPolinomio& P);
	double operator[](int exp) const;
	double operator()(double x) const;
	bool operator==(const CPolinomio& P2);
	bool operator<(const CPolinomio& P2);
	bool operator>(const CPolinomio& P2);

	void MostrarPoli(ostream& os) const;
};