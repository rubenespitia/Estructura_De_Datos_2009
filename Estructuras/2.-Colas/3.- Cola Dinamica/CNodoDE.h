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

//Constructor de Nodos sin datos
	CNodoDE::CNodoDE()
	{
		ant=NULL;
		dato=0;
		sig=NULL;
	}

///Constructor de nodos con Elementos	
	CNodoDE::CNodoDE(int ele)
	{
		ant=NULL;
		dato=ele;
		sig=NULL;
	}
	
//MostrarNodo
	void CNodoDE::mostrarNodoDE()
	{
		cout<<dato<<" - ";
	}
//Eliminamos elemento
	void CNodoDE::eliminarNodoDE()
	{
		delete this;	
	}
	
	#endif
