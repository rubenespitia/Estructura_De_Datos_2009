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

//Metodo Constructor
	CNodo::CNodo()
	{
		dato=0;
		sig=NULL;
	}
	
	//Constructor con elemento
	CNodo::CNodo(int ele)
	{
		dato=ele;
		sig=NULL;
	}
	
	//Mostrando Elementos
	void CNodo::mostrarNodo()
	{
		cout<<dato<<" - ";
	}
	
	//EliminandoNodos
	void CNodo::eliminarNodo()
	{
		delete this;	
	}
	
	#endif
