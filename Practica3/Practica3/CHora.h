#pragma once

class CHora {
private:
	int m_nHoras;
	int m_nMinutos;
	int m_nSegundos;
	char *m_pszFormato;

	bool AsignarFormato(char *pszFormato);
	bool Formato24() const;

protected:
	bool EsHoraCorrecta() const;

public:
	CHora();
	~CHora();
	void Iniciar();
	bool AsignarHora(int nHoras, int nMinutos, int nSegundos, char *pszFormato);
	void ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char *pszFormato) const;
	void Destruir();
};

void VisualizarHora(const CHora& hora);