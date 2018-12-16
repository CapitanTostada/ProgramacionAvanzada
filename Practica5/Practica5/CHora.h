#include <string>
using namespace std;

class CHora
{
private:
	int m_nHoras, m_nMinutos, m_nSegundos;
	string m_pszFormato; //almacena los valores AM, PM, 24

	bool Formato24() const;			

	
public:
	CHora(int nHoras=1, int nMinutos=1, int nSegundos=1, const string pszFormato="24");	
	CHora(const CHora& hora);
	bool AsignarHora (int nHoras, int nMinutos, int nSegundos, const string pszFormato); 		
	void ObtenerHora (int& nHoras, int& nMinutos, int& nSegundos, string& pszFormato) const;	
	bool EsHoraCorrecta() const;			
	~CHora();
}; 
																		