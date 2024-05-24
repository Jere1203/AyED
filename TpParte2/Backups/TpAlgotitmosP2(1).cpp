#include <iostream>
#include <limits>
#include <string>
#include <cstring>
using namespace std;

struct repartidores
{
    int dni;
    char nombreYapellido[34]; 
    char patente[34]; 
    int codZona; 
    int transporte; 
}; 

struct infoArbol
{
    int cant; 
    int codComercio; 
};

struct arbol
{
    infoArbol data; 
    arbol* derecha; 
    arbol* izquierda;  
};

struct Pedidos
{
    char domicilio [30];
    int zona;
    float volumenPack;
    float importe;
    int codComercio;
};

struct sublistaRep
{
    Pedidos info;
    sublistaRep*sig;    
};

struct listaRep
{
    repartidores info;
    listaRep*sig;
    sublistaRep*ordenes;
};

struct NodoCola
{
    Pedidos info;
    NodoCola*sig;
};

struct Cola
{
    NodoCola*pri;
    NodoCola*ult;
};


bool LeerInt(int&); 
bool LeerFloat(float&); 
void encolar(NodoCola*&, NodoCola*&, Pedidos);
void desencolar(NodoCola*&, NodoCola*&, Pedidos&);

int tipoVehiculo(float);
void pedirDatos(Pedidos&);
bool encolarPedidos(Cola[14][4]);
bool chequeoVehiculos(char[20], int);

bool OpcionDos(repartidores&);
bool chequeoRepartidores(char[20], repartidores&);
void sublistaRepartidores(sublistaRep*&, Pedidos);
void ListaRepartidores(listaRep*&, repartidores, Pedidos);
void RecorrerListaySub (listaRep*);

void ArchvioPendientes (Cola[14][4]);
void insertarEnArbol(arbol*&, int);
void listarIn(arbol*raiz); 

int main()
{
    int menu;
    arbol*arbolComercios=NULL;
    listaRep *lRep=NULL;
    repartidores rep; 
    Pedidos ped; 
    Cola MatPedidos[14][4];
    for(int i=0; i<14; i++) //inicializa las colas de la matriz
    {
        for(int j=0; j<4; j++)
            MatPedidos[i][j].pri=MatPedidos[i][j].ult=NULL;
    }
    
    cout<<"Seleccione una opcion:"<<endl;
    cout<<"1- Recibir un pedido \n2- Asignar pedidos a un repartidor \n3- Mostrar \n4- Salir"<<endl;
    do
    {
        while(!LeerInt(menu))
        {
            cout<<"Ingrese una opcion valida"<<endl;
            LeerInt(menu);
        }
        switch (menu)
        {
            case 1:
                if(encolarPedidos(MatPedidos))
                {
                    cout<<"El pedido a sido registrado."<<endl;
                }
                else
                {
                    cout<<"El pedido no se ha podido registrar, el tipo de vehiculo solicitado no esta disponible en esa zona. "<<endl;
                }
                break;
            case 2:
                cout<<"Ingrese el DNI del repartidor (sin punto ni espacios): "; 
                while(!LeerInt(rep.dni))
                {
                    cout<<"Ingrese una opcion valida"<<endl;
                    LeerInt(rep.dni);
                }
                if(OpcionDos(rep))
                {
                    if(MatPedidos[rep.codZona-1][rep.transporte].ult!=NULL)
                    {
                        desencolar(MatPedidos[rep.codZona-1][rep.transporte].pri, MatPedidos[rep.codZona-1][rep.transporte].ult, ped);
                        ListaRepartidores(lRep, rep, ped);
                        insertarEnArbol(arbolComercios, ped.codComercio);
                    }
                    else
                        cout<<"No hay pedidos disponibles para el repartidor ingresado. ";
                }
                else
                {
                    cout<<"El repartidor con ese DNI no esta registrado. ";
                }
                break;
            case 3:
                RecorrerListaySub(lRep);    
                break;
            case 4:
                listarIn(arbolComercios);
                ArchvioPendientes(MatPedidos);
                break;
        }
    cout<<"\nSeleccione una opcion:"<<endl;
    cout<<"1- Recibir un pedido \n2- Asignar pedidos a un repartidor \n3- Mostrar \n4- Salir"<<endl;
    } while (menu!=4);
    return 0;
}

