/*El dueño de un local de venta de libros desea relevar el stock que posee en el local y en el depósito, para realizar las
compras del mes.
Para ello cuenta con dos archivos:
a) StockEnLocal.dat, ordenado por código del libro, con un registro por cada libro que se encuentra en el
local, con el siguiente diseño:
a.1) Código de libro            a.2) Título del libro (30 caracteres)
a.3) Autor (20 caracteres)      a.4) Editorial (20 caracteres)
a.6) Stock en el local          a.7) Genero ( 10 caracteres)*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct libro
{
    unsigned codLibro;
    char titulo[30];
    char autor[20];
    char edit[20];
    unsigned stock;
    char genero[10];
};

int main()
{
    FILE *aLocal;
    aLocal=fopen("StockEnLocal.dat","wb");
    if(aLocal!=NULL)
    {
        libro book;
        cout<<"Ingrese codigo de libro (0 para finalizar el ingreso)"<<endl;
        cin>>book.codLibro;
        while(book.codLibro<0) cin>>book.codLibro;
        while(book.codLibro>0)
        {
            cout<<"Ingrese titulo del libro"<<endl;
            fflush(stdin);
            cin.getline(book.titulo,30);
            cout<<"Ingrese autor"<<endl;
            fflush(stdin);
            cin.getline(book.autor,20);
            cout<<"Ingrese editorial"<<endl;
            fflush(stdin);
            cin.getline(book.edit,20);
            cout<<"Ingrese stock"<<endl;
            cin>>book.stock;
            cout<<"Ingrese genero"<<endl;
            fflush(stdin);
            cin.getline(book.genero,10);
            fwrite(&book,sizeof(libro),1,aLocal);
            cout<<"Ingrese codigo de libro (0 para finalizar el ingreso)"<<endl;
            cin>>book.codLibro;
        }
    }
    else cout<<"ERROR"<<endl;
    fclose(aLocal);
    getch();
}