#include <iostream>
#include "Clista.h"

using namespace std;

class CPilaD{
	public:
		Clista l;
		
	public:
		
		CPilaD();
		void push(int e);
		void pop();
		void mostrarPila();
};

CPilaD::CPilaD(){
}

void CPilaD::push(int e)
{
	l.insertarNodoFinal(e);
	
}

void CPilaD::pop()
{
	
	l.eliminarNodoFinal();
}

void CPilaD::mostrarPila()
{
	cout<<"La Pila dinamica es: "<<endl;
	l.mostrarLista();
}


int main(int argc, char **argv) {
	
	CPilaD PD;
	int opc,e;
	
	do{
		cout<<"Menu Pila"<<endl;
		cout<<"1.-Insertar/Push"<<endl;
		cout<<"2.-Eliminar/Pop"<<endl;
		cout<<"3.-Mostrar Pila Dinamica"<<endl;
		cout<<"4.-Salir"<<endl;
		cout<<"Tarea a realizar: ";
		cin>>opc;
		
		
		switch (opc){
			case 1:{
				cout<<"Da el elemento a ingresar: ";
				cin>>e;
				PD.push(e);
				cout<<endl;
				break;
			}
			
			case 2:{
				PD.pop();
				cout<<endl;
				break;
			}
			
			case 3:{
				PD.mostrarPila();
				cout<<endl<<endl;
				break;
			}
			
		}
	}while(opc!=4);
	
	return 0;
		
		
		
		
		
		
		
	}
	
	
