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
	int buscarNodoDEAnterior(int ele);//////////////////Listo
	int buscarNodoDESiguiente(int ele);//////
	void mostrarListaDEIzqDer();//////////////////////////Listo
	void mostrarListaDEDerIzq();////////////////////////Listo
	void ordenarListaDE();///////////////////////Listo
};



//Metodo constructo de lista vacio
	ClistaDE::ClistaDE()
	{
		numNodos=0;
		primerNodo=NULL;
	}


	
		void ClistaDE::insertarNodoDEInicio(int ele)//////////////Listo
	{
		CNodoDE *temp=primerNodo;
		CNodoDE *nuevo= new CNodoDE(ele);
		
		if(primerNodo==NULL) /////Si no existe primer nodo, se crea uno 
		{
			primerNodo=nuevo;
			numNodos=numNodos+1;
		}
		else // si existen mas elementos se asigna el nuevo nodo como el primero los valores correspondientes, mientras que al anterior se le recorre en la estructura
		{
			nuevo->sig=primerNodo;
			primerNodo->ant= nuevo;
			primerNodo = nuevo;
			numNodos=numNodos+1;
		}
		
	}
	
	
	
			
	int ClistaDE::eliminarNodoDEInicio()///////////////////////////////Listo
	{
		CNodoDE *temp=new CNodoDE();
		
				if(primerNodo==NULL) //No eliminamos nodo si no hay nada 
		{
			cout<<"No hay elementos en la lista"<<endl;
			
		}
		else //Eliminamos el primer nodo, y se le asigna el nuevo valor al nodo siguiente
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




	void ClistaDE::insertarNodoDEFinal(int ele)//////////////listo 
	{
		CNodoDE *temp=primerNodo;
		CNodoDE *nuevo= new CNodoDE(ele);
		
		if(primerNodo==NULL) //Si no hay nodos se crea el nodo inicial
		{
			primerNodo=nuevo;
			numNodos=numNodos+1;
		}
		else
		{	
		while(temp->sig!=NULL) // Mientras existan elementos se recorren los nodos hasta el final para agragar el nuevo elemento
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
		
		if(primerNodo==NULL) //Si no hay nodos no eliminamos nada
		{
			cout<<"No hay elementos en la lista"<<endl;
			
		}
		else
		
		while(actual->sig!=NULL) //Si hay elementos se recorre la estructura hasta llegar al final y eliminar el ultimo elemento
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

	void ClistaDE::generarListaDE() 
	{
		int opc=1,e;
		
		while(opc==1)
		{
			cout<<endl<<"Da el valor del nuevo nodo ";
			cin>>e;
			insertarNodoDEFinal(e);
			cout<<endl<<"Deseas seguir insertando nodos si=1 ";
			cin>>opc;
		}
	}



	int ClistaDE::buscarNodoDEAnterior(int ele) //Dada la posicion dada, accedemos a las direcciones asignadas y sacamos el valor que se nos solicita
	{
		CNodoDE *temp=primerNodo;
		int valor,count=1;

		while(temp->sig!=NULL)
		{
			count=count+1;
			temp=temp->sig;	
		}

		temp=primerNodo;

		if(primerNodo==NULL||ele==1)
		{
			cout<<"No hay elementos en la lista"<<endl;
			
		}

		else if(ele>count)
		{
		cout<<"No existe esa posicion"<<endl;
		}
	
			else
		{
			
		for(int i=1;i<ele;i++)
		{
			temp=temp->sig;
		}
		
		temp=temp->ant;
		valor=temp->dato;
		
		cout<<"tu valor en una posicion anterior es: "<<valor<<endl;
		
		
		}
	}




int ClistaDE::buscarNodoDESiguiente(int ele)//Dada la posicion dada, accedemos a las direcciones asignadas y sacamos el valor que se nos solicita, el siguiente
{
		CNodoDE *temp=primerNodo;
		int valor,count=1;

		while(temp->sig!=NULL)
		{
			count=count+1;
			temp=temp->sig;	
		}

		temp=primerNodo;

		if(primerNodo==NULL)
		{
			cout<<"No hay elementos en la lista"<<endl;
			
		}
	
		else if(ele>=count)
		{
		cout<<"No existe esa posicion"<<endl;
		}	
		
		else
		{
			
		for(int i=1;i<=ele;i++)
		{
			temp=temp->sig;
		}
		
		valor=temp->dato;
		cout<<"tu valor en una posicion anterior es: "<<valor;
		}
}


#endif
