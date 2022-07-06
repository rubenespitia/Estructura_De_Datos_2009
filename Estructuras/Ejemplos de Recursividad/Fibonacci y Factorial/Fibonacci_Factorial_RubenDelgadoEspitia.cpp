#include <iostream>
using namespace std;


long fibonacci(long n){
	long var;
	if(n==0||n==1)
	{
		return n;
		
	}
	
	else{
		return fibonacci(n-1)+fibonacci(n-2);
	}
}


double factorial(double numero)
{
 if (numero > 1)
 return numero * factorial(numero-1);
 return 1;
}




int main(){
int opc;
double numero;
long n;
long f1;
double f2;


do{
cout<<"Menu"<<endl;
cout<<"1.-Fibonacci"<<endl;
cout<<"2.-Factorial"<<endl;
cout<<"3.-Salir"<<endl;
cout<<endl<<"Ingrese opcion: ";
cin>>opc;

switch(opc)
{
	case 1:{
		cin>>n;
		f1=fibonacci(n);
		cout<<f1;
		cout<<endl;
		break;
	}
	
	case 2:{
		cin>>numero;
		f2=factorial(numero);
		cout<<f2;
		cout<<endl;
		break;
	}
	
}



}while(opc!=3);


}
