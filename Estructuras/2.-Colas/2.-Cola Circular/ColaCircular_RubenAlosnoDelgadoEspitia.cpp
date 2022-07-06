#include <iostream>
#define tam 3

using namespace std;

class CCola{
	//definir atributos
	public:
		int frente;
		int fin;
		int arreglo[tam];
		int num;
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
		//Definimos el constructor vacion de la Cola Circular
		CCola::CCola()
		{
			frente=0;
			fin=0;
			num=0;
		}
		
		
		void CCola::instertarElementoCola(int ele)
		{
			if(esColaLlena()==0) //Mientras la Cola no esté llena
			{
				//Si el fin de nuestra Cola es el último elemento equivalente al último espacio. El el fin de nuestra cola se hace el primer espacio del arreglo
				if(fin==3)
				{
				fin=0;
				}
				arreglo[fin]=ele;
				fin=fin+1;
				num=num+1;
			}
			else
			{
				cout<<"Imposible insertar un elemento mas";
			}
			
		}
		
		
		
		
		int CCola::sacarElementoCola()
		{
			if (esColaVacia() == 0) //Mientras cola no sea vacia
			{
			//Nuestro frente se convierte en el siguiente elemento del elemento que sale
				frente = frente + 1;
				num=num-1;
				arreglo[frente-1]=0;
				if(frente==3)////Si el frente llega a 3 y se elimina este elemento, el frente es el principio del arreglo
				{
				frente=0;
				}
			}
			else
			{
				cout<<"Imposible sacar cola vacia";
				return 0;
			}
			
		}
		
		
		
	//Verifica que la estructura no esté Vacia comparando el numero de datos incertados con 0.
		int CCola::esColaVacia()
		{
		
		if(num<=0)
		{
			return 1;
		}
			
			else
			{
				return 0;
			}
		}
		
		
		
		//Verifica que la cola no esté llena comparando el numero de datos insertados con el tamaño del arreglo
		int CCola::esColaLlena()
		{
			if(num>=tam)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
		
		//Obtenemos el frente considerado de la lista
		int CCola::getFrente()
		{
			cout<<arreglo[frente];
		}
		
		
		//Obtenemos el fin considerado de la lista
		int CCola::getFinal()
		{
			cout<<arreglo[fin-1];
		}
		
		
		//Imprime los elementos de la lista
		void CCola::mostrarElementosCola()
		{
			int i;
			cout<<"Los elementos en la cola son :"<<endl;
			for (i=0; i<3; i++)
			{
				cout<<arreglo[i]<<" , ";
			}
		}





int main()
{
	int oper=0, x=0;
	//Inicia la estructura de la COLA
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
	
	//Selecciona las opciones
	
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
		case 3:cout<<"Su elemento frente es: "; C1.getFrente();
		break;
		case 4:cout<<"Su elemento final es: "; C1.getFinal();
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
