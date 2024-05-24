/*Una compañía que ofrece préstamos a sus clientes a pagar en 12 meses, desea
obtener un listado con los códigos de clientes y los números de las cuotas
adeudadas de aquellos clientes que adeuden cuotas, ordenado por código de
cliente. Para ello cuenta con un archivo de cobranzas, sin ningún orden, con el
siguiente diseño:
Código de cliente (int)
Número de cuota (1 a 12)*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct cobranzas
{
    int codCliente,cuota;
};

int main()
{
    FILE *archCobranzas;
    cobranzas cob;
    archCobranzas=fopen("Cobranzas.dat","wb");
    cout<<"CODIGO: "<<endl;
    cin>>cob.codCliente;
    while(cob.codCliente!=0)
    {
        cout<<"CUOTAS ADEUDADAS: "<<endl;
        cin>>cob.cuota;
        fwrite(&cob,sizeof(cobranzas),1,archCobranzas);
        cout<<"CODIGO: "<<endl;
        cin>>cob.codCliente;
    }
    fclose(archCobranzas);
    getch();
}