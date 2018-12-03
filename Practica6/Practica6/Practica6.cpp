#include <cstdio>
#include <iostream>
#include "Clases.h"

using namespace std;


int main()
{
	
	CPolinomio P, Q, R, S, T, U, V, W, X, Y, Z, N;
	CMonomio m1, m2(2, 2), m3(3, 3), m4(4, 4);

	P << m1 << m2 << -m4 << m3;
	Q << m4 << m1 << m2 << -m3;
	R << m3 << m4 << -m2;
	S << m2 << m3 << m4 << -m2;
	T << -m2 << -m3 << -m4 << m3;
	U << m2 << m3 << m4 << -m4;
	V << m2 << m3 << m4 << -m2 << -m3 << -m4;
	W << m2 << m3 << -m2 << -m3;
	X << m2 << -m2;
	Y << m2 << m3 << m4 << m2;
	Z << -m2 << -m3 << -m4 << -m3;
	N << m2 << m3 << m4 << m4;

	cout << "P = " << P << endl;
	cout << "Q = " << Q << endl;
	cout << "R = " << R << endl;
	cout << "S = " << S << endl;
	cout << "T = " << T << endl;
	cout << "U = " << U << endl;
	cout << "V = " << V << endl;
	cout << "W = " << W << endl;
	cout << "X = " << X << endl;
	cout << "Y = " << Y << endl;
	cout << "Z = " << Z << endl;
	cout << "N = " << N << endl;

	cout << endl << "Prueba de constructor copia A=P" << endl;
	CPolinomio A(P);
	cout << "P = " << P << endl;
	cout << "A = " << A << endl;

	cout << endl << "Prueba operador asignación B=Q" << endl;
	CPolinomio B;
	B = Q;
	cout << "B = " << B << endl;
	cout << "Q = " << Q << endl;


	cout << endl << "Prueba constructor con coeficiente y exponente" << endl;
	CPolinomio C(2.5);
	cout << "C = " << C << endl;
	CPolinomio D(2.5, 5);
	cout << "D = " << D << endl;


	cout << endl << "Prueba constructor con un monomio" << endl;
	CPolinomio E(m4);
	cout << "E = " << E << endl;

	cout << endl << "Prueba funcion grado" << endl;
	cout << "El grado de U es: " << U.Grado() << endl;

	cout << endl << "Prueba funcion con vector<CMonomio>" << endl;
	vector<CMonomio> monomio(3);
	monomio[0] = m4;
	monomio[1] = m3;
	monomio[2] = m2;
	CPolinomio F(monomio);
	cout << "F= " << F << endl;

	cout << endl << "Prueba del operador >" << endl;
	cout << "P = " << P << endl;
	cout << "U = " << U << endl;
	if (P > U)
		cout << "P tiene mayor grado que U" << endl;
	else
		cout << "M tiene mayor grado que U" << endl;


	cout << endl << "Prueba del operador==" << endl;
	cout << "P = " << P << endl;
	cout << "Q = " << Q << endl;
	if (P == Q)
		cout << "tienen el mismo grado" << endl;
	else
		cout << "No tienen el mismo grado" << endl;


	cout << endl << "Prueba operador - unario" << endl;
	cout << "Q = " << Q << endl;
	cout << "-Q  = " << -Q << endl;

	cout << endl << "Prueba operador +" << endl;
	cout << "N = " << N << endl;
	cout << "U = " << U << endl;
	cout << "N+U = " << N + U << endl;

	cout << endl << "Prueba operador - y +=" << endl;
	cout << "R = " << R << endl;
	cout << "S = " << S << endl;
	cout << "R-S = " << R - S << endl;
	cout << "R+=S = " << (R += S) << endl;

	cout << endl << "Prueba operador -=" << endl;
	cout << "N = " << N << endl;
	cout << "Y = " << Y << endl;
	cout << "N-=Y = " << (N -= Y) << endl;

	cout << endl << "Prueba del operador[]" << endl;
	cout << "Polinomio P: " << P << endl;
	cout << "Coeficiente de P[4]: " << P[4] << endl;

	cout << endl << "Prueba del operador()" << endl;
	CPolinomio G;
	CMonomio g1(3, 2), g2(-2, 1);
	G << g1 << g2;
	cout << "G: " << G << "G(0.5)= " << G(0.5) << endl;

	return 0;
}