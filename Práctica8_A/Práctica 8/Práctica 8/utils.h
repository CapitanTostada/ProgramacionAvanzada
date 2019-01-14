#if !defined(_UTILS_H)
#define _UTILS_H
#include <string>


namespace utils
{
	class CUtils
	{
	public:
		bool LeerDato(int& dato);
		bool LeerDato(float& dato);
		bool LeerDato(double& dato);
		bool LeerDato(char* str);
		bool LeerDato(std::string& str);
		int CrearMenu(char *opciones_menu[]);
		char* ConverMayus(char* str);
		void ConverMayus(std::string& str);

	};
}



#endif