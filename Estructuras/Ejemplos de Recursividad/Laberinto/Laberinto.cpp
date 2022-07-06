#include <cstdlib>
#include <iostream>
#include <time.h>
#include <windows.h>
#define FIL 20
#define COL 50
using namespace std;

char lab[FIL][COL];
struct recorrido{
       int x;
       int y;
       struct recorrido *sgt;
       };
typedef struct recorrido *Lista;
Lista reco=NULL;
void Inicializar();
void Imprimir();
void GenerarCamino(int i, int j);
int Adelante(int i, int j);
void InsertReco(int x, int y);
bool Verificar(int x, int y);
void GenerarParedes();
void FinGenerar();
int main(int argc, char *argv[])
{
    srand(unsigned(time(NULL)));
    Inicializar();
    int x=1+rand()%FIL-2;
    GenerarCamino(x, 1);
    lab[x][1]='I';
    GenerarParedes();
    FinGenerar();
    Imprimir();
    system("PAUSE");
    system("cls");
    
    if(Adelante(x,1)==0) cout<<"Sin solucion"<<endl;
    else cout<<"Solucion encontrada!!! ^^"<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

void Inicializar()
{
     for(int i=0; i<FIL; i++)
     {
             for(int j=0; j<COL; j++)
             {
                     if(i==0 || j==0 || i==FIL-1 || j==COL-1) lab[i][j]='0';
                     else lab[i][j]=' ';
                     }
             }
     }

void Imprimir()
{
     for(int i=0; i<FIL; i++)
     {
             for(int j=0; j<COL; j++)
             {
                     if(lab[i][j]=='0')cout<<(char)177;
                     else cout<<lab[i][j];
                     }
                     cout<<endl;
             }
     }

void GenerarCamino(int i, int j)
{
     while(j!=COL-2)
     {
             int a=rand()%3;
             switch(a)
             {
                      case 0:
                           if(i+1!=FIL-1 && lab[i+1][j]!='O')
                           {
                                      i++;
                                      lab[i][j]='O';
                                      }
                           break;
                      case 1:
                           if(i-1!=0 && lab[i-1][j]!='O')
                           {
                                     i--;
                                     lab[i][j]='O';
                                      }
                           break;
                      case 2:
                           if(j+1!=COL-1 && lab[i][j+1]!='O')
                           {
                                      j++;
                                      lab[i][j]='O';
                                      if(j==COL-2) lab[i][j]='F';
                                      }
                           break;
                      
                      
                      }                  
                 }//fin while
     }
void GenerarParedes()
{
     int paredes=0;
     while(paredes<100)
     {
                      int x=rand()%FIL;
                      int y=rand()%COL;
                      
                      if(lab[x][y]==' ')
                      {
                                      paredes++;
                                      int lim=1+rand()%10;
                                      int puestas=0;          
                                      switch(rand()%4)
                                      {
                                                       case 0:
                                                            
                                                            while(lab[x][y]==' ')//para arriba
                                                            {
                                                                               if(puestas==lim)break;
                                                                               puestas++;
                                                                               lab[x][y]='0';
                                                                               x--;        
                                                                               }
                                                            break;
                                                       case 1:
                                                            while(lab[x][y]==' ')//para abajo
                                                            {
                                                                               if(puestas==lim)break;
                                                                               puestas++;
                                                                               lab[x][y]='0';
                                                                               x++;      
                                                                               }
                                                            break;
                                                       case 2:
                                                            while(lab[x][y]==' ')//para atras
                                                            {
                                                                               if(puestas==lim)break;
                                                                               puestas++;
                                                                               lab[x][y]='0';
                                                                               y--;        
                                                                               }
                                                            break;
                                                       case 3:
                                                            while(lab[x][y]==' ')//para adelante
                                                            {
                                                                               if(puestas==lim)break;
                                                                               puestas++;
                                                                               lab[x][y]='0';
                                                                               y++;      
                                                                               }
                                                            break;
                                                            }
                                                       }
                                      }
     }
     
void FinGenerar()
{
     for(int i=0; i<FIL; i++)
     {
             for(int j=0; j<COL-1; j++)
             {
                     if(lab[i][j]=='O') lab[i][j]=' ';
                     if(j==COL-2 && lab[i][j]!='F') lab[i][j]='0';
                     if(lab[i][j]=='F')
                     {
                                       lab[i][j+1]='F';
                                       lab[i][j]=' ';
                                       }
                     }
             }
     }
int Adelante(int i, int j)
{
    int re=0;
    if(lab[i][j+1]=='F')
    {
                        lab[i][j]=(char)1;
                        return 1;
                        }
    lab[i][j]=(char)1;
    system("cls");
    Imprimir();
    if(lab[i][j+1]==' ' && re==0 && Verificar(i,j+1)) re=Adelante(i,j+1);//hacia adelante    
    if(lab[i-1][j]==' ' && re==0 && Verificar(i-1,j)) re=Adelante(i-1,j);//hacia arriba
    if(lab[i+1][j]==' ' && re==0 && Verificar(i+1,j)) re=Adelante(i+1,j);//hacia abajo
    //if(lab[i][j-1]==' ' && re==0 && Verificar(i,j-1)) re=Adelante(i,j-1);//hacia atras
    if(re==1) return 1;
    else
    {
        InsertReco(i,j);
        lab[i][j]=' ';
        }
    return 0;    
     }
     
void InsertReco(int x, int y)
{
     Lista q=new (struct recorrido);
     q->x=x;
     q->y=y;
     q->sgt=reco;
     reco=q;
     }

bool Verificar(int x, int y)
{
     Lista q=reco;
     while(q!=NULL)
     {
                   if(q->x==x && q->y==y) return false;
                   q=q->sgt;
                   }
                   return true;
     }
