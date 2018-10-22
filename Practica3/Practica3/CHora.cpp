#include "CHora.h"
#include <cstdio>
#include <iostream>
#include <locale>
#include "../../Practica 2/Practica2/Practica2/utils.h"
using namespace std;

bool CHora::AsignarFormato(char* pszFormato) {
	if (pszFormato != NULL && strlen(pszFormato) < 10) {
		delete m_pszFormato;
		m_pszFormato = new char[9];

		converMayus(pszFormato);

		if (pszFormato != 0 && m_pszFormato != 0)
			strcpy_s(m_pszFormato, 9, pszFormato);
		return true;
	}
	else
		return false;
}

bool CHora::Formato24() const {
	if (strcmp(m_pszFormato, "24 HORAS") == 0)
		return true;
	return false;
}

bool CHora::EsHoraCorrecta() const {
	if (Formato24() == true) {
		if (ComprobarLimites(0, 23, m_nHoras) && ComprobarLimites(0, 59, m_nMinutos) && ComprobarLimites(0, 59, m_nSegundos))
			return true;
		else
			return false;
	}
	else if (strcmp(m_pszFormato,"AM") == 0 || strcmp(m_pszFormato,"PM") == 0) {
		if (ComprobarLimites(1, 12, m_nHoras) && ComprobarLimites(0, 59, m_nMinutos) && ComprobarLimites(0, 59, m_nSegundos))
			return true;
		else
			return false;
	}
	else
		return false;
}


CHora::CHora(int nHora, int nMinutos, int nSegundos, char* cad) {
	m_nHoras = nHora;
	m_nMinutos = nMinutos;
	m_nSegundos = nSegundos;
	char cadena[] = "24 HORAS";
	if (cad == NULL)
		AsignarFormato(cadena);
	else
		AsignarFormato(cad);
	cout << "Constructor ejecutado\n";
}

CHora::CHora(const CHora& hora) {
	m_nHoras = hora.m_nHoras;
	m_nMinutos = hora.m_nMinutos;
	m_nSegundos = hora.m_nSegundos;
	m_pszFormato = NULL;
	cout << "Constructor copia ejecutado\n";
}

CHora::~CHora() {
	delete m_pszFormato;
	m_nHoras = 0;
	m_nMinutos = 0;
	m_nSegundos = 0;
	m_pszFormato = NULL;
	cout << "Destructor ejecutado\n";
}

bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, char *pszFormato) {
	if (AsignarFormato(pszFormato)) {
		m_nHoras = nHoras;
		m_nMinutos = nMinutos;
		m_nSegundos = nSegundos;
		if (EsHoraCorrecta())
			return true;
	}
	this->~CHora();
	return false;
}

void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char *pszFormato) const {
	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;
	if (pszFormato != 0 && m_pszFormato != 0)
		strcpy_s(pszFormato, 9, m_pszFormato);
	else
		*pszFormato = 0;
}

void VisualizarHora(const CHora& hora) {
	int nHoras, nMinutos, nSegundos;
	char* pszFormato = new char[9]; 

	hora.ObtenerHora(nHoras, nMinutos, nSegundos, pszFormato);

	if (pszFormato != NULL && *pszFormato != 0) {
		cout << "Son las: " << nHoras
			<< ":" << nMinutos
			<< ":" << nSegundos
			<< " " << pszFormato
			<< "\n";
	}
	else
		cout << "Ponga una hora";
}

void SubMenu() {
	int opcion;
	Submenu seleccion;
	do {
		cout << "Menu de opciones: "
			<< "\n\t 1. Introducir una hora predeterminada"
			<< "\n\t 2. Introducir la hora"
			<< "\n\t 3. Introducir la hora y los minutos"
			<< "\n\t 4. Introducir la hora, los minutos y los segundos"
			<< "\n\t 5. Introducir la hora, los minutos, los segundos y el formato"
			<< "\n\t 6. Volver al menu principal"
			<< "\nIntroduce la opcion deseada: ";
		opcion = comprobarEntrada();
	} while (opcion > 6 && opcion < 0);
	seleccion = Submenu(--opcion);

	switch (seleccion) {
	case Predeterminada: {
		CHora Fecha;
		VisualizarHora(Fecha);
		break;
	}
	case Hora: {
		cout << "Introduzca una hora: \n";
		int nHora = comprobarEntrada();
		CHora Fecha(nHora);
		VisualizarHora(Fecha);
		break; 
	}
	case Minutos: {
		cout << "Introduzca una hora: \n";
		int nHora = comprobarEntrada();
		cout << "Introduzca los minutos: \n";
		int nMinutos = comprobarEntrada();
		CHora Fecha(nHora, nMinutos);
		VisualizarHora(Fecha);
		break; 
	}
	case Segundos: {
		cout << "Introduzca una hora: \n";
		int nHora = comprobarEntrada();
		cout << "Introduzca los minutos: \n";
		int nMinutos = comprobarEntrada();
		cout << "Introduzca los minutos: \n";
		int nSegundos = comprobarEntrada();
		CHora Fecha(nHora, nMinutos, nSegundos);
		VisualizarHora(Fecha);
		break;
	}
	case Formato: {
		cout << "Introduzca una hora: \n";
		int nHora = comprobarEntrada();
		cout << "Introduzca los minutos: \n";
		int nMinutos = comprobarEntrada();
		cout << "Introduzca los sedgundos: \n";
		int nSegundos = comprobarEntrada();
		cout << "Introduzca el formato: \n";
		char* cad = LeerCadena(9);
		CHora Fecha(nHora, nMinutos, nSegundos, cad);
		VisualizarHora(Fecha);
		break;
	}
	case Exit:
		break;
	default:
		break;
	}
}
int Menu() {
	int opcion;
	do {
		cout << "Menu de opciones: "
			<< "\n\t 1. Crear objeto local"
			<< "\n\t 2. Crear objeto dinamicamente"
			<< "\n\t 3. Constructor copia"
			<< "\n\t 4. Operador de asignacion"
			<< "\n\t 5. Salir: sale del programa"
			<< "\nIntroduce la opcion deseada: ";
		opcion = comprobarEntrada();
	} while (opcion > 5 && opcion < 0);
	return opcion;
}

CHora CHora::operator=(CHora obj) {
	CHora fecha2(obj);
	cout << "Ejecutado con sobrecarga";
	return fecha2;
}