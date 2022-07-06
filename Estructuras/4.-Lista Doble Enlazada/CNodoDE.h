#ifndef CAB_NODODE
#define CAB_NODODE
#include <iostream>


using namespace std;

class CNodoDE{
	//atributos
	public:
	int dato;
	CNodoDE *sig;
	CNodoDE *ant;
	
	//metodos
	public:
	CNodoDE();
	CNodoDE(int ele);
	void mostrarNodoDE();
	void eliminarNodoDE();
};

//Metodo constructor sin datos

	CNodoDE::CNodoDE()
	{
		ant=NULL;
		dato=0;
		sig=NULL;
	}
	
//Metodo constructor con dato en elemento
	CNodoDE::CNodoDE(int ele)
	{
		ant=NULL;
		dato=ele;
		sig=NULL;
	}
	
	//Mostrar informacion
	void CNodoDE::mostrarNodoDE()
	{
		cout<<dato<<" - ";
	}
	
	//Eliminar informacion
	void CNodoDE::eliminarNodoDE()
	{
		delete this;	
	}
	
	#endif
