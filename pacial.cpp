#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{
     int nro;
     struct nodo *iz, *de;
};

typedef struct nodo *A;


A cn(int x)
{
     A nn = new(struct nodo);
     nn->nro = x;
     nn->iz = NULL;
     nn->de = NULL;

     return nn;
}
void insertar(A &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = cn(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->iz, x);
     else if(x > arbol->nro)
          insertar(arbol->de, x);
}





void ver(A arbol, int n)
{
     if(arbol==NULL)
          return;
     ver(arbol->de, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     ver(arbol->iz, n+1);
}

int main()
{
    A arbol = NULL;   

    int n;  
    int x; 

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " Numero del nodo " << i+1 << ": ";
        cin >> x;
        insertar( arbol, x);
    }

    cout << "\n Mostrando : \n\n";
    ver( arbol, 0);



    cout << endl << endl;

    system("pause");
    return 0;
}