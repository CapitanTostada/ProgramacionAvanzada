int comprobarEntrada();
enum opciones {
	Construir1D,
	Construir2D,
	Introducir,
	Imprimir,
	Salir
};

enum Lista {
	Poner,
	Visualizar,
	Terminar
};

bool LeerEntrada(int& num);
char* LeerCadena(int n);
void converMayus(char* str);
bool ComprobarLimites(int inferior, int superior, int num);