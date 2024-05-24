#include <iostream>
#include <stdio.h>
#include <limits>
#include <regex>
#include <conio.h>
#include <string.h>
using namespace std;

//Agregar ctype(libreria), corregir numero mezclado con letras.

/*El siguiente struct es utilizado para el ingreso de la informacion de los repartidores de las diferentes zonas.*/  
struct repartidores{
    int dni;
    char nombreYapellido[30]; 
    char patente[7]; 
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
void ordenar(repartidores [],repartidores [], repartidores [], repartidores [], int &, int &, int &, int & ); 
bool LeerInt(int &);
bool verif_patente(string);

int main ()
{
    /*m (moto), k (camión), c (camioneta), a (auto), */
    int a=0, m=0, c=0, k=0;
    zonas vectorZonas[14]; 
    repartidores vectorRep[2000], vectorMot[1000], vectorAut[1000], vectorCam[1000], vectorMion[1000]; 

    funcioningresoZonas (vectorZonas);
    funcionIngreso (vectorRep, vectorZonas, vectorAut, vectorMot, vectorMion, vectorCam, a, m, c, k);
    ordenar(vectorMot, vectorMion, vectorCam, vectorAut, m, k, c, a ); 

    //Punto 1
    FILE *fMot;
    fMot=fopen("rep_motos.dat", "wb");
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
    fAuto=fopen("rep_autos.dat", "wb");
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
    fCam=fopen("rep_camionetas.dat", "wb");
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
    fMion=fopen("rep_Camiones.dat", "wb");
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
    getch();
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
    cout << "0: Cancelar" << endl;
    //cin >> vectorRep[i].transporte; 
    
    while(true)
    {
        if(!LeerInt(vectorRep[i].transporte) || (vectorRep[i].transporte < 0 || vectorRep[i].transporte > 4))
        {
            cout << "Ingrese un numero de transporte valido, segun el siguiente criterio:" << endl; 
            cout << "1: Moto" << endl; 
            cout << "2: Camion" << endl; 
            cout << "3: Camioneta" << endl; 
            cout << "4: Auto" << endl; 
            cout << "0: Cancelar" << endl;
        }
        else
        break;
    }

    while (vectorRep[i].transporte != 0)
    {
        cout << "Ingrese su codigo de zona (del 1 al 14): " << endl; 
        //cin >> vectorRep[i].codZona;
        while(true)
        {
            if(!LeerInt(vectorRep[i].codZona) || (vectorRep[i].codZona < 1 || vectorRep[i].codZona > 14))
                cout << "Ingrese un codigo de zona valido (del 1 al 14): \n";
            else
            break;
        }
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
        while(true)
        {
            if(!LeerInt(vectorRep[i].transporte) || (vectorRep[i].transporte < 0 || vectorRep[i].transporte > 4))
            {
                cout << "Ingrese un numero de transporte valido, segun el siguiente criterio:" << endl; 
                cout << "1: Moto" << endl; 
                cout << "2: Camion" << endl; 
                cout << "3: Camioneta" << endl; 
                cout << "4: Auto" << endl; 
                cout << "0: Cancelar" << endl;
            }
            else
            break;
        }
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
                //cin >> vectorMot[m].dni; 
                while(true)
                {
                    if(!LeerInt(vectorMot[m].dni))
                        cout << "ERROR, ingrese un dni valido: \n";
                    else
                    break;
                }
                vectorRep[i].dni = vectorMot[m].dni; 
                cout << "Ingrese el numero de patente del vehiculo en formato AA123BB: " << endl; 
                cin >> vectorMot[m].patente;
                while(verif_patente(vectorMot[m].patente)==false)
                {
                    cout<<"La patente ingresada no es valida, vuelva a ingresarla"<<endl;
                    cin >> vectorMot[m].patente;
                }
                //vectorRep[i].patente = vectorMot[m].patente
                strcpy(vectorRep[i].patente,vectorMot[m].patente);
                cout << "Ingrese su nombre y apellido: " << endl;
                //cin.ignore(); 
                fflush(stdin);
                //getline(cin, vectorMot[m].nombreYapellido); 
                cin.getline(vectorMot[m].nombreYapellido,30);
                //vectorRep[i].nombreYapellido = vectorMot[m].nombreYapellido; 
                strcpy(vectorRep[i].nombreYapellido,vectorMot[m].nombreYapellido);
                m++;
                break;

            case 2:
                vectorMion[k].codZona = vectorRep[i].codZona; 
                cout << "Ingrese su numero de dni sin espacios entre las cifras: " << endl; 
                //cin >> vectorMion[k].dni; 
                while(true)
                {
                    if(!LeerInt(vectorMion[m].dni))
                        cout << "ERROR, ingrese un dni valido: \n";
                    else
                    break;
                }
                vectorRep[i].dni = vectorMion[k].dni; 
                cout << "Ingrese el numero de patente del vehiculo en formato AA123BB: " << endl; 
                cin >> vectorMion[k].patente; 
                while(verif_patente(vectorMion[k].patente)==false)
                {
                    cout<<"La patente ingresada no es valida, vuelva a ingresarla"<<endl;
                    cin >> vectorMion[k].patente;
                }
                //vectorRep[i].patente = vectorMion[k].patente;
                strcpy(vectorRep[i].patente,vectorMion[k].patente);
                cout << "Ingrese su nombre y apellido: " << endl;
                //cin.ignore(); 
                fflush(stdin);
                //getline(cin, vectorMion[k].nombreYapellido); 
                cin.getline(vectorMion[k].nombreYapellido,30);
                //vectorRep[i].nombreYapellido = vectorMion[k].nombreYapellido; 
                strcpy(vectorRep[i].nombreYapellido,vectorMion[k].nombreYapellido);
                k++;   
                break;

            case 3:
                vectorCam[c].codZona = vectorRep[i].codZona; 
                cout << "Ingrese su numero de dni sin espacios entre las cifras: " << endl; 
                //cin >> vectorCam[c].dni;
                while(true)
                {
                    if(!LeerInt(vectorCam[m].dni))
                        cout << "ERROR, ingrese un dni valido: \n";
                    else
                    break;
                } 
                vectorRep[i].dni = vectorCam[c].dni; 
                cout << "Ingrese el numero de patente del vehiculo en formato AA123BB: " << endl; 
                cin >> vectorCam[c].patente;
                while(verif_patente(vectorCam[c].patente)==false)
                {
                    cout<<"La patente ingresada no es valida, vuelva a ingresarla"<<endl;
                    cin >> vectorCam[c].patente;
                }
                //vectorRep[i].patente = vectorCam[c].patente;
                strcpy(vectorRep[i].patente,vectorCam[c].patente);
                cout << "Ingrese su nombre y apellido: " << endl;
                //cin.ignore(); 
                fflush(stdin);
                //getline(cin, vectorCam[c].nombreYapellido);
                cin.getline(vectorCam[c].nombreYapellido,30);
                //vectorRep[i].nombreYapellido = vectorCam[c].nombreYapellido; 
                strcpy(vectorRep[i].nombreYapellido,vectorCam[c].nombreYapellido);
                c++;    
                break;

            case 4:
                vectorAut[a].codZona = vectorRep[i].codZona; 
                cout << "Ingrese su numero de dni sin espacios entre las cifras: " << endl; 
                //cin >> vectorAut[a].dni;
                while(true)
                {
                    if(!LeerInt(vectorMot[m].dni))
                        cout << "ERROR, ingrese un dni valido: \n";
                    else
                    break;
                } 
                vectorRep[i].dni = vectorAut[a].dni; 
                cout << "Ingrese el numero de patente del vehiculo en formato AA123BB: " << endl; 
                cin >> vectorAut[a].patente;
                while(verif_patente(vectorAut[a].patente)==false)
                {
                    cout<<"La patente ingresada no es valida, vuelva a ingresarla"<<endl;
                    cin >> vectorAut[a].patente;
                }
                //vectorRep[i].patente = vectorAut[a].patente; 
                strcpy(vectorRep[i].patente,vectorAut[a].patente);
                cout << "Ingrese su nombre y apellido: "<<endl;
                //cin.ignore(); 
                fflush(stdin);
                //getline(cin, vectorAut[a].nombreYapellido); 
                cin.getline(vectorAut[a].nombreYapellido,30);
                //vectorRep[i].nombreYapellido = vectorAut[a].nombreYapellido; 
                strcpy(vectorRep[i].nombreYapellido,vectorAut[a].nombreYapellido);
                a++;    
                break;
        }
}

/*Funcion para ver si alguno de los transportes no tiene inscriptos.*/
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

/*Funcion que ordena los vectores de los 4 medios de transporte*/
void ordenar(repartidores vectorMot[],repartidores vectorMion[], repartidores vectorCam[], repartidores vectorAut[], int &m, int &k, int &c, int &a )
{
    repartidores aux1;
    repartidores aux2;
    repartidores aux3;
    repartidores aux4;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m-i-1;j++)
        {
            if(vectorMot[j].dni>vectorMot[j+1].dni)
            {
                aux1=vectorMot[j];
                vectorMot[j]=vectorMot[j+1];
                vectorMot[j+1]=aux1;
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k-i-1;j++)
        {
            if(vectorMion[j].dni>vectorMion[j+1].dni)
            {
                aux2=vectorMion[j];
                vectorMion[j]=vectorMion[j+1];
                vectorMion[j+1]=aux2;
            }
        }
    }
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<c-i-1;j++)
        {
            if(vectorCam[j].dni>vectorCam[j+1].dni)
            {
                aux3=vectorCam[j];
                vectorCam[j]=vectorCam[j+1];
                vectorCam[j+1]=aux3;
            }
        }
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a-i-1;j++)
        {
            if(vectorAut[j].dni>vectorAut[j+1].dni)
            {
                aux4=vectorAut[j];
                vectorAut[j]=vectorAut[j+1];
                vectorAut[j+1]=aux4;
            }
        }
    }
}

/*Funcion maximo usando el vector zonas.repartidores para ver cual tiene mas*/
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
    if (max == 0)
    {
    cout << "No exite zona con mayor cantidad de repartidores ya que no se ingreso ninguno." << endl; 
    }
    else
    {
   cout<<"La zona "<<pos+1<<" es la que mayor cantidad de repartidores tiene."<< endl; 
    }

}

/*Funcion que use el vector zonas y vaya haciendo un cout de cada transporte por cada zona*/
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
bool verif_patente(string pat)
{
    const regex expReg("[A-Z]{2}[0-9]{3}[A-Z]{2}");

    return regex_match(pat, expReg);
}