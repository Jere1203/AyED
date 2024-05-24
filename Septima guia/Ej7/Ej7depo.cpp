/*b) El dueño de un local de venta de libros desea relevar el stock que posee en el local y en el depósito, para realizar las
compras del mes.
Para ello cuenta con dos archivos:
StockEnDeposito.dat, ordenado por código del libro, con un registro por cada libro que se encuentra en el
depósito, con el siguiente diseño:
b.1) Código de libro b.2) Stock en depósito*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct libro
{
    unsigned codLibro;
    unsigned stock;
};
int main()
{
    FILE *aDep;
    aDep=fopen("StockEnDeposito.dat","wb");
    if(aDep!=NULL)
    {
        libro book;
        cout<<"Ingrese codigo de libro (0 para finalizar)"<<endl;
        cin>>book.codLibro;
        while(book.codLibro<0) cin>>book.codLibro;
        while(book.codLibro>0)
        {
            cout<<"Ingrese stock"<<endl;
            fwrite(&book,sizeof(libro),1,aDep);
            cout<<"Ingrese codigo de libro (0 para finalizar)"<<endl;
            cin>>book.codLibro;
        }
    }
    else cout<<"ERROR"<<endl;
    fclose(aDep);
    getch();
}