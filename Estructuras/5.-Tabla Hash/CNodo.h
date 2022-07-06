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

	CNodo::CNodo()
	{
		dato=0;
		sig=NULL;
	}
	
	
	CNodo::CNodo(int ele)
	{
		dato=ele;
		sig=NULL;
	}
	
	void CNodo::mostrarNodo()
	{
		cout<<dato<<" - ";
	}
	void CNodo::eliminarNodo()
	{
		delete this;	
	}
	
	#endif