//Funciones correspondientes a opcion 1
bool encolarPedidos(Cola MatPedidos[14][4])
{
    Pedidos ped;
    char nomArch[20];
    pedirDatos(ped);
    int aux;
    bool presencia;
    aux=tipoVehiculo(ped.volumenPack);
    switch (aux)
    {
        case 0:
            strcpy(nomArch, "rep_motos.dat");
            presencia=chequeoVehiculos(nomArch, ped.zona);
            break;
        case 3:
            strcpy(nomArch, "rep_camiones.dat");
            presencia=chequeoVehiculos(nomArch, ped.zona);
            break;
        case 2:
            strcpy(nomArch, "rep_camionetas.dat");
            presencia=chequeoVehiculos(nomArch, ped.zona);
            break;
        case 1:
            strcpy(nomArch, "rep_autos.dat");
            presencia=chequeoVehiculos(nomArch, ped.zona);
            break;
    }
    if(presencia) {
        encolar(MatPedidos[ped.zona-1][aux].pri, MatPedidos[ped.zona-1][aux].ult, ped);
        return true;
    }
    else
        return false;
}

//Ingreso de datos de pedidos
void pedirDatos (Pedidos&ped)
{
    cout<<"Ingrese domicilio de la entrega: ";
    fflush(stdin);
    cin.getline(ped.domicilio,30);

    cout<<"Ingrese zona de entrega (1 al 14): ";
    while(true)
    {
        if(!LeerInt(ped.zona) || (ped.zona < 1 || ped.zona > 14))
            cout << "Ingrese un codigo de zona valido (del 1 al 14): \n";
        else
            break;
    }

    cout<<"Ingrese volumen del paquete: ";
    while (true)
    {
      if(!LeerFloat(ped.volumenPack) || (ped.volumenPack < 0))
            cout << "Ingrese volumen del paquete valido: \n";
        else
            break;
    }

    cout<<"Ingrese importe del pedido: ";
    while(true)
    {
        if(!LeerFloat(ped.importe))
            cout << "Ingrese importe del pedido: \n";
        else
            break;
    }
    
    cout<<"Ingrese codigo del comercio: ";
    while(true)
    {
        if(!LeerInt(ped.codComercio) || (ped.zona < 0))
            cout << "Ingrese un codigo de comercio valido: \n";
        else
            break;
    }
    
}

//revisa en los archivos de vehiculos si hay algun repartidor de esa zona
bool chequeoVehiculos(char nomArchivo[20], int zona)
{
    //cout<<nomArchivo;
    repartidores aux;
    FILE *f;
    f=fopen(nomArchivo, "rb");
    if(f==NULL) {
        cout<<"\nERROR en la apertura del archivo."<<endl;
        return false;
    }
    else
    {
        fread(&aux, sizeof(repartidores), 1, f);
        do
        {
            if(aux.codZona==zona)
                return true;
            fread(&aux, sizeof(repartidores), 1, f);
        }while(!feof(f));
        return false;
    }
    return false;
}

//Asigna vehiculo segun volumen
int tipoVehiculo(float vol) 
{
    if(vol<0.005)
        return 0;
    else {
        if(vol<0.02)
            return 1;
        else {
            if(vol<8)
                return 2;
            else 
                return 3;
        }
    }
}

//Verificacion de ingreso de enteros
bool LeerInt(int& valor)
{
    cin >> valor;
    bool ok = cin.good();
    if( ok )
    {
        char c = static_cast<char>(cin.peek());
        ok = (c == '\n' || c == ' ' );
    }
    if( !ok )
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return ok;
}

//Idem de float
bool LeerFloat(float& valor)
{
    cin >> valor;
    bool ok = cin.good();
    if( ok )
    {
        char c = static_cast<char>(cin.peek());
        ok = (c == '\n' || c == ' ' );
    }
    if( !ok )
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return ok;
}

//agrega nodos a una cola
void encolar(NodoCola*&pri,NodoCola*&ult,Pedidos ped)
{
    NodoCola*p=new NodoCola;
    p->info=ped;
    p->sig=NULL;
    if(ult!=NULL) ult->sig=p;
    else pri=p;
    ult=p;
}

//elimina nodos de una cola, devolviendo por referencia el pedido
void desencolar(NodoCola*&pri,NodoCola*&ult,Pedidos&ped)
{
    NodoCola*p=pri;
    ped=p->info; //nro=pri->info;
    pri=p->sig;
    delete p;
    if(pri==NULL) ult=NULL;

} 

//revisa los archivos de vehiculos
bool OpcionDos(repartidores&rep)
{
    bool encontro;
    char nomArch[20];
    strcpy(nomArch, "rep_motos.dat");
    encontro=chequeoRepartidores(nomArch, rep);
    if(!encontro)
    {
        strcpy(nomArch, "rep_camiones.dat");
        encontro=chequeoRepartidores(nomArch, rep);
    }
    if(!encontro)
    {
        strcpy(nomArch, "rep_camionetas.dat");
        encontro=chequeoRepartidores(nomArch, rep);
    }
    if(!encontro)
    {
        strcpy(nomArch, "rep_autos.dat");
        encontro=chequeoRepartidores(nomArch, rep);
    }
    if(!encontro)
        return false;
    else
        return true; 
}

