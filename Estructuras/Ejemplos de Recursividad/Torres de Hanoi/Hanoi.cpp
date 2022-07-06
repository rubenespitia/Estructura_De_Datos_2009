# include <iostream>

using namespace::std;

void Mover_Torres(int N, int Origen, int Intermedio, int Destino)

{ 

	if ( N > 1 )
	{
	Mover_Torres( N - 1, Origen, Destino, Intermedio);
	cout <<"Mueve el disco " <<  N  << " de " << Origen << " a " <<  Destino << endl;
	Mover_Torres( N - 1, Intermedio, Origen, Destino);
	}	 


	if ( 1 == N )
	cout << "Mueve el disco 1 de " << Origen << " a " << Destino << endl;

}


int main()

{ 
int Discos;
cout << "Numero de discos que quiere mover de la pila 1 a la pila 3" << endl;
cin >> Discos;

Mover_Torres( Discos, 1, 2, 3);

cout << endl << endl;

return 0;

} // Ci
