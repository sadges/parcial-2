#include <iostream>
#include <conio.h>
using namespace std;
struct nodo{
    int da;
    struct nodo *si;  

};

void insertar(nodo *&li,int n);
void mostrar(nodo*li);
void quickSort(nodo*& li);

void mostrar(nodo *li){
	nodo* act =li;
	while(act !=NULL ){
		cout<<act->da<<"   \n";
		act = act->si;	
	}
}

void quickSort(nodo*& li) {
    if (li == NULL || li->si == NULL) {
        return;
    }

    nodo* p = li;
    li = li->si;

    nodo* mas = NULL;
    nodo* me = NULL;

    while (li != NULL) {
        nodo* sig = li->si;
        if (li->da < p->da) {
            li->si = mas;
            mas = li;
        } else {
            li->si = me;
            me = li;
        }
        li = sig;
    }

    quickSort(mas);
    quickSort(me);

    if (mas == NULL) {
        li = p;
    } else {
        nodo* co = mas;
        while (co->si != NULL) {
            co = co ->si;
        }
        co->si = p;
        li = mas;
    }

    p->si = me;
    
    system ("pause");
}

int main(){
    nodo *li= NULL;
    int nro,b,nu;
    cout<<"cantidad de la lista\n";
    cin>>b;

for (int i=0 ; i < b ; i++)
{
    cout<<"ingrese el valor\n";
    cin>>nro;
    insertar(li,nro); 	
}

int o;
do{	
cout<<"Mostrar lista - 1\n";
cout<<"ordenar por quicksort - 2\n";
cin>>o;


	switch(o){
		case 1: 
		mostrar(li);
		system("pause");
		break;
		case 2:
			quickSort(li);


		system("pause");	
		break;
	}
	system("cls");	

   }while(o !=3);

}

 void insertar(nodo *&li,int n){
 
    nodo *nul = new nodo();
    nul -> da =n;
    nul->si=li;
    li=nul;
   
}