//abre los archivos y verifica que este el repartidor
bool chequeoRepartidores(char nomArchivo[20], repartidores&repartidor)
{
    repartidores aux;
    FILE *f;
    f=fopen(nomArchivo, "rb");
    if(f==NULL) {
        cout<<"\nERROR en la apertura del archivo."<<endl;
        return false;
    }
    else
    {
        fread(&aux, sizeof(repartidores), 1, f);
        do
        {
            if(aux.dni==repartidor.dni)
                {
                    repartidor=aux;
                    return true;    
                }
            fread(&aux, sizeof(repartidores), 1, f);
        }while(!feof(f));
        return false;
    }
    return false;
}

//revisa si los repartidores estan en la lista, y sino los agrega
void ListaRepartidores(listaRep*&lista, repartidores repartidor, Pedidos pedido)
{
    listaRep*ant, *p=lista;
    while(p!= NULL && p->info.dni<repartidor.dni)
    {
        ant = p;
        p = p->sig; 
    }
    if(p!=NULL && repartidor.dni==p->info.dni)
    {
        sublistaRepartidores(lista->ordenes, pedido);
    }
    else 
    {
        listaRep*n=new listaRep;
        n->info=repartidor;
        n->sig=p;
        if(p!=lista)
            ant->sig=n;
        else 
            lista=n; 
    }
}

//agrega a una sublista los pedidos del repartidor
void sublistaRepartidores(sublistaRep*&lista, Pedidos ped)
{
    sublistaRep*p,*n,*ant;
    n=new sublistaRep;
    n->info=ped;
    p=lista;
    while(p!=NULL && ped.importe<p->info.importe)
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

//recorre la lista de repartidores y las sublistas de pedidos
void RecorrerListaySub (listaRep*lista){
    listaRep* p;
    sublistaRep* q;  
    p=lista; 
    q=p->ordenes; 

    while (p!= NULL)
    {
        cout <<"DNI: " << p->info.dni << endl;
        cout <<"Nombre y apellido: " << p->info.nombreYapellido << endl;
        cout <<"Patente: " << p->info.patente<< endl;
        cout <<"Transporte: " << p->info.transporte << endl;
        cout <<"CodZona: " << p->info.codZona << endl;
        cout <<"Pedidos asignados al repartidor: "<<endl;
        

        while (q!=NULL)
        {
            cout << "Codigo de comercio: " << q->info.codComercio << endl; 
            cout << "Codigo de domicilio: "<< q->info.domicilio << endl; 
            cout << "Importe del pedido: "<< q->info.importe << endl; 
            cout << "Volumen del pedido: " << q->info.volumenPack << endl; 
            cout << "Zona del pedido: " << q->info.zona << endl << endl; 
            q = q->sig;  
        }
        p=p->sig; 
        q=p->ordenes;
    }
    
}

//recorre la matriz de colas de pedidos para buscar pedidos pendientes y agregarlos a un archivo
void ArchvioPendientes (Cola Mat[14][4])
{
    Pedidos ped;
    FILE*ArchPen=fopen("PedidosNoEntregados.dat", "wb");
    for(int i=0; i<14; i++)
    {
        for(int j=0; j<4; j++)
        {
            while(Mat[i][j].ult!=NULL)
            {
                desencolar(Mat[i][j].pri, Mat[i][j].ult, ped);
                fwrite(&ped, sizeof(Pedidos), 1, ArchPen);
            }
        }
    }
}

//inserta en un arbol binario los comercios, y si ya estan, suma al contador
void insertarEnArbol(arbol*&raiz, int cod)
{
    arbol*n=new arbol;
    n->data.codComercio=cod;
    n->izquierda=NULL;
    n->derecha=NULL;
    if(raiz==NULL)
        raiz=n;
    else
    {
        arbol*r,*ant;
        r=raiz;
        while(r!=NULL)
        {
            ant=r;
                if(cod<r->data.codComercio)
                    r=r->izquierda;
                else
                    r=r->derecha;
        }
        if(cod==ant->data.codComercio)
            ant->data.cant++;
        else
        {
            n->data.cant=1;
            if(cod<ant->data.codComercio)
                ant->izquierda=n;
            else
                ant->derecha=n;
        }
    }
}

//muestra el arbol binario de comercios
void listarIn(arbol*raiz)
{
   if(raiz!=NULL)
   {
        listarIn(raiz->izquierda);
        cout<<raiz->data.codComercio <<"  ";
        cout<<raiz->data.cant <<"  ";
        listarIn(raiz->derecha);
   }
}