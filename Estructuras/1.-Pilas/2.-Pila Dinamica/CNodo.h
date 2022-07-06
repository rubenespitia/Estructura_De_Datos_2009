#ifndef CAB_NODO
#define CAB_NODO

#include <iostream>
using namespace std;

class CNodo{
	//atributos
	public:
	int dato;
	CNodo *sig;
	
	//metodos
	public:
	CNodo();
	CNodo(int ele);
	void mostrarNodo();
	void eliminarNodo();
	
};

	//Datos por defecto del nodo sin dato
	CNodo::CNodo()
	{
		dato=0;
		sig=NULL;
	}
	
	//Datos por defecto de nodo sin dato
	CNodo::CNodo(int ele)
	{
		dato=ele;
		sig=NULL;
	}
	
	//Mmostramos la estructura del nodo
	void CNodo::mostrarNodo()
	{
		cout<<dato<<" - ";
	}
	
	//Eliminacion Del Nodo
	void CNodo::eliminarNodo()
	{
		delete this;	
	}
	
	#endif
