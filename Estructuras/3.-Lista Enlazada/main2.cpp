#include <iostream>
#include "Clista.h"

using namespace std;

int main ()
{
	//Inicializamos el objeto de la clase
	Clista L;
	int opc, e;
	
	//Menu
	do
	{
		cout<<endl<<"Menu Lista"<<endl;
		cout<<endl<<"1.-Generar Lista"<<endl;
		cout<<endl<<"2.-Insertar al Final"<<endl;
		cout<<endl<<"3.-Eliminar al Final"<<endl;
		cout<<endl<<"4.-Buscar por posicion"<<endl;
		cout<<endl<<"5.- Mostrar Lista"<<endl;
		cout<<endl<<"6.-Intertar al Inicio"<<endl;
		cout<<endl<<"7.-Eliminar al Inicio"<<endl;
		cout<<endl<<"8.-Buscar por numero"<<endl;
		cout<<endl<<"9.-Ordenar"<<endl;
		cout<<endl<<"10.-Salir"<<endl;
		cout<<endl<<"Selecciona un apara realizar "<<endl;
		
	cin>>opc;
	switch(opc)
	{
		case 1:{
			L.generarLsita();
			break;
		}
		
		case 2:{
			cout<<"Da el valor del Nodo a Insertar:";
			cin>>e;
			L.insertarNodoFinal(e);
			break;
		}
		
		case 3:{
			L.eliminarNodoFinal();
			break;
		}
		
		case 4:{
			cout<<"Da la posicion a buscar: ";
			cin>>e;
			L.buscarNodoPos(e);
			break;
		}
		
		case 5:{
			L.mostrarLista();
			break;
		}
		
			case 6:{
			cout<<"Da el valor del Nodo a Insertar: ";
			cin>>e;
			L.insertarNodoInicio(e);
			break;
		}
		
			case 7:{
			L.eliminarNodoInicio();
			break;
			}
		

		case 8:{
			cout<<"Da el valor a buscar: ";
			cin>>e;
			L.buscarNodoVal(e);
			break;
		}
		
			case 9:{
			L.OrdenarBurbuja();
			break;
		}

	}
	
}while(opc!=10);

	return 0;
	

	
	
}
