#include "Clases.h"
#include <cstdio>
#include <iostream>

ostream& operator<<(ostream& os, const CMonomio& mono) {
	os << showpos;
	if (!mono.GetExp())
		os << mono.GetCoef;
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

ostream& operator<<(ostream& os, const CPolinomio& poli) {
	poli.MostrarPoli(os);
	return os;
}

//********************Clase de CMonomio********************
CMonomio::CMonomio(double dCoef = 0, int nExp) :m_dCoeficiente(dCoef), m_nExponente(nExp) {}

CMonomio::CMonomio operator-() const {
	return CMonomio(-m_dCoeficiente, m_nExponente);
}

CMonomio::GetCoef() const {
	return m_dCoeficiente;
}

CMonomio::GetExp() const {
	return m_nExponente;
}

CMonomio::SetCoef(double dCoef) {
	m_dCoeficiente = dCoef;
}

CMonomio::SetExp(int nExp) {
	m_nExponente = nExp;
}


//********************Clase de CTermino********************

CTermino::CTermino(double dCoef = 0, int nExp = 0, CTermino pSig = NULL) {
	SetCoef(dCoef);
	SetExp(nExp);
}
CTermino::CTermino(const CMonomio& mono, CTermino pSig = NULL) {
	SetCoef(mono.GetCoef());
	SetExp(mono.GetExp());
}
CTermino::CTermino(const CTermino& termino, CTermino pSig = NULL) {
	SetCoef(termino.GetCoef());
	SetExp(termino.GetExp());
}

CTermino::GetCoef() const {
	return m_Monomio.GetCoef();
}
CTermino::GetExp() const {
	return m_Monomio.GetExp();
}
CTermino::GetMono() const {
	return m_Monomio;
}
CTermino::GetSig() const {
	return m_pSig;
}

CTermino::SetCoef(double dCoef) {
	m_Monomio.SetCoef(dCoef);
}
CTermino::SetMono(const CMonomio& mono) {
	m_Monomio = mono;
}
CTermino::SetExp(int nExp) {
	m_Monomio.SetExp(nExp);
}
CTermino::SetSig(CTermino * pSig) {
	m_pSig = pSig;
}


//********************Clase CPolinomio********************

CPolinomio::CPolinomio() {
	m_pCabecera = NULL;
}

CPolinomio::MostrarPoli(ostream& os) const {
	const CTermino * pPos = m_pCabecera;
	if (pPos)
		do {
			os << pPos->GetMono() << ' ';
			pPos = pPos->GetSig;
		} while (pPos);
	else
		os << "0 ";
}
