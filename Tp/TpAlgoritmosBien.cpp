#include <iostream>
#include <stdio.h>

using namespace std;

/*El siguiente struct es utilizado para el ingreso de la informacion de los repartidores de las diferentes zonas.*/  
struct repartidores{
    int dni;
    string nombreYapellido; 
    int patente; 
    int codZona; 
    int transporte; 
}; 

/* El siguiente struct es utilizado para el ingreso de las cantidades de los diferentes tipos de transportes y repartidores que hay por zona.*/
struct zonas {
    int codZona; 
    int motos; 
    int camiones; 
    int camionetas; 
    int autos; 
    int cRepartidores; 
}; 

int funcionDisp (zonas[], repartidores[], int);
void funcioningresoZonas (zonas []);
void funcionIngreso (repartidores[], zonas[], repartidores[], repartidores[], repartidores[], repartidores[], int &, int &, int &, int &);
void funcionDatosZonas (zonas[], repartidores[], int);
void funcionTransportes (int &, int &, int &, int &, int, int ,zonas[], repartidores[], repartidores[], repartidores[],repartidores[], repartidores[]);
void ContTransp (int &, int &, int &, int &);
void maxRepartidor(zonas[]);
void informarTransp (zonas[]);

int main ()
{
    int a=0, m=0, c=0, k=0;
    zonas vectorZonas[14]; 
    repartidores vectorRep[2000], vectorMot[1000], vectorAut[1000], vectorCam[1000], vectorMion[1000]; 

    funcioningresoZonas (vectorZonas);
    funcionIngreso (vectorRep, vectorZonas, vectorAut, vectorMot, vectorMion, vectorCam, a, m, c, k);

    //Punto 1
    FILE *fMot;
    fMot=fopen("rep_motos.txt", "wb");
    if(fMot==NULL)
        cout<<"ERROR";
    else
    {
        for(int i=0; i<m; i++)
        {
            fwrite(&vectorMot[i], sizeof(vectorMot[i]), 1, fMot);
        }
    }
    fclose(fMot);

    FILE *fAuto;
    fAuto=fopen("rep_autod.txt", "wb");
    if(fAuto==NULL)
        cout<<"ERROR";
    else
    {
        for(int i=0; i<m; i++)
        {
            fwrite(&vectorAut[i], sizeof(vectorAut[i]), 1, fAuto);
        }
    }
    fclose(fAuto);

    FILE *fCam;
    fCam=fopen("rep_camionetas.txt", "wb");
    if(fCam==NULL)
        cout<<"ERROR";
    else
    {
        for(int i=0; i<m; i++)
        {
            fwrite(&vectorCam[i], sizeof(vectorCam[i]), 1, fCam);
        }
    }
    fclose(fCam);

    FILE *fMion;
    fMion=fopen("rep_Camiones.txt", "wb");
    if(fMion==NULL)
        cout<<"ERROR ";
    else
    {
        for(int i=0; i<m; i++)
        {
            fwrite(&vectorMion[i], sizeof(vectorMion[i]), 1, fMion);
        }
    }
    fclose(fMion);    

    //Puntos 2, 3, 4
    informarTransp (vectorZonas);
    ContTransp (m, k, c, a);
    maxRepartidor(vectorZonas);
    cout<<endl;
    system("pause");
}

/*La siguiente funcion tiene la tarea de rellenar el vector de structs zonas e inicializar las variables de transporte, que funcionaran 
como contadores, en cero. */
void funcioningresoZonas (zonas vectorZonas [])
{
    for (int i = 0; i < 14; i++)
    {
        vectorZonas[i].codZona = i + 1; 
        vectorZonas[i].motos= 0;
        vectorZonas[i].camiones = 0; 
        vectorZonas[i].camionetas = 0;  
        vectorZonas[i].autos= 0; 
        vectorZonas[i].cRepartidores= 0; 
    }
}

