#pragma once
#include <string>

using namespace std;

class CIndiceIncorrecto
{
	string mensajeDeError;
public:
	CIndiceIncorrecto(string mensaje = "Indice incorrecto")
	{
		mensajeDeError = mensaje;
	}
	string what() { return mensajeDeError; }
};