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

//Iniciacion del metodo lista
	Clista::Clista()
	{
		numNodos=0;
		primerNodo=NULL;
	}

//Creamos lista desde 0 
	void Clista::generarLsita()
	{
		int opc=1,e;
		
		while(opc==1)//Generamos la lista con datos hasta que el usuario lo requiera
		{
			cout<<endl<<"Da el valor del nuevo modo ";
			cin>>e;
			insertarNodoFinal(e);
			cout<<endl<<"Deseas seguir insertando nodos si=1 ";
			cin>>opc;
		}

	}
	
	void Clista::insertarNodoFinal(int ele)
	{
		//Tomamos la direccion de primerNodo y el valor que se nos proporciona
		CNodo *temp=primerNodo;
		CNodo *nuevo= new CNodo(ele);
		
		if(primerNodo==NULL)//Si el primer nodo es nulo, agregamos los datos que se nos da y pasamos de tener 0 nodos a 1 nodo.
		{
			primerNodo=nuevo;
			numNodos=numNodos+1;
		}
		else  /////////Si ya existen nodos
		{
			while(temp->sig!=NULL)//Recorremos con un while hasta que la referencia del nodo siguiente sea vacia, asi insertamos el dato que corresponde.
			{
				temp= temp ->sig;
			}
			temp->sig=nuevo;
			numNodos=numNodos +1;
		}
		
	}
	
	
		void Clista::insertarNodoInicio(int ele)
	{
		CNodo *temp=primerNodo;
		CNodo *nuevo= new CNodo(ele);
		
		if(primerNodo==NULL)
		{
			primerNodo=nuevo;
			numNodos=numNodos+1;
		}
		else ///////El nuevo dato le asignamos la direccion de lo que antes era el primer nodo, y los nuevos datos ahora son los primeros en la estructura
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
		
				if(primerNodo==NULL)//Mientras el primer nodo no sea vacio
		{
			cout<<"No hay elementos en la lista"<<endl;
			
		}
		
		else //Eliminamos el primer nodo y se lo asignamos al siguiente que tiene la estructura
		{
			anterior=primerNodo;
			primerNodo=primerNodo->sig;
			anterior->eliminarNodo();
			
			
		}
		
		

		 
	}
	
	
	
	int Clista::buscarNodoVal(int val) //Recorremos la estructura hasta encontrar el valor que queriamos
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
	
		
	int Clista::eliminarNodoFinal() //Eliminamos el nodo final mientras la estructura no sea vacia, asignando el final al dato que estaba antes de este
	{
		CNodo *actual =new CNodo();
		CNodo *anterior=new CNodo();
		
		actual=primerNodo;
		anterior=actual;
		
		if(primerNodo==NULL)
		{
			cout<<"No hay elementos en la lista"<<endl;
			
		}
		else
		
		while(actual->sig!=NULL)
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
	
	int Clista::buscarNodoPos(int pos) //Imprimimos el valor dado la posicicion que nosotros indiquemos, mientras la estructura no sea vacia
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

	void Clista::mostrarLista() //Mostramos toda la lista
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
