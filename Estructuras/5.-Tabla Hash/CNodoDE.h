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

	CNodoDE::CNodoDE()
	{
		ant=NULL;
		dato=0;
		sig=NULL;
	}
	
	
	CNodoDE::CNodoDE(int ele)
	{
		ant=NULL;
		dato=ele;
		sig=NULL;
	}
	
	void CNodoDE::mostrarNodoDE()
	{
		cout<<dato<<" - ";
	}
	void CNodoDE::eliminarNodoDE()
	{
		delete this;	
	}
	
	#endif
