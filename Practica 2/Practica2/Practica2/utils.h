int comprobarEntrada();
enum opciones {
	Construir1D,
	Construir2D,
	Introducir,
	Imprimir,
	Salir
};

enum Lista {
	Local,
	Dinamico,
	Copia,
	Asignacion,
	Terminar
};

enum Submenu {
	Predeterminada,
	Hora,
	Minutos,
	Segundos,
	Formato,
	Exit
};

bool LeerEntrada(int& num);
char* LeerCadena(int n);
void converMayus(char* str);
bool ComprobarLimites(int inferior, int superior, int num);