#include <iostream>
#include "Clista.h"

int main(int argc, char** argv){
 
///Hacer tabla hash

Clista tabla[10];
int opc1,opc2;

int clave, pos;

        do{
        cout<<"Menu Hashing modular"<<endl;
        cout<<"1.-Insertar"<<endl;
        cout<<"2.-Eliminar"<<endl;
        cout<<"3.-Buscar"<<endl;
        cout<<"4.-Imprimir"<<endl;
        cout<<"5.-Salir"<<endl;
        cout<<"Elija su operacion: ";
        cin>>opc2;

        switch (opc2){
            case 1:{
            cout<<"Da la clave a insertar"<<endl;
            cin>>clave;
            //transormar clave
            pos=clave%10;
            tabla[pos].insertarNodoInicio(clave);
            break;
            }

            case 2:{
            cout<<"Da la clave a eliminar: ";
            cin>>clave;
            //transformar clase
            pos=clave%10;
            tabla[pos].eliminarNodoDato(clave);//eliminar dato general
            cout<<endl;
            break;
            }

        case 3:{
            cout<<"Da la clave a buscar: ";
            cin>>clave;
            //trasformar clase
            pos=clave%10;
            tabla[pos].buscarNodoVal(clave);//buscar nodo actual
            break;

        } 

        case 4:{
        int i;
        cout<<"Imprimir Tabla"<<endl;
        for(i=0;i<10;i++){
            tabla[i].mostrarLista();
            cout<<endl;
            }
        break;
        }




        }
    }while(opc2!=5);


}

