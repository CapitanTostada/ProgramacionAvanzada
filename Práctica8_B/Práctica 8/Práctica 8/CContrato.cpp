#include "CContrato.h"
#include "MemoryManager.h"
using namespace std;

CContrato::CContrato(int NumSerie, const string& Desc, const string& FF, long Poliza, long ValorCompra)
  : m_NumSerie(NumSerie), m_Descripcion(Desc),
  m_FechaFin(FF), m_Poliza(Poliza), m_ValorCompra(ValorCompra)
{
}

// PREGUNTA 3: constructor copia de la clase CContrato

CContrato::CContrato(const CContrato& c)
{
	*this = c;
}


CContrato& CContrato::operator =(const CContrato &c)
{
	m_NumSerie = c.m_NumSerie;
	m_Descripcion = c.m_Descripcion;
	m_FechaFin = c.m_FechaFin;
	m_Poliza = c.m_Poliza;
	m_ValorCompra = c.m_ValorCompra;
	BorrarSiniestros();
	if (c.m_Siniestros.size()==0)
	{
		for (int i = 0; i<c.m_Siniestros.size(); i++)
		AgregarSiniestro(*c.m_Siniestros[i]);
	}
	return *this;
}





// PREGUNTA 4: AgregarSiniestro de la clase CContrato

void CContrato:: AgregarSiniestro(const CSiniestro & s)
{
	m_Siniestros.push_back(s.Clonar());
}



CContrato::~CContrato()
{
  BorrarSiniestros();
}

//
void CContrato::BorrarSiniestros()
{
	for (int i = 0; i<m_Siniestros.size(); i++)
		delete m_Siniestros[i];
	m_Siniestros.clear();
}



void CContrato::MostrarSiniestros(ostream& os)
{
  if (this->m_Siniestros.size()==0)
    os << "Contrato sin siniestros." << endl;
  else
  {
	  for (int i = 0; i<m_Siniestros.size(); i++)
      this->m_Siniestros[i]->Mostrar(os);
  }
}


// Necesaria para PREGUNTA 5
ostream& operator<<(ostream& os,  CContrato& c)
{
	os << "Numero de serie: " << c.m_NumSerie << endl;
	os << "Descripcion: " << c.m_Descripcion << endl;
	os << "Fecha de finalizacion del contrato: " << c.m_FechaFin << endl;
	os << "Poliza: " << c.m_Poliza << endl;
	os << "Valor de compra: " << c.m_ValorCompra << endl << endl;
	os << "Siniestros: " << endl << endl;
	c.MostrarSiniestros();
	return os;
}
