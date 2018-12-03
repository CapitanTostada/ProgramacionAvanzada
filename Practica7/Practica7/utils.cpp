#include <iostream>
#include <string>
#include "utils.h"
using namespace std;

void utils::CUtils::CrearMenu (char opciones_menu[][100], int num_opciones)
{
	cout << "------Menu-------" << endl;
	for (int i=1; i<=num_opciones; i++)
		cout << i << ".-" << opciones_menu[i-1] << endl;
}

bool utils::CUtils::LeerDato(int& dato)
{
	bool error;
	do
	{
		cin >> dato; 
		cin.ignore(numeric_limits<int>::max(), '\n');
		error=cin.fail();
		if (!cin.eof() && error)
		{
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cout << "Dato incorrecto, vuelva a intentarlo" << endl;
		}
		else if (cin.eof())
			return false;
	}
	while(error);
	return true;
}

bool utils::CUtils::LeerDato(double& dato)
{
	bool error;
	do
	{
		cin >> dato; 
		cin.ignore(numeric_limits<int>::max(), '\n');
		error=cin.fail();
		if (!cin.eof() && error)
		{
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cout << "Dato incorrecto, vuelva a intentarlo" << endl;
		}
		else if (cin.eof())
			return false;
	}
	while(error);
	return true;
}

bool utils::CUtils::LeerDato(char *dato)
{
	int n;
	bool error;
	do
	{
		cin.getline(dato, 100, '\n');		
		error=cin.fail();
		if (!cin.eof() && error)
		{
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cout << "Dato incorrecto, vuelva a intentarlo" << endl;
		}
		else if (cin.eof())
			return false;
	}
	while(error);
	return true;
}

void utils::CUtils::Mayusculas(char *cadena)
{
	strupr(cadena);
}

void utils::CUtils::Mayusculas(string& cadena)
{
	char mayuscula[100];
	cadena.copy(mayuscula, cadena.length());
	mayuscula[cadena.length()]=0;
	strupr(mayuscula);
	cadena= string(mayuscula);
}

bool utils::CUtils::LeerDato(string& dato)
{
	int n;
	bool error;
	do
	{
		getline(cin, dato);	
		error=cin.fail();
		if (!cin.eof() && error)
		{
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cout << "Dato incorrecto, vuelva a intentarlo" << endl;
		}
		else if (cin.eof())
			return false;
	}
	while(error);
	return true;
}

