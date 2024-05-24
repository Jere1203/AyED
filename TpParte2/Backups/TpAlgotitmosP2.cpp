#include <iostream>
#include <limits>
#include <string>
#include <cstring>
using namespace std;

struct repartidores
{
    int dni;
    string nombreYapellido; 
    string patente; 
    int codZona; 
    int transporte; 
}; 

struct Pedidos
{
    char domicilio [30];
    int zona;
    float volumenPack;
    float importe;
    int codComercio;
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

//funciones genericas
bool LeerInt(int&); 
bool LeerFloat(float&); 
void encolar(NodoCola*&, NodoCola*&, Pedidos);
void desencolar(NodoCola*&, NodoCola*&, Pedidos&);
//funciones punto 1
int tipoVehiculo(float);
void pedirDato(Pedidos);
bool encolarPedidos(Cola[14][4]);
bool chequeoVehiculos(char[18], int);
Pedidos Registro();
//funciones punto 2
bool OpcionDos(repartidores&);
bool chequeoRepartidores(char[18], repartidores&);

int main()
{
    int menu;
    repartidores rep; 
    Pedidos ped; 
    Cola MatPedidos[14][4];
    for(int i=0; i<14; i++) //inicializa las colas de la matriz
    {
        for(int j=0; j<4; j++)
            MatPedidos[i][j].pri=MatPedidos[i][j].ult=NULL;
    }
    
    cout<<"Seleccione una opcion:"<<endl;
    cout<<"1- Recibir un pedido \n 2- Asignar pedidos a un repartidor \n 3- Mostrar \n 4- Salir"<<endl;
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
                        //AGREGAR "PED" A UNA ESTRUCTURA DINAMICA NUEVA
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
            
                break;
            case 4:

                break;
        }
    cout<<"\nSeleccione una opcion:"<<endl;
    cout<<"1- Recibir un pedido \n 2- Asignar pedidos a un repartidor \n 3- Mostrar \n 4- Salir"<<endl;
    } while (menu!=4);
    return 0;
}

//Funciones correspondientes a opcion 1
bool encolarPedidos(Cola MatPedidos[14][4])
{
    Pedidos ped;
    pedirDatos(ped);
    int aux;
    bool presencia;
    aux=tipoVehiculo(ped.volumenPack);
    switch (aux)
    {
        case 0:
            presencia=chequeoVehiculos("rep_motos.dat", ped.zona);
            break;
        case 1:
            presencia=chequeoVehiculos("rep_camiones.dat", ped.zona);
            break;
        case 2:
            presencia=chequeoVehiculos("rep_camionetas.dat", ped.zona);
            break;
        case 3:
            presencia=chequeoVehiculos("rep_autos.dat", ped.zona);
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
void pedirDatos (Pedidos ped)
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
bool chequeoVehiculos(char nomArchivo[18], int zona)
{
    repartidores aux;
    FILE *f;
    f=fopen(nomArchivo, "rb");
    if(f==NULL) cout<<"ERROR"<<endl;
    else
    {
        fread(&aux, sizeof(repartidores), 1, f);
        while(!feof(f))
        {
            if(aux.codZona==zona)
                return true;
            fread(&aux, sizeof(repartidores), 1, f);
        }
        return false;
    }
}

//Asigna vehiculo segun volumen
int tipoVehiculo(float vol) 
{
    if(vol<0,005)
        return 0;
    if(vol<0,02)
        return 1;
    if(vol<8)
        return 2;
    else 
        return 3;
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

void encolar(NodoCola*&pri,NodoCola*&ult,Pedidos ped)
{
    NodoCola*p=new NodoCola;
    p->info=ped;
    p->sig=NULL;
    if(ult!=NULL) ult->sig=p;
    else pri=p;
    ult=p;
}

void desencolar(NodoCola*&pri,NodoCola*&ult,Pedidos&ped)
{
    NodoCola*p=pri;
    ped=p->info; //nro=pri->info;
    pri=p->sig;
    delete p;
    if(pri==NULL) ult=NULL;

} 

bool OpcionDos(repartidores&rep)
{
    bool encontro=true;
    do
    {
        while(encontro)
        {
            encontro=chequeoRepartidores("rep_motos.dat", rep);
        }
        while(encontro)
        {
            encontro=chequeoRepartidores("rep_camiones.dat", rep);
        }
        while(encontro)
        {
            encontro=chequeoRepartidores("rep_camionetas.dat", rep);
        }
        while(encontro)
        {
            encontro=chequeoRepartidores("rep_autos.dat", rep);
        }
    } while(encontro);
    if(!encontro)
        return false;
    else
        return true; 
}

bool chequeoRepartidores(char nomArchivo[18], repartidores&repartidor)
{
    repartidores aux;
    FILE *f;
    f=fopen(nomArchivo, "rb");
    if(f==NULL) cout<<"ERROR"<<endl;
    else
    {
        fread(&aux, sizeof(repartidores), 1, f);
        while(!feof(f))
        {
            if(aux.dni==repartidor.dni)
                repartidor=aux;
                return true;
            fread(&aux, sizeof(repartidores), 1, f);
        }
        return false;
    }
}
