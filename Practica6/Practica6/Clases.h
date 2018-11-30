ostream& operator<<(ostream& os, const CPolinomio& Poli);
ostream& operator<<(ostream& os, const CMonomio& mono);

class CMonomio {
private:
	double m_dCoeficiente;
	int m_nExponente;

public:
	CMonomio(double dCoef = 0, int nExp);

	inline double GetCoef() const;
	inline int GetExp() const;

	inline void SetCoef(double dCoef);
	inline void SetExp(int nExp);

	CMonomio operator-() const;
};

class CTermino {
private:
	CMonomio m_Monomio;
	CTermino *m_pSig;

public:
	CTermino(double dCoef = 0, int nExp = 0, CTermino pSig = NULL);
	CTermino(const CMonomio& mono, CTermino pSig = NULL);
	CTermino(const CTermino& termino, CTermino pSig = NULL);

	double GetCoef() const;
	int GetExp() const;
	CMonomio GetMono() const;
	CTermino * GetSig() const;

	void SetCoef(double dCoef);
	void SetMono(const CMonomio& mono);
	void SetExp(int nExp);
	void SetSig(CTermino * pSig);
};

class CPolinomio {
private:
	CTermino * m_pCabecera;

public:
	//Introducir constructores
	CPolinomio();

	void MostrarPoli(ostream& os) const;

};