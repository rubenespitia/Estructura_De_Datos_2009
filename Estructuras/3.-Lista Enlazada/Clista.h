#ifndef CAB_LISTA
#define CAB_LISTA

#include <iostream>
#include "CNodo.h"
using namespace std;

class Clista{
	//atributos
	public:
		CNodo *primerNodo;
		int numNodos;
		
	//metodos
	Clista();
	void generarLsita();
	void insertarNodoFinal(int ele);
	void insertarNodoInicio(int ele);
	int eliminarNodoFinal();
	int eliminarNodoInicio();
	int buscarNodoPos(int pos);
	int buscarNodoVal(int val);
	void mostrarLista();
	void OrdenarBurbuja();
};

//Clase Constructor de Lista
	Clista::Clista()
	{
		numNodos=0;
		primerNodo=NULL;
	}
	
//metodo donde generamos la lista e insertamos datos hasta que el usuario lo requiera

	void Clista::generarLsita()
	{
		int opc=1,e;
		
		while(opc==1)
		{
			cout<<endl<<"Da el valor del nuevo nodo ";
			cin>>e;
			insertarNodoFinal(e);
			cout<<endl<<"Deseas seguir insertando nodos si=1 ";
			cin>>opc;
		}

	}

//Recorremos la estructura hasta encontrar el nodo final e insertamos el nodo en la direccion de referencia
	void Clista::insertarNodoFinal(int ele)
	{
		CNodo *temp=primerNodo;
		CNodo *nuevo= new CNodo(ele);
		
		if(primerNodo==NULL)//Si no existen nodos lo ingresamos como si fuera el primero
		{
			primerNodo=nuevo;
			numNodos=numNodos+1;
		}
		else
		{
			while(temp->sig!=NULL)
			{
				temp= temp ->sig;
			}
			temp->sig=nuevo;
			numNodos=numNodos +1;
		}
		
	}
	
	
		void Clista::insertarNodoInicio(int ele) //Si no existe nodo colocamos el primero en el nodo inicio
	{
		CNodo *temp=primerNodo;
		CNodo *nuevo= new CNodo(ele);
		
		if(primerNodo==NULL)
		{
			primerNodo=nuevo;
			numNodos=numNodos+1;
		}
		else //Si existen otros datos, asignamos el nuevo dato como el primero en la estructura
		{
			nuevo->sig=primerNodo;
			primerNodo = nuevo;
			numNodos=numNodos+1;
		}
		
	}
	
	
	int Clista::eliminarNodoInicio()
	{
		CNodo *anterior;
		CNodo *siguiente=new CNodo();
		
				if(primerNodo==NULL) ///Si no hay primer nodo no eliminamos nada
		{
			cout<<"No hay elementos en la lista"<<endl;
			
		}
		
		else // Si existen mas datos, hacemos que el nodo siguiente del primero, ahora sea el nuevo primero, y eliminamos el dato actual
		{
			anterior=primerNodo;
			primerNodo=primerNodo->sig;
			anterior->eliminarNodo();
			
			
		}
		
		

		 
	}
	
	
	
	int Clista::buscarNodoVal(int val) //Recorremos la estructura hasta encontrar el valor indicado, mostrara el primero que encuentre
		{
			CNodo *temp=primerNodo;
			int i;
			
			if(primerNodo==NULL)
			{
				cout<<"No hay elementos en la lista"<<endl;
			}
			else
			{
				for(i=1;i<=numNodos;i++)
				{
					if(val==temp->dato)
					{
						cout<<"El elementos en la lista "<<val<<" fue encontrado en la posicion "<<i<<endl;
						return 0;
					}
					
					else
					{
						temp=temp->sig;
					}
				}
			
			
			}
			
			
			
		}
		
	void Clista::OrdenarBurbuja()
	{
		CNodo *temp=primerNodo;
		CNodo *nuevo= new CNodo();
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
		cout<<arreglo[i]<<endl;
		i=i+1;
		temp=temp->sig;	
			
		}
		arreglo[i]=temp->dato;
		cout<<arreglo[i+1]<<endl;
		
		n=i+1;
		
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


		cout<<"Los numeros en la lista en orden ascendente son: (no se reacomoda la lista, solo acomoda valores dentro de la lista)"<<endl;
		for(i=0;i<n;i++)
	{
		cout<<arreglo[i]<<endl;
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
	
		
	int Clista::eliminarNodoFinal()
	{
		CNodo *actual =new CNodo();
		CNodo *anterior=new CNodo();
		
		actual=primerNodo;
		anterior=actual;
		
		if(primerNodo==NULL) //Si no existe el primer nodo no eliminamos nada
		{
			cout<<"No hay elementos en la lista"<<endl;
			
		}
		else
		
		while(actual->sig!=NULL) //Recorremos la estructura hasta poder eliminar el ultimo nodo que no tenga una direccion relacionada siguiente
		{
		anterior=actual;
		actual=actual->sig;
		}
		
		anterior->sig=NULL;
		actual->eliminarNodo();
		numNodos=numNodos-1;
		//agregar
		if(numNodos==0)
		{
			primerNodo=NULL;
		}
		 
	}
	
	int Clista::buscarNodoPos(int pos) //Recorremos la estructura para saber que elemento está en esa posicion
	{
		CNodo *temp=primerNodo;
		int i;
		
		if(primerNodo==NULL)
		{
			cout<<"No hay elementos en la lista";
		}
	
	else
	{
	
		for(i=1;i<=numNodos;i++)
		{
			if(i==pos)
			{
				cout<<"El elemento en la posicion "<<pos<<" es ";
				temp->mostrarNodo();
				cout<<endl;
			}
			
		else
			{
			temp=temp->sig;
			}
		}
		
	}
	}

	void Clista::mostrarLista() //Imprime la lista
	{
		CNodo *temp=primerNodo;
		if(numNodos==0)
		{
			cout<<"No hay elementos"<<endl;
		}	
		else
		{
			while(temp->sig!=NULL)
			{
				temp->mostrarNodo();
				temp=temp->sig;
			}
			temp->mostrarNodo();
		}
	}









#endif
