#include <iostream>
#include <cstdio>
#include "../../../Practica3/Practica3/CHora.h"
using namespace std;

int comprobarEntrada() {
	int error;
	int num;

	do {
		cin >> num;
		error = cin.rdstate() & ios::failbit;
		if (error) {
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cout << "\nIntroduce un numero entero: ";
		}
	} while (error);
	cin.ignore(numeric_limits<int>::max(), '\n');
	return num;
}

bool LeerEntrada(int& num) {

	int error;

	do {
		cin >> num;
		error = cin.rdstate() & ios::eofbit;
		if (error)
			return false;
		
		error = cin.rdstate() & ios::failbit;
		if (error) {
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cout << "\nIntroduce un numero entero: ";
		}
	} while (error);
	cin.ignore(numeric_limits<int>::max(), '\n');
	return true;
	
}

char* LeerCadena(int n) {
	char * c = NULL;
	c = new char[n];
	cin.getline(c,n);
	return c;
}

void converMayus(char* str) {
	int i = 0;
	while (str[i] != '\0') {
		str[i] = toupper(str[i]);
		i++;
	}
}

bool ComprobarLimites(int inferior, int superior, int num) {
	if (num <= superior and num >= inferior)
		return true;
	else
		return false;
}