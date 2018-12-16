//#include <string>
using namespace std;

namespace utils
{
	class CUtils
	{
	public:
		static bool LeerDato(int& dato);

		static bool LeerDato(double& dato);

		static bool LeerDato(string& dato);

		static bool LeerDato(char *dato);

		static void Mayusculas(char *cadena);
		
		static void Mayusculas(string& cadena);

		static void CrearMenu (char opciones_menu[][100], int num_opciones);
	};
};