/*El ingreso de los datos de los repartidores se llevara a cabo hasta que se ingrese un 
numero de transporte "0" de modo que sale del ciclo while. */
void funcionIngreso (repartidores vectorRep [], zonas vectorZonas [], repartidores vectorAut[],
repartidores vectorMot[], repartidores vectorMion[], repartidores vectorCam[], int &a, int &m, int &c, int &k)
{
    int  i=0,transp=0; 
    cout << "Ingrese su correspondiente numero de transporte, segun el siguiente criterio:" << endl; 
    cout << "1: Moto" << endl; 
    cout << "2: Camion" << endl; 
    cout << "3: Camioneta" << endl; 
    cout << "4: Auto" << endl; 
    cin >> vectorRep[i].transporte; 
    while (vectorRep[i].transporte != 0)
    {
        cout << "Ingrese su codigo de zona: " << endl; 
        cin >> vectorRep[i].codZona;

        if (funcionDisp (vectorZonas, vectorRep, i) != 0)
        {
            transp = funcionDisp (vectorZonas, vectorRep, i); 
            funcionTransportes(m,k,c,a,transp,i,vectorZonas,vectorCam,vectorAut,vectorMion,vectorMot,vectorRep);
            funcionDatosZonas(vectorZonas,vectorRep,i);  
        }
        else
        {
        cout << "El vehiculo que ingreso llego a su limite en la zona ingresada " << endl; 
        }
        i++; 
        cout << endl <<  "Nuevo repartidor, ingrese un nuevo transporte o 0 para terminar: ";
        cin >> vectorRep[i].transporte; 
    }
}

/*La siguiente funcion se encarga de devolvernos si es posible seguir inscribiendo repartidores en las zonas.*/
int funcionDisp (zonas vectorZonas [], repartidores vectorRep[], int i)
{
    int devolver = 0; 
    if (vectorRep[i].transporte == 1 && vectorZonas[vectorRep[i].codZona - 1].motos < 20 )
    {
        devolver = 1; 
    }
    if (vectorRep[i].transporte == 2 && vectorZonas[vectorRep[i].codZona - 1].camiones < 20 )
    {
        devolver = 2; 
    }
    if (vectorRep[i].transporte == 3 && vectorZonas[vectorRep[i].codZona - 1].camionetas < 20 )
    {
        devolver = 3; 
    }
    if (vectorRep[i].transporte == 4 && vectorZonas[vectorRep[i].codZona - 1].autos < 20 )
    {
        devolver = 4; 
    }
return devolver; 
}

/*La siguiente funcion tiene la tarea de añadir la informacion que se ingresa en cuanto a cantidades de transportes
y repartidores al vector de structs zonas*/
void funcionDatosZonas (zonas vectorzonas[], repartidores vectorRep[], int i)
{
    switch (vectorRep[i].transporte)
    {
        case 1:
            vectorzonas[vectorRep[i].codZona - 1].motos++; 
            vectorzonas[vectorRep[i].codZona - 1].cRepartidores++; 
            break;
        case 2:
            vectorzonas[vectorRep[i].codZona - 1].camiones++; 
            vectorzonas[vectorRep[i].codZona - 1].cRepartidores++; 
            break;
        case 3:
            vectorzonas[vectorRep[i].codZona - 1].camionetas++; 
            vectorzonas[vectorRep[i].codZona - 1].cRepartidores++; 
            break;
        case 4:
            vectorzonas[vectorRep[i].codZona - 1].autos++; 
            vectorzonas[vectorRep[i].codZona - 1].cRepartidores++;
            break;
    }
}

