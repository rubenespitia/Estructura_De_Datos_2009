#ifndef CAB_LISTADE
#define CAB_LISTADE

#include <iostream>
#include "CNodoDE.h"
using namespace std;

class ClistaDE{
	//atributos
	public:
		CNodoDE *primerNodo;
		int numNodos;
		
	//metodos
	ClistaDE();
	void generarListaDE();///////////////////Listo
	void insertarNodoDEFinal(int ele);///////////////////Listo
	void insertarNodoDEInicio(int ele);////////////////////////listo
	int eliminarNodoDEFinal();//////////////////////////listo
	int eliminarNodoDEInicio();//////////////////////// listo
	int buscarNodoDEAnterior(int ele);
	int buscarNodoDESiguiente(int ele);
	void mostrarListaDEIzqDer();//////////////////////////Listo
	void mostrarListaDEDerIzq();////////////////////////Listo
	void ordenarListaDE();///////////////////////Listo
};




	ClistaDE::ClistaDE()
	{
		numNodos=0;
		primerNodo=NULL;
	}


	
		void ClistaDE::insertarNodoDEInicio(int ele)//Insertamos Nodo al Inicio
	{
		CNodoDE *temp=primerNodo;
		CNodoDE *nuevo= new CNodoDE(ele);
		
		if(primerNodo==NULL) //Si es nulo el primer nodo, el dato ingresado será declarado como el primer nodo
		{
			primerNodo=nuevo;
			numNodos=numNodos+1;
		}
		else // Si no es el primer nodo, se le asignan las direcciones del dato anterior y siguiente, junto con el valor del nuevo elemento
		{
			nuevo->sig=primerNodo;
			primerNodo->ant= nuevo;
			primerNodo = nuevo;
			numNodos=numNodos+1;
		}
		
	}
	
	
	
			
	int ClistaDE::eliminarNodoDEInicio()//Eliminamos el nodo de inicio
	{
		CNodoDE *temp=new CNodoDE();
		
				if(primerNodo==NULL) //Si no hay primer nodo, no podemos eliminar nada
		{
			cout<<"No hay elementos en la lista"<<endl;
			
		}
		else //So existe el primer nodo, pasamos los datos de primer nodo al siguiente, asignamos valores al siguiente nodo 
		{
			temp=primerNodo;
			primerNodo=primerNodo->sig;
			primerNodo->ant=NULL;
			temp->eliminarNodoDE();
			numNodos=numNodos-1;
			cout<<endl<<"Nodo inicial eliminado"<<endl;
		}
		 
	}
	
	
	
	
	void ClistaDE::mostrarListaDEDerIzq()///////////////////////Listo
	{
		CNodoDE *temp=primerNodo;
		if(numNodos==0)
		{
			cout<<"No hay elementos"<<endl;
		}	
		else
		{
			while(temp->sig!=NULL)
			{
				temp=temp->sig;
				
			}
			
			while(temp->ant!=NULL)
			{
				temp->mostrarNodoDE();
				temp=temp->ant;
				
			}
			temp->mostrarNodoDE();
			cout<<endl;
			
		}
	}
	
	



	void ClistaDE::mostrarListaDEIzqDer()//////////////////Listo
	{
		CNodoDE *temp=primerNodo;
		
		if(numNodos==0)
		{
			cout<<"No hay elementos"<<endl;
		}	
		else
		{

			while(temp->sig!=NULL)
			{
				temp->mostrarNodoDE();
				temp=temp->sig;
				
			}
			temp->mostrarNodoDE();
			cout<<endl;
			
		}
	}




	void ClistaDE::insertarNodoDEFinal(int ele)//Asignamos el elemento final
	{
		CNodoDE *temp=primerNodo;
		CNodoDE *nuevo= new CNodoDE(ele);
		
		if(primerNodo==NULL)//Si no hay nodos, agregamos este como el primer nodo
		{
			primerNodo=nuevo;
			numNodos=numNodos+1;
		}
		else //En cualquier otro caso
		{	
		while(temp->sig!=NULL)//Se recorre la estructura hasta que la direccion del siguiente dato es nullo, asi asignamos el nuevo nodo al final de la estructura
			{
				temp= temp ->sig;
			}
			temp->sig=nuevo;
			nuevo->ant=temp;
			numNodos=numNodos+1;
		}
}
		
		
		
		
	int ClistaDE::eliminarNodoDEFinal()////////////////////listo
	{
		CNodoDE *actual =new CNodoDE();
		CNodoDE *anterior=new CNodoDE();
		
		actual=primerNodo;
		anterior=actual;
		
		if(primerNodo==NULL) //Si lista esta vacia no eliminamos nada
		{
			cout<<"No hay elementos en la lista"<<endl;
			
		}
		else
		
		while(actual->sig!=NULL) //Recorre la estructura hasta encontrar el ultimo nodo y eliminarlo
		{
		anterior=actual;
		actual=actual->sig;
		}
		
		anterior->sig=NULL;
		actual->eliminarNodoDE();
		numNodos=numNodos-1;
		//agregar
		if(numNodos==0)
		{
			primerNodo=NULL;
		}
		 
	}
	




	void ClistaDE::ordenarListaDE()/////////////listo
	{
		CNodoDE *temp=primerNodo;
		CNodoDE *nuevo= new CNodoDE();
		int i=0,n,arreglo[50],aux,j;
		
		if(primerNodo==NULL)
		{
			cout<<"No hay elementos en la lista"<<endl;
		}
		else
		{
			i=0;
		
		while(temp->sig!=NULL)
		{
			arreglo[i]=temp->dato;
			i=i+1;
			temp=temp->sig;	
		}
		arreglo[i]=temp->dato;
		
		n=i;
			
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arreglo[j]>arreglo[j+1])
			{
				aux=arreglo[j];
				arreglo[j]=arreglo[j+1];
				arreglo[j+1]=aux;
			}
		}
	}
		temp=primerNodo;
		i=0;
	
		while(temp->sig!=NULL)
		{
			temp->dato=arreglo[i];
			i=i+1;
			temp=temp->sig;	
			
		}
		temp->dato=arreglo[i];	
		}
	}

	void ClistaDE::generarListaDE() //Generamos la lista aplicando la funcion de insertar nodo
	{
		int opc=1,e;
		
		while(opc==1)
		{
			cout<<endl<<"Da el valor del nuevo modo ";
			cin>>e;
			insertarNodoDEFinal(e);
			cout<<endl<<"Deseas seguir insertando nodos si=1 ";
			cin>>opc;
		}
	}



	int ClistaDE::buscarNodoDEAnterior(int ele)  //Buscamos valor del nodo que se nos ordene
	{
		CNodoDE *temp=primerNodo;
		int valor;

		if(primerNodo==NULL||ele==1)
		{
			cout<<"No hay elementos en la lista"<<endl;
			
		}

	else
		{
		for(int i;i<ele;i++)
		{
			temp=temp->sig;
		}
		
		valor=temp->dato;
		
		cout<<"tu valor en una posicion anterior es: "<<valor;
		
		
		}
	}




#endif
