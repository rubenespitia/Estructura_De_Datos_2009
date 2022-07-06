# include <iostream>

using namespace::std;

void Mover_Torres(int N, int Torre1, int Torre2, int Torre3)

{ 

	if ( N > 1 )
	{
	Mover_Torres( N - 1, Torre1, Torre3, Torre2);
	cout <<"Mueve el disco " <<  N  << " de " << Torre1 << " a " <<  Torre3 << endl;
	Mover_Torres( N - 1, Torre2, Torre1, Torre3);
	}	 


	if ( 1 == N )
	cout << "Mueve el disco 1 de " << Torre1 << " a " << Torre3 << endl;

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
