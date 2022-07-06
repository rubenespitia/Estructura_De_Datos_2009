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
	int buscarNodoDESiguiente(int ele);//////listo
	void mostrarListaDEIzqDer();//////////////////////////Listo
	void mostrarListaDEDerIzq();////////////////////////Listo
	void ordenarListaDE();///////////////////////Listo
	void remplazarDatoDE(int ele, int pos);////////////Listo
	void eliminarRepetidosDE();
};




	ClistaDE::ClistaDE()
	{
		numNodos=0;
		primerNodo=NULL;
	}



		void ClistaDE::insertarNodoDEInicio(int ele)//////////////Listo
	{
		CNodoDE *temp=primerNodo;
		CNodoDE *nuevo= new CNodoDE(ele);

		if(primerNodo==NULL)
		{
			primerNodo=nuevo;
			numNodos=numNodos+1;
		}
		else
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

				if(primerNodo==NULL)
		{
			cout<<"No hay elementos en la lista"<<endl;

		}
		else
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

		if(primerNodo==NULL)
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
			cout<<endl<<"Da el valor del nuevo modo ";
			cin>>e;
			insertarNodoDEFinal(e);
			cout<<endl<<"Deseas seguir insertando nodos si=1 ";
			cin>>opc;
		}
	}



	int ClistaDE::buscarNodoDEAnterior(int ele)
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




int ClistaDE::buscarNodoDESiguiente(int ele)
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


void ClistaDE::remplazarDatoDE(int ele, int pos)
{
		CNodoDE *temp=primerNodo;
		int count=1;

        while(temp->sig!=NULL)
		{
			count=count+1;
			temp=temp->sig;
		}

		temp=primerNodo;

        if(primerNodo==NULL)
		{
			cout<<"No hay elementos en la lista: "<<endl;
		}


        else if(pos>count||pos<=0)
		{
		cout<<"No existe esa posicion: "<<endl;
		}


		else
		{

		for(int i=1;i<pos;i++)
		{
			temp=temp->sig;
		}

		temp->dato=ele;


		}
}


void ClistaDE::eliminarRepetidosDE()
{
		CNodoDE *temp=primerNodo;
		CNodoDE *antes;
		int valor, rep;

		while(temp->sig!=NULL)
		{

		    valor=temp->dato;
		    cout<<valor<<endl;
		    if(valor==5)
            {
                cout<<"Repetido valor 1"<<endl;/////////////////////////aqui podemos identificar valores dentro de la lista para ver que esta repetido, pero no pude, en ste

            }
            temp=temp->sig;
		}


}

#endif