/*Esta funcion lo que hace es cargar a los repartidores en los vectores de sus respectivos
vehiculos de transporte y cargarlos en el vector de repartidores general*/
void funcionTransportes (int &m, int &k, int &c, int &a, int transp, int i,zonas vectorZonas[],
repartidores vectorCam [], repartidores vectorAut [],repartidores vectorMion [],repartidores vectorMot [], repartidores vectorRep [])
{
switch (transp)
    {
    case 1:
        vectorMot[m].codZona = vectorRep[i].codZona; 
        cout << "Ingrese su numero de dni sin espacios entre las cifras: " << endl; 
        cin >> vectorMot[m].dni; 
        vectorRep[i].dni = vectorMot[m].dni; 
        cout << "Ingrese el numero de patente del vehiculo utilizado para el transporte: " << endl; 
        cin >> vectorMot[m].patente; 
        vectorRep[i].patente = vectorMot[m].patente;
        cin.ignore(); 
        cout << "Ingrese su nombre y apellido: " << endl;
        getline(cin, vectorMot[m].nombreYapellido); 
        vectorRep[i].nombreYapellido = vectorMot[m].nombreYapellido; 
        m++;
        break;

    case 2:
        vectorMion[k].codZona = vectorRep[i].codZona; 
        cout << "Ingrese su numero de dni sin espacios entre las cifras: " << endl; 
        cin >> vectorMion[k].dni; 
        vectorRep[i].dni = vectorMion[k].dni; 
        cout << "Ingrese el numero de patente del vehiculo utilizado para el transporte: " << endl; 
        cin >> vectorMion[k].patente; 
        vectorRep[i].patente = vectorMion[k].patente;
        cin.ignore(); 
        cout << "Ingrese su nombre y apellido: " << endl;
        getline(cin, vectorMion[k].nombreYapellido); 
        vectorRep[i].nombreYapellido = vectorMion[k].nombreYapellido; 
        k++;   
        break;

    case 3:
        vectorCam[c].codZona = vectorRep[i].codZona; 
        cout << "Ingrese su numero de dni sin espacios entre las cifras: " << endl; 
        cin >> vectorCam[c].dni; 
        vectorRep[i].dni = vectorCam[c].dni; 
        cout << "Ingrese el numero de patente del vehiculo utilizado para el transporte: " << endl; 
        cin >> vectorCam[c].patente; 
        vectorRep[i].patente = vectorCam[c].patente;
        cin.ignore(); 
        cout << "Ingrese su nombre y apellido: " << endl;
        getline(cin, vectorCam[c].nombreYapellido);
        vectorRep[i].nombreYapellido = vectorCam[c].nombreYapellido; 
        c++;    
        break;

    case 4:
        vectorAut[a].codZona = vectorRep[i].codZona; 
        cout << "Ingrese su numero de dni sin espacios entre las cifras: " << endl; 
        cin >> vectorAut[a].dni; 
        vectorRep[i].dni = vectorAut[a].dni; 
        cout << "Ingrese el numero de patente del vehiculo utilizado para el transporte: " << endl; 
        cin >> vectorAut[a].patente; 
        vectorRep[i].patente = vectorAut[a].patente; 
        cin.ignore();
        cout << "Ingrese su nombre y apellido: "<<endl;
        getline(cin, vectorAut[a].nombreYapellido); 
        vectorRep[i].nombreYapellido = vectorAut[a].nombreYapellido; 
        a++;    
        break;
    }
}

/*Hacer funcion para ordenar los vectores de cada transporte por dni, usar vectorCam vectorMion etc.. */
void ContTransp (int &m, int &k, int &c, int &a)
{
    cout<<"3) "<<endl;
    if(m==0 && k==0 && c==0 && a==0)
        cout<<"Ningun repartidor tiene asignado un transporte"<<endl;
    else
    {
        if (m==0)
            cout<<"No hay ningun inscripto con moto"<<endl;
        if(k==0)
            cout<<"No hay ningun inscripto con camion"<<endl;
        if(c==0)
            cout<<"No hay ningun inscripto con caminoneta"<<endl;
        if(a==0)
            cout<<"No hay ningun inscripto con auto"<<endl;
        if(m>0 && k>0 && c>0 && a>0)
            cout<<"Todos los transportes tienen al menos un inscripto"<<endl;
    }
}

/*Hacer funcion para ver si alguno de los transportes no tiene inscriptos. Usar la m, k, c y a de la funcion transportes y usar if para ver cual quedo en cero*/
void ordenar(repartidores transporte[], int max)
{
    repartidores aux;
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max-i-1;j++)
        {
            if(transporte[i].dni>transporte[i+1].dni)
            {
                aux=transporte[i];
                transporte[i]=transporte[i+1];
                transporte[i+1]=aux;
            }
        }
    }
}

/*Hacer funcion maximo usando el vector zonas.repartidores para ver cual tiene mas*/
void maxRepartidor(zonas vectorZonas[])
{
    cout<<"4) "<<endl;
    int max=0, pos=0; 
    max=vectorZonas[0].cRepartidores;
    for (int i=1; i<14; i++)
    {
        if(max<vectorZonas[i].cRepartidores)
        {
            max=vectorZonas[i].cRepartidores;
            pos=i;
        }
    }
    cout<<"La zona "<<pos+1<<" es la que mayor cantidad de repartidores tiene.";
}

/*Para el punto 2 hacer una funcion que use el vector zonas y vaya haciendo un cout de cada transporte por cada zona*/
void informarTransp (zonas vectorZonas[])
{
    cout<<"2) "<<endl;
    for (int i=0; i<14; i++)
    {
        cout<<"La zona "<<i+1<<" tiene la siguiente cantiad de repartidores por transporte: "<<endl;
        cout<<"   - Motos: "<<vectorZonas[i].motos<<endl;
        cout<<"   - Autos: "<<vectorZonas[i].autos<<endl;
        cout<<"   - Camiones: "<<vectorZonas[i].camiones<<endl;
        cout<<"   - Camionetas: "<<vectorZonas[i].camionetas<<endl<<endl;
    }
}

