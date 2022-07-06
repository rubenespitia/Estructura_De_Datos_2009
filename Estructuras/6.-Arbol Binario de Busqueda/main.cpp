#include <iostream>
#include <cstdlib>
using namespace std;


///////////////////Definimos los datos del nodo
struct nodo{
     int nro;
     struct nodo *izq, *der;
};

typedef struct nodo *ABB;
// es un puntero de tipo nodo que hemos llamado ABB

////////////////////////////Creacion de un nodo nuevo
ABB crearNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}


void insertar(ABB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}

void postOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}

void verArbol(ABB arbol, int n)
{
     if(arbol==NULL){
	 	return;
	 	}  
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
}

int main()
{
    ABB arbol = NULL;   //Arbol desde 0

    int n;  // numero de nodos 
    int x; // elemento x
    
    cout << "Cantidad de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " Numero del nodo " << i+1 << ": ";
        cin >> x;
        insertar( arbol, x);
    }
    cout << endl << endl;
    cout << "Arbol ABB";
    cout << endl << endl;
    verArbol( arbol, 0);
    cout << endl << endl;
    
    cout << "Recorridos del ABB";

    cout << endl << endl << "Inorden   :  ";  
	enOrden(arbol);
    cout << endl << endl << "PreOrden  :  ";
	preOrden(arbol);
    cout << endl << endl << "PostOrden :  ";   
	postOrden(arbol);

    cout << endl << endl;

    system("pause");
    return 0;
}
