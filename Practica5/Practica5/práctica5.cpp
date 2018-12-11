#include <iostream>
#include "utils.h"
#include "CFicha.h"
#include <string>
using namespace std;

/*int main()
{
	CFicha ficha1;
	CHora hora1;
	hora1 = ficha1.ObtenerNacio();
}*/

int main ()
{
	CFicha *pficha=NULL;
	CHora horaNacio;
	string sNombre, sFormato;
	int nEdad, nHora, nMinutos, nSegundos, sel1=0, flag;
	char Menu[][100]={"Crear una ficha", "Visualizar ficha", "Terminar"};

	utils::CUtils::CrearMenu(Menu, 3); //Creación de menú

	while(sel1!=3)
	{
		cout << "Introduzca opcion\n";
		if (!utils::CUtils::LeerDato(sel1))
			return 0;

		switch (sel1)
		{
			case 1:
			{
				if (pficha !=NULL)
					cout << "objeto dinámico ya creado" << endl;
					
				else{
				flag=0;
				do
				{
					cout << "Introduzca Nombre, edad, hora, minutos, segundos, formato" << endl;
					if (!utils::CUtils::LeerDato(sNombre))
						return 0;
					if (!utils::CUtils::LeerDato(nEdad))
						return 0;
					if (!utils::CUtils::LeerDato(nHora))
						return 0;
					if (!utils::CUtils::LeerDato(nMinutos))
						return 0;
					if (!utils::CUtils::LeerDato(nSegundos))
						return 0;
					if (!utils::CUtils::LeerDato(sFormato))
						return 0;
					utils::CUtils::Mayusculas(sFormato);

					pficha = new CFicha();	
					if (pficha==NULL)
					{
						cout << "Memoria insuficiente\n";
						return 0;
					}

					pficha->AsignarNombre(sNombre);
					pficha->AsignarEdad(nEdad);
					if (pficha->AsignarNacio(nHora, nMinutos, nSegundos, sFormato)){
						cout << "Datos introducidos" << endl;
						flag=1;
						}
					else
						cout << "Formato hora incorrecto" << endl;
						
				}while(flag!=1);
				}
				break;
			}

			case 2:
			{
				if (pficha == NULL)
					cout << "Ficha no creada" << endl;

				else{
				sNombre= pficha->ObtenerNombre();
				nEdad = pficha ->ObtenerEdad();
				horaNacio = pficha ->ObtenerNacio();
				horaNacio.ObtenerHora(nHora, nMinutos, nSegundos, sFormato);

				cout << sNombre <<" " << nEdad << " "<< nHora << ":" << nMinutos << ":" << nSegundos << " " << sFormato << endl;
				}
				break;
			}

			case 3:
				delete pficha;
				pficha=NULL;
				break;

			default:
				cout << "Orden incorrecta" << endl;
				break;
		}
					
	}
}