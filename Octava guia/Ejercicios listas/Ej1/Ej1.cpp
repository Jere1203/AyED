/*Se tiene ordenada por código de producto una lista simplemente enlazada donde cada nodo
contiene: código, descripción, importe y stock.
Hacer funciones para:
a. dado un entero K, imprimir el k-ésimo elemento.
b. incrementar en un 10% el importe de un producto dado su código.
c. devolver el stock de un producto dado ó cero si no se lo encuentra.*/
#include<iostream>
#include<conio.h>
using namespace std;
struct producto
{
    int cod,importe,stock,pos;
    char desc[10];
};
struct Nodo
{
    producto info;
    Nodo*sig;
};
Nodo* buscarSecuencial(Nodo*lista,unsigned unLeg);
void insertar(Nodo*&lista,producto prod);
void listar(Nodo*lista);
Nodo* buscarSecMejorada(Nodo*lista,unsigned unLeg);
void modificarPrecio(Nodo*lista,int unCod);
int buscarStock(Nodo*lista,unsigned unCod);
int buscarK(Nodo*&lista,int k);
int main()
{
    Nodo *lprod=NULL;
    producto prod;
    unsigned k;
    cout<<"CODIGO: "<<endl;
    cin>>prod.cod;
    while(prod.cod!=0)
    {
        cout<<"DESC: "<<endl;
        cin>>prod.desc;
        cout<<"IMPORTE: "<<endl;
        cin>>prod.importe;
        cout<<"STOCK: "<<endl;
        cin>>prod.stock;
        cout<<"POSICION: "<<endl;
        cin>>prod.pos;
        insertar(lprod,prod);
        cout<<"CODIGO: "<<endl;
        cin>>prod.cod;
    }
    //listar(lprod);
    cout<<"Ingrese K para buscar un elemento en la lista"<<endl;
    cin>>k;
    cout<<"El elemento buscado es: "<<endl;
    cout<<buscarK(lprod,k);
    cout<<"Ingrese codigo para incrementar el precio un 10%"<<endl;
    cin>>k;
    modificarPrecio(lprod,k);
    cout<<"Ingrese codigo para buscar stock"<<endl;
    cin>>k;
    if(buscarStock(lprod,k)!=0) cout<<"STOCK: "<<buscarStock(lprod,k)<<endl;
    else cout<<"NO HAY STOCK"<<endl;
    getch();
}

void listar(Nodo*lista)
{
    Nodo*p;
    p=lista;
    while(p!=NULL)
    {
        //cout<<p->info.pos<<p->info.cod<<p->info.desc<<p->info.importe<<p->info.stock<<endl;
        cout<<p->info.pos<<p->info.desc<<p->info.cod<<p->info.importe<<p->info.stock<<endl;
        p=p->sig;
    }
}
int buscarK(Nodo*&lista,int k)
{
    //solo para buscar por lo que est� ordenado
    Nodo*p=lista;
    while(p!=NULL && p->info.pos<k)
        p=p->sig;
    if(p==NULL || p->info.pos!=k)
        cout<<"NO SE ENCUENTRA EL PRODUCTO"<<endl;
    else
        listar(p);
    
}
void insertar(Nodo*&lista,producto prod)
{
    Nodo*n,*p,*ant;
    n=new Nodo;
    n->info=prod;
    p=lista;
    while(p!=NULL && p->info.cod<prod.cod)
    {
        ant=p;
        p=p->sig;
    }
    n->sig=p;
    if(p!=lista)
        ant->sig=n;
    else
        lista=n;
}

Nodo* buscarSecuencial(Nodo*lista,unsigned pos)
{
    //devuelve el puntero al nodo con leg unLeg y NULL
    //si no hay un nodo con el unLeg
    Nodo*p=lista;
    while(p!=NULL && p->info.pos!=pos)
        p=p->sig;
    return p;
}

Nodo* buscarSecMejorada(Nodo*lista,unsigned unCod)
{
    //solo para buscar por lo que est� ordenado
    Nodo*p=lista;
    while(p!=NULL && p->info.cod<unCod)
        p=p->sig;
    if(p==NULL || p->info.cod!=unCod)
        return NULL;
    else
        return p;
}

void modificarPrecio(Nodo*lista,int unCod)
{
    Nodo*p;
    p=buscarSecMejorada(lista,unCod);
    if(p!=NULL) 
    {
        cout<<"PRECIO ANTERIOR: "<<endl;
        cout<<p->info.importe<<endl;
        p->info.importe*=1.10;
        cout<<"PRECIO ACTUALIZADO: "<<endl;
        cout<<p->info.importe<<endl;
    }
    else cout<<"NO SE ENCUENTRA EL PRODUCTO"<<endl;   
}

int buscarStock(Nodo*lista,unsigned unCod)
{
    Nodo*p=buscarSecMejorada(lista,unCod);
    if(p!=NULL)
    {
      if(p->info.stock>0) return p->info.stock;
      else return 0;
    }
}