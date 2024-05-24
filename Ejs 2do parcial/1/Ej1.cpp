/*Una entidad bancaria ofrece diferentes tipos de créditos (personal, hipotecario, etc.).
Se quiere hacer un programa para administrar la asignación de los mismos a las personas que los requieran y
mostrar datos estadísticos.
Los créditos se asignan según los ingresos que han declarado, teniendo prioridad aquellos que tengan el mayor
ingreso promedio.
Se cuenta con los siguientes archivos de datos (binario)

“Inscriptos.dat” con un registro por cada persona que se ha inscripto para solicitar un crédito, con el siguiente
diseño de registro:
    Dni
    Apellido y nombre
    Código del crédito que solicita
    Ingreso Promedio

    “Creditos.dat” con un registro por cada crédito que ofrece la entidad, ordenado por código de crédito, con el
    siguiente diseño de registro:
    Código de crédito
    Descripción
    Cantidad de créditos otorgados hasta el momento

    El programa tiene las siguientes funciones:
    
    Función ingresarCreditos
    El usuario del programa deberá ingresar los diferentes créditos que ofrecen en este mes. Se ingresa por teclado
    código de crédito (debe estar entre los créditos que ofrece la entidad) y la cantidad de personas máxima a los que se
    les otorgará el mismo en este mes (cupo). Con estos datos deberá preparar la estructura para almacenar, luego, los
    inscriptos. El ingreso de datos finaliza con código de crédito cero.

    Función organizarInscriptos
    Procesar los datos del archivo, almacenándolos convenientemente en la estructura de datos para realizar la
    asignación de los créditos.

    Función otorgarCreditos
    Generar el archivo “Otorgados.dat”, con un registro por cada persona a la que se otorgó un crédito, ordenado por
    código de crédito, con el siguiente diseño de registro:
        Código de crédito
        Dni de la persona beneficiaria
        Apellido y nombre

    Se le otorga el crédito a la cantidad de personas que se inscribieron para ese crédito o la cantidad máxima posible,
    según criterio de asignación. Ejemplo: si el crédito tiene un cupo de 10 personas y se inscribieron 8 se le otorgará a
    las 8, si el crédito tiene un cupo de 10 y se inscribieron 15, se le otorgará a los 10 de mayor sueldo.
    Además deberá actualizarse el archivo “Creditos.dat”.
    
    Se pide:
    1) Elegir la estructura más eficiente para procesar la información y realizar lo pedido por el programa. Justificarla.
    2) Declarar todos los struct necesarios.
    3) Desarrollar las tres funciones nombradas.
*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

struct inscriptos
{
    int dni;
    char nomyape[20];
    int codCred;
    int ingProm;
};

struct creditos
{
    int codCred;
    char desc[10];
    int cantOtorg;
    NodoSub *lInsc;
};
struct Nodo
{
    creditos info;
    Nodo*sig;
};
struct NodoSub
{
    inscriptos info;
    NodoSub*sig;
};
void armadoLista(FILE *&archCred,Nodo *&lCred) //bajo a memoria en una lista los creditos del archivo creditos.dat
{
    archCred=fopen("Creditos.dat","rb");
    creditos cred;
    fread(&cred,sizeof(creditos),1,archCred);
    while(!feof(archCred))
    {
        buscarInsertar(lCred,cred);
        fread(&cred,sizeof(creditos),1,archCred);
    }
}

void ingresarCreditos(creditos cred,FILE *&archCred,Nodo *&lCred)
{
    NodoSub *p=NULL;
    cout<<"CODIGO: "<<endl;
    cin>>cred.codCred;
    while(cred.codCred!=0)
    {
        while(buscarSecuencial(lCred,cred.codCred)==NULL)
        {
            cout<<"EL CODIGO INGRESADO NO EXISTE"<<endl;
            cin>>cred.codCred;
        } 
        cout<<"CUPO MAXIMO: "<<endl;
        cin>>cred.cantOtorg;
        insertar2(lCred,cred);
        cout<<"CODIGO: "<<endl;
        cin>>cred.codCred;
    }
}

Nodo *buscarInsertar(Nodo*&lista,creditos cred)
{
    Nodo*ant,*p=lista;
    while(p!=NULL && p->info.codCred<cred.codCred)
    {
        ant=p;
        p=p->sig;
    }
    if(p!=NULL && cred.codCred==p->info.codCred)
    {
        p->info=cred;
        return p;
    }
    else
    {
        Nodo*n=new Nodo;
        n->info=cred;
        n->sig=p;
        if(p!=lista)
            ant->sig=n;
        else
            lista=n;
    }
}

Nodo* buscarSecuencial(Nodo*lista, int codCred)
{
    //devuelve el puntero al nodo con leg unLeg y NULL
    //si no hay un nodo con el unLeg
    Nodo*p=lista;
    while(p!=NULL && p->info.codCred!=codCred)
        p=p->sig;
    return p;
}



/*Función organizarInscriptos
    Procesar los datos del archivo, almacenándolos convenientemente en la estructura de datos para realizar la
    asignación de los créditos.*/
void organizarInscriptos(FILE *&archInsc,Nodo *&lCred,NodoSub *&lIns)
{
    inscriptos ins;
    Nodo *p;
    fread(&ins,sizeof(inscriptos),1,archInsc);
    while(!feof(archInsc))
    {
        p=buscarInsertarInscriptos(lCred,ins);
        insertar(p->info.lInsc,ins);
        fread(&ins,sizeof(inscriptos),1,archInsc);
    }
}

void insertar(NodoSub*&listaIns,inscriptos in)  //ordenado por codigo de credito
{
    NodoSub*n,*p,*ant;
    n=new NodoSub;
    n->info=in;
    p=listaIns;
    while(p!=NULL && p->info.codCred < in.codCred)
    {
        ant=p;
        p=p->sig;
    }
    n->sig=p;
    if(p!=listaIns)
        ant->sig=n;
    else
        listaIns=n;
}
void insertar2(Nodo*&listaIns,creditos cre)  //ordenado por codigo de credito
{
    Nodo*n,*p,*ant;
    n=new Nodo;
    n->info=cre;
    p=listaIns;
    while(p!=NULL && p->info.codCred < cre.codCred)
    {
        ant=p;
        p=p->sig;
    }
    n->sig=p;
    if(p!=listaIns)
        ant->sig=n;
    else
        listaIns=n;
}

Nodo *buscarInsertarInscriptos(Nodo*&lista,inscriptos ins)  //busca por codigo de credito XD
{
    Nodo*ant,*p=lista;
    while(p!=NULL && p->info.codCred<ins.codCred)
    {
        ant=p;
        p=p->sig;
    }
    if(p!=NULL && ins.codCred==p->info.codCred)
    {
        p->info.lInsc->info=ins;
        return p;
    }
    else
    {
        Nodo*n=new Nodo;
        n->info.lInsc->info=ins;
        n->sig=p;
        if(p!=lista)
            ant->sig=n;
        else
            lista=n;
    }
}