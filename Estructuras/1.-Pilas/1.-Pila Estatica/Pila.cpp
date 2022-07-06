#include <iostream>
#define tam 5
using namespace std;


class CPila
{
	//Declaracion de atributos
	public:
		int arreglo[tam];
		int tope;
	
	//Declaracion de metodos
	public:
		CPila();
		void InsertarPila(int ele);
		int sacarPila();
		int esPilaVacia();
		int esPilallena();
		void mostrarPila();
		int getTopePila();
};


	//Metodo Constructor inicializando su tope en -1
		CPila::CPila()
		{
			tope=-1;
		}



	
		void CPila::InsertarPila(int ele)
		{
			if(esPilallena()==1){
				cout<<"La pila esta llena"<<endl;
			}
			else{

				tope=tope+1;
				arreglo[tope]=ele;
			}
		}
		


		
		int CPila::sacarPila()
		{
			if(esPilaVacia()==0)
			{
				tope=tope-1;
				return (arreglo[tope+1]);
			}
			else
			{
				cout<<"La pila esta vacia"<<endl;
				return 0;
			}
		}


	///////Detectamos el tope de la Pila, si este es igual a -1 se devuelve un valor de 1

		int CPila::esPilaVacia()
		{
			if(tope==-1)
			{
				return 1;
			}
			
			else{
				return 0;
				}
		}


	//////////Esto al ser una pila estatica de 4 espacios, este detecta cuando se llegue al limite de la misma devolviendo un 1
		int CPila::esPilallena()
				{
			if(tope == 4)
			{
				return 1;
			}
			else{
				return 0;
				
			}
		}

		/////Imprimimos los datos de la Pila

		void CPila::mostrarPila()
		{
			int i;
			cout<<"La Pila es:"<<endl;
			for(i=tope; i>=0;i--)
			{
				cout<<arreglo[i]<<endl;
			}
		}

		
		///Obtenemos la parte final de la  pila
		int CPila::getTopePila()
		{
			return arreglo[tope];
		}




int main(){

int oper=0,ele=0;
CPila R2;

do{

cout<<"Elige una operacion"<<endl;
cout<<"1.-Insertar Elemento"<<endl;
cout<<"2.-Sacar Elemento"<<endl;
cout<<"3.-Mostrar Pila"<<endl;


cin>>oper;

switch (oper)
{
	case 1: ;cout<<"Ingresa la variable a ingresar: "; cin>>ele; R2.InsertarPila(ele);
	break;
	case 2: R2.sacarPila();
	break;
	case 3: R2.mostrarPila();
	break;

	default: cout<<"Operacion no valida"<<endl;
	
	
}



cout<<endl<<endl<<"Quieres hacer algun otro proceso? , ingresa 0 para salir o cualquier otro numero para continuar  ";
cin>>oper;
system("CLS");


}while(oper!=0);

return 0;
};
