#include <iostream>
#include "Clista.h"

using namespace std;

//Hacemos la clase pila, en vase a la lista

class CPilaD{
	public:
		Clista l;
		
	//Metodos usados
	public:
		
		CPilaD();
		void push(int e);
		void pop();
		void mostrarPila();
};

//Metodo Vacio Constructor
CPilaD::CPilaD(){
}

//Asignamos de funciones de la Clista a nuestra estructura de PIla dinamica
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
	//Iniciamos el objeto CPILA
	CPilaD PD;
	int opc,e;
	//Menu
	do{
		cout<<"Menu Pila"<<endl;
		cout<<"1.-Insertar/Push"<<endl;
		cout<<"2.-Eliminar/Pop"<<endl;
		cout<<"3.-Mostrar Pila Dinamica"<<endl;
		cout<<"4.-Salir"<<endl;
		cout<<"Tarea a realizar: ";
		cin>>opc;
		
		//Seleccion
		
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
	
	
