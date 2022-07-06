#include <iostream>
#include "ClistaDE.h"

using namespace std;

class CPrueba{
	public:
 	ClistaDE a;
		
	public:
		
	CPrueba();
	void IngresarDatosInicio(int ele);
	int EliminarDatosInicio();
	void MostrarIzqDer();
	void MostrarDerIzq();
	void IngresarDatosFinal(int ele);
	int EliinarDatosFinal();
	void Ordenar();
	void generar();
	int Anterior(int ele);
	int Siguiente(int ele);
};

	CPrueba::CPrueba()
	{
	
	}
	

	void CPrueba::IngresarDatosInicio(int ele)
	{
		a.insertarNodoDEInicio(ele);
	}
	
	
	int CPrueba::EliminarDatosInicio()
	{
		a.eliminarNodoDEInicio();
	}
	
	
	void CPrueba::MostrarIzqDer()
	{
		a.mostrarListaDEIzqDer();
	}

	void CPrueba::MostrarDerIzq()
	{
		a.mostrarListaDEDerIzq();
		
	}
	
	void CPrueba::IngresarDatosFinal(int ele)
	{
		a.insertarNodoDEFinal(ele);
	}
	
	int CPrueba::EliinarDatosFinal()
	{
		a.eliminarNodoDEFinal();
		}

	void CPrueba::Ordenar()
{
	a.ordenarListaDE();
}
	
	void CPrueba::generar()
	{
		a.generarListaDE();
	
	}

	int CPrueba::Anterior(int ele)
	{
	a.buscarNodoDEAnterior(ele);
	}
	
	int CPrueba::Siguiente(int ele)
	{
	a.buscarNodoDESiguiente(ele);
	}

////////////////////////////////////////////////////////////////////////Programa principal


int main(int argc, char **argv) 
{
	
	CPrueba PD;
	int opc,e;
	

	do{  
	
	
/////////////////Menu 

	cout<<"Seleccione el num de operacion"<<endl;
	cout<<"1.-Insertar datos Inicio"<<endl;
	cout<<"2.-Eliminar datos Inicio"<<endl;
	cout<<"3.-Mostrar de Izquierda a Derecha"<<endl;
	cout<<"4.-Mostrar de Derecha a Izquierda"<<endl;
	cout<<"5.-Insertar datos Final"<<endl;
	cout<<"6.-Eliminar datos Final"<<endl;
	cout<<"7.-Ordenar Lista"<<endl;
	cout<<"8.-Generar Lista"<<endl;
	cout<<"9.-Buscar anterior"<<endl;
	cout<<"10.-Buscar siguiente"<<endl;
	cout<<"11.-Salir"<<endl;
	cin>>opc;
	
	switch(opc)
	{
///////////////operaciones

case 1:{
	cout<<endl<<"Ingrese el valor a insertar: ";
	
	cin>>e;
	PD.IngresarDatosInicio(e);
	break;
}

case 2:{
	PD.EliminarDatosInicio();
	break;
}

case 3:{
	cout<<endl<<"Los numeros acomodados son: "<<endl;
	PD.MostrarIzqDer();
	break;
}

case 4:{
	cout<<endl<<"Los numeros acomodados son: "<<endl;
	PD.MostrarDerIzq();
	break;
}

case 5:{
	cout<<endl<<"Ingrese el valor a insertar: ";
	cin>>e;
	PD.IngresarDatosFinal(e);
	break;
} 


case 6:{
	PD.EliinarDatosFinal();
	break;
}

case 7:{
	PD.Ordenar();
	break;
}

case 8:{
	PD.generar();
	break;
}

case 9:{
	cout<<endl<<"Ingrese la posicion de referencia: ";
	cin>>e;
	PD.Anterior(e);
	break;
} 

case 10:{
	cout<<endl<<"Ingrese la posicion de referencia: ";
	cin>>e;
	PD.Siguiente(e);
	break;
} 

	}
	cout<<endl<<"Quiere salir?, presione 11 para salir, cualquier otro para no: ";
	cin>>opc;
	system("CLS");
	
}while(opc!=11);
	
	return 0;
		
		
		
		
		
		
		
	}
