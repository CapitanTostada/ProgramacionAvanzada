#include <iostream>
#include <iomanip>
#include <string>
#include "utils.h"


using namespace utils;


	bool CUtils::LeerDato(int& dato)
	{
		int error;
		bool flaError;
		do
		{
			flaError = false;
			std::cin >> dato;
			error = std::cin.rdstate() & std::ios::failbit;
			if (error)
			{
				flaError = true;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			}

		} while (flaError);

		std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		return true;
	}

	bool CUtils::LeerDato(float& dato)
	{
		int error;
		bool flaError;
		do
		{
			flaError = false;
			std::cin >> dato;
			error = std::cin.rdstate() & std::ios::failbit;
			if (error)
			{
				flaError = true;
				std:: cin.clear();
				std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			}

		} while (flaError);

		std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		return true;
	}

	bool CUtils::LeerDato(double& dato)
	{
		int error;
		bool flaError;
		do
		{
			flaError = false;
			std::cin >> dato;
			error = std::cin.rdstate() & std::ios::failbit;
			if (error)
			{
				flaError = true;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			}

		} while (flaError);

		std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		return true;
	}

	bool CUtils::LeerDato(char* str)
	{
		int n = 9;
		std::cin.getline(str, n);
		return true;
	}

	bool CUtils::LeerDato(std::string& str)

	{
		getline(std::cin, str);
		return true;
	}

	int CUtils::CrearMenu(char *opciones_menu[])
	{
		int valor;
		for (int i = 0; opciones_menu[i] != NULL; i++)
		{
			std::cout << opciones_menu[i] << std::endl;
		}

		LeerDato(valor);
		return valor;

	}

	char* CUtils::ConverMayus(char* str)

	{
		for (int i = 0; i < strlen(str); i++) str[i] = toupper(str[i]);
		return str;
	}

	void CUtils::ConverMayus(std::string& str)
	{
		for (int i = 0; i < str.size(); i++) str[i] = toupper(str[i]);
	}
