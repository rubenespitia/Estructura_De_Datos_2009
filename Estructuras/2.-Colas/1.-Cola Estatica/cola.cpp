#include <iostream>
#define tam 3

using namespace std;

class CCola{
	//definir atributos
	public:
		int frente;
		int fin;
		int arreglo[tam];
	//definir operaciones
	public:
		CCola();
		void instertarElementoCola(int ele);
		int sacarElementoCola();
		int esColaVacia();
		int esColaLlena();
		int getFrente();
		int getFinal();
		void mostrarElementosCola();
	
};
		///Metodo Constructor que define frente y final de la cola 
		CCola::CCola()
		{
			frente=0;
			fin=0;
		}
		
		
		//Inserta un elemento al final mientras la cola no sea llena al final del arreglo
		void CCola::instertarElementoCola(int ele)
		{
			if(esColaLlena()==0)
			{
				arreglo[fin]=ele;
				fin=fin+1;
			}
			else
			{
				cout<<"Imposible insertar un elemento mas";
			}
			
		}
		

		
		
		//Se elimina un elemento de la cola mientras esta no sea vacia, se elimina el elemento que esté al frente del arreglo y el nuevo elemento que está alfrente es el que seguia en el arreglo
		int CCola::sacarElementoCola()
		{
			if (esColaVacia() == 0)
			{
				frente = frente + 1;
				return arreglo[frente-1];
			}
			else //Si la cola es vacia no hace nada
			{
				cout<<"Imposible sacar cola vacia";
				return 0;
			}
			
		}
		
		
		
		//Si el frente llega a ser el fin, la cola se considera vacia y se regresa un 1 
		int CCola::esColaVacia()
		{
		
		if(frente==fin)
		{
			return 1;
		}
			
			else
			{
				return 0;
			}
		}
		
		
		
		//Si el fin es igual al tamaño asignado  se condiera llena la estructura
		int CCola::esColaLlena()
		{
			if(fin == tam)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
		
		//Obtenemos del arreglo el valor posicionado en lo que consideramos enfrente
		int CCola::getFrente()
		{
			cout<<arreglo[frente];
		}
		
		
		//Obtenemos la posicion final del arreglo.
		int CCola::getFinal()
		{
			cout<<arreglo[fin-1];
		}
		
		
		//Imprimimos por orden con un for el arreglode la estructura
		void CCola::mostrarElementosCola()
		{
			int i;
			cout<<"Los elementos en la cola son :"<<endl;
			for (i=frente; i<fin; i++)
			{
				cout<<arreglo[i]<<" , ";
			}
		}





int main()
{
	int oper=0, x=0;
	//Iniciamos el tipo de dato Clase Cola como C1
	CCola C1;
	do{
		
		
		//Menu
		
	cout<<"Seleccione el num de operacion"<<endl;
	cout<<"1.-Insertar datos"<<endl;
	cout<<"2.-Eliminar datos"<<endl;
	cout<<"3.-Tener frente"<<endl;
	cout<<"4.-Tener Fin"<<endl;
	cout<<"5.-Tener todos los elementos"<<endl;
	cout<<"6.-Salir"<<endl;
	cin>>oper;
	
	
	//Seleccion de operaciones
	switch(oper)
	{
		case 1:{
		cout<<"Ingresa elemento que se quiere agregar: ";
		cin>>x;
		C1.instertarElementoCola(x);
			
			break;
		} 
		case 2: C1.sacarElementoCola();
		break;	
		case 3: C1.getFrente();
		break;
		case 4: C1.getFinal();
		break;
		case 5: C1.mostrarElementosCola();
		break;
		
	}
	cout<<endl<<"Quiere salir?, presione 6 para salir, cualquier otro para no: ";
	cin>>oper;
	system("CLS");
	
}while(oper!=6);
	
	
	
	
	return 0;
}
