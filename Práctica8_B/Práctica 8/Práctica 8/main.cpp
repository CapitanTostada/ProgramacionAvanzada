#include <iostream>
#include <fstream>
#include <vector>
#include "CContrato.h"
#include "CSiniestroUrgente.h"
#include "CSiniestroNormal.h"
#include "CCliente.h"
#include "utils.h"
#include "CEmpresa.h"
#include "MemoryManager.h"

using namespace std;
using namespace utils;

const int MAX_CLIENTES = 10;

int main()
{
  {
	utils::CUtils funciones;
    char * OpMenu[]={" 1. Vaciar() de CLista.",
                     " 2. Operador [] CLista.",
                     " 3. Constructor copia de CContrato.",
                     " 4. AgregarSiniestro() de CContrato.",
                     " 5. Operador << CCliente.",
                     " 6. m_pSigCodigo static.",
                     " 7. Presupuestar() de CSiniestro y derivadas",
                     " 8. AgregarContrato() de CCliente",
                     " 9. total += seguros[i]",
                     "10. Constructor CSiniestro y CSiniestroNormal",
                     "11. const_cast<CLista<T>*>(this)->",
                     "12. GetCoste()?",
                     "13. c.AgregarSiniestro()",
                     "14. Plantilla CEmpresa.",
                     "15. Guardar empresa.",
                     "16. Salir.",
					 NULL
                    };
    const int numopciones = sizeof(OpMenu)/sizeof(char *);
    int opcion=0;

    do
    {
	  system("cls");
	  opcion=funciones.CrearMenu(OpMenu);
      switch(opcion)
      {
      case 1:
        {
          // Crear una lista para después vaciarla
          vector<string> miLista;

          string nombres[]={"Nombre 1", "Nombre 2", "Nombre 3", "Nombre 4", "Nombre 5",
            "Nombre 6", "Nombre 7", "Nombre 8", "Nombre 9", "Nombre 10"};
          // Rellenar la lista con nombres
		  for (int i = 0; i < 10; i++)
		  {
			  miLista.push_back(nombres[i]);
		  }

          // Mostrar la lista. Preveer execepción CIndiceIncorrecto.
		  for (int i = 0; i < 10; i++)
		  {
			  try
			  {
				  cout << miLista[i]<<endl;
			  }
			  catch (bad_alloc)
			  {
				  cout << "Indice incorrecto" << endl;
			  }
		  }

          // Vaciar la lista y verificar después que está vacía.

		  cout << "Vaciando Lista ..." << endl;

		  miLista.clear();

		  cout << "Lista vacia." << endl;

          cout << "Es necesario que la clase CLista sea friend de CNodoLista ya que CLista necesita tener acceso a los miembros privados de CNodoLista" << endl;

          system("pause");
          break;
        }
      case 2:
        {
          // Ejemplo operador [] con lista de enteros
          // Crear un objeto lista que almacene 10 datos de tipo int

		  vector <int> lista;
		  int array []= { 5,6,7,10,3,2,15,12,8,1 };

		  for (int i = 0; i < 10; i++)
		  {
			  try
			  {
				  lista.push_back(array[i]);
			  }
			  catch (bad_alloc)
			  {
				  cout << "Indice incorrecto" << endl;
			  }
		  }
		  
          // Sumar todos los números de la lista y provocar la excepción CIndiceIncorrecto

		  cout << "Provocando la excepcion CIndiceIncorrecto: " << endl;

		  int total=0;

		  for (int i = 0; i < 11; i++)
		  {
			  try
			  {
				  total += lista.at(i);
			  }
			  catch (out_of_range& e)
			  {
				  cout << e.what() << "   Indice incorrecto" << endl;
			  }
		  }

		  cout << "Suma de una lista de 10 enteros consecutivos (del 1 al 10): " << total << endl;

          system("pause");
          break;
        }
      case 3: // Pregunta 1
        {
          // Crear e iniciar objeto CContrato a copiar
          CContrato original(12345,"Prueba constructor copia","11-01-16",123456789,987654321);
          // Rellenar objeto original
          TSituacion situacion = local;
          original.AgregarSiniestro(CSiniestroUrgente(local,"siniestro 1"));
          original.AgregarSiniestro(CSiniestroNormal("siniestro 2"));
          original.AgregarSiniestro(CSiniestroNormal("siniestro 3"));
          cout << " CONTRATO ORIGINAL: " << endl << endl << original;

          cout << "\n Constructor copia de CContrato ejecutado con exito." << endl << endl;
          CContrato copia(original);
          original = copia;

          cout << " CONTRATO COPIA: " << endl << endl << copia << endl;
          system("pause");
          break;
        }
      case 4:
        {
          CContrato prueba(12345);
		  cout << "Creado un objeto CContrato prueba sin siniestros." << endl << endl;

          // Agregar a "prueba" un siniestro urgente y otro normal

		  prueba.AgregarSiniestro(CSiniestroUrgente(local, "siniestro 1"));
		  cout << "Agregado siniestro 1 (urgente)." << endl << endl;

		  prueba.AgregarSiniestro(CSiniestroNormal("siniestro 2"));
		  cout << "Agregado siniestro 2 (normal)." << endl << endl;

          prueba.MostrarSiniestros();

          cout << endl;
          cout << "Es necesario que Clonar sea virtual ya que se tiene que llamar a la clase derivada adecuada" << endl << endl;
          system("pause");
          break;
        }
      case 5:
        {
          // Crear cliente
          CCliente cli("Juan");
          // Agregar un contrato con dos siniestros, urgente y normal, a cli

		  CContrato contrato1(12345, "Contrato 1 de Juan", "12-11-08", 1234567, 23000);
		  contrato1.AgregarSiniestro(CSiniestroUrgente(local, "siniestro 1"));
		  contrato1.AgregarSiniestro(CSiniestroNormal("siniestro 2"));

		  cli.AgregarContrato(contrato1);

          // Mostrar datos
		  cout << " Datos del cliente: \n" << endl << cli << endl;
          system("pause");

		  operator<<(operator<<(cout, " Datos del cliente : \n"), cli);

          cout << "Llamada explicita:\n" << "operator<<(operator<<(cout, ' Datos del cliente : \n'), cli);";
          system("pause");
          break;
        }
      case 6:
        {
          cout << "La iniciacion de m_SigCodigo se realiza en la clase base CSiniestro ya que siempre se invoca sin importar cual sea la clase derivada" << endl;
          system("pause");
          break;
        }
      case 7:
        {
		  cout << "Ejemplo funcion Presupuestar de CSiniestro: " << endl << endl;
		  
		  CSiniestroUrgente MiSiniestroUrgente(internacional,"Siniestro Urgente Ejemplo");
          MiSiniestroUrgente.Presupuestar(7,3);
		  cout << "Presupuesto de Siniestro Urgente Ejemplo: " << MiSiniestroUrgente.GetCoste() << endl;

          CSiniestroNormal MiSiniestroNormal("Siniestro Normal Ejemplo");
          MiSiniestroNormal.Presupuestar(9,4);
		  cout << "Presupuesto de Siniestro Normal Ejemplo: " << MiSiniestroNormal.GetCoste() << endl << endl;


          cout << "No podria se private la variable m_Coste ya que tienen que poder acceder las clases derivadas." << endl;
          system("pause");
          break;
        }
      case 8:
        {
          // Crear un cliente cli

		  CCliente cli("Juan");

          // Agregar a cli un contrato con siniestros

		  CContrato contrato1(12345, "Contrato 1 de Juan", "12-11-08", 1234567, 23000);
		  contrato1.AgregarSiniestro(CSiniestroUrgente(local, "siniestro 1"));
		  contrato1.AgregarSiniestro(CSiniestroNormal("siniestro 2"));

		  cli.AgregarContrato(contrato1);

          // Mostrar cli

		  cout << " Datos del cliente: \n" << endl << cli << endl;

          system("pause");
          break;
        }
      case 9:
        {
          // Crear una matriz dinámica de tipo CCliente apuntada por "seguros"

		  CCliente * seguros = new CCliente [MAX_CLIENTES];

          // Agregar contratos a los clientes de la matriz "seguros"

		  CContrato contrato1(12345, "Prueba cliente", "11-01-16", 123456789, 987654321);
		  CContrato contrato2(12345, "Prueba cliente", "11-01-16", 123456789, 987654321);
		  CContrato contrato3(12345, "Prueba cliente", "11-01-16", 123456789, 987654321);
		  CContrato contrato4(12345, "Prueba cliente", "11-01-16", 123456789, 987654321);

		  seguros[0].AgregarContrato(contrato1);
		  seguros[0].AgregarContrato(contrato2);
		  seguros[1].AgregarContrato(contrato3);
		  seguros[1].AgregarContrato(contrato4);

          // Contar el número total de contratos
          long total = 0;
		  for (int i = 0; i < MAX_CLIENTES; i++)
		  total += seguros[i];
          cout << "\n El numero total de contratos de los clientes asciende a: ";
          cout << total << " contratos\n";
          system("pause");
          delete [] seguros;
          break;
        }
      case 10:
        {
          CSiniestroNormal s("Rotura de tambor");
          cout << endl;
          s.Mostrar(); cout << endl;

          system("pause");
          break;
        }
      case 11:
        {
          cout << "Es necesaria esa conversion ya que sino 'm_Actual' no se puede modificar porque se estaria obteniendo acceso a este elemento a traves de un objeto const" << endl;
          system("pause");
          break;
        }
      case 12:
        {
          cout << "Si se podria ejecutar GetCoste() desde esa funcion miembro ya que las dos son funciones miembro de la misma clase" << endl;
          system("pause");
          break;
        }
      case 13:
        {
          CContrato c(12345, "Cafetera C1Z","2/1/2016", 100, 1000);
          CSiniestroUrgente s(nacional, "Fallo general");
          c.AgregarSiniestro(s);

          cout << "Las sentencias llamadas son:" << endl;
		  cout << "1- CContrato::AgregarSiniestro()" << endl;
		  cout << "2- SiniestroUrgente::Clonar()" << endl;
		  cout << "3- CLista<T>::AgregarObjeto()" << endl;
          system("pause");
          break;
        }
      case 14:
        {
          // Crear empresa1
          CEmpresa<CCliente> empresa1;
          // Agregar elementos a la empresa

		  CCliente cliente1("Cliente 1");
		  CCliente cliente2("Cliente 2");
		  CCliente cliente3("Cliente 3");
		  empresa1.AgregarElemento(cliente1);
		  empresa1.AgregarElemento(cliente2);
		  empresa1.AgregarElemento(cliente3);

          // Crear empresa2 como copia de empresa1

		  CEmpresa<CCliente> empresa2(empresa1);

          // Mostrar la empresa2
          cout << "\n CLIENTES DE LA EMPRESA: \n" << endl;

		  cout << empresa2[0] << endl;
		  cout << empresa2[1] << endl;
		  cout << empresa2[2] << endl;


          system("pause");
          break;
        }
      case 15:
        {
          //Crear empresa
		  CEmpresa<CCliente> empresa1;
          // Rellenar empresa
          
		  CCliente cliente1("Cliente 1");
		  CCliente cliente2("Cliente 2");
		  CCliente cliente3("Cliente 3");
		  empresa1.AgregarElemento(cliente1);
		  empresa1.AgregarElemento(cliente2);
		  empresa1.AgregarElemento(cliente3);

          // Guardar los nombres en un fichero (escribir)

		  fstream fs;
		  fs.open("clientes.txt", ios::out | ios::trunc | ios::in);

		  if (!fs) throw "No se puede abrir el fichero";

		  fs << empresa1[0].GetNombre() << "\n";
		  fs << empresa1[1].GetNombre() << "\n";
		  fs << empresa1[2].GetNombre() << "\n";

          cout << "\nCLIENTES DE LA EMPRESA GUARDADOS.\n";

		  system("pause");

          // Verificar la información almacenada en el fichero (leer)

		  string str;
		  fs.seekg(ios::beg);
		  for (int i = 0; i < 3; i++)
		  {
			  getline(fs, str);
			  cout << str << endl;
		  }
		  
          system("pause");
          break;
        }
      }
    }
    while(opcion < (numopciones-1));
  }
  MemoryManager::dumpMemoryLeaks();
  system("pause");
}

