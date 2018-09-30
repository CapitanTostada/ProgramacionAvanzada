#include <iostream>
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