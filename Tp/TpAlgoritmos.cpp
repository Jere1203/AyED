#include <iostream>
using namespace std;

/*El siguiente struct es utilizado para el ingreso de la informacion de los repartidores de las diferentes zonas.*/  

struct repartidores{
    int dni;
    string nombreYapellido; 
    int patente; 
    int codZona; 
    int transporte; 
}; 

/* El siguiente struct es utilizado para el ingreso de las cantidades de los diferentes tipos de transportes y
repartidores que hay por zona.*/

struct zonas {
    int codZona; 
    int motos; 
    int camiones; 
    int camionetas; 
    int autos; 
    int repartidores; 
}; 
void ordenar(repartidores transporte[],int max);
int main ()
{
 
    zonas vectorZonas[14]; 
    repartidores vectorRep[2000]; 
    repartidores vectorMot[1000];
    repartidores vectorAut[1000]; 
    repartidores vectorCam[1000]; 
    repartidores vectorMion[1000]; 
    ordenar(vectorRep,14);


}




/*La siguiente funcion tiene la tarea de rellenar el vector de structs zonas e inicializar las variables de transporte, que funcionaran 
como contadores, en cero. */
 
void funcioningresoZonas (zonas vectorZonas []){

for (int i = 0; i < 14; i++)
{
    vectorZonas[i].codZona = i + 1; 
    vectorZonas[i].motos= 0;
    vectorZonas[i].camiones = 0; 
    vectorZonas[i].camionetas = 0;  
    vectorZonas[i].autos= 0; 
    vectorZonas[i].repartidores = 0; 
}

}

/*El ingreso de los datos de los repartidores se llevara a cabo hasta que se ingrese un 
numero de transporte "0" de modo que sale del ciclo while. */

void funcionIngreso (repartidores vectorRep [], zonas vectorZonas [], repartidores vectorAut[],
repartidores vectorMot[], repartidores vectorMion[], repartidores vectorCam[])
{
    int  i = 0;
    int  a = 0;
    int  m = 0;
    int  c = 0;
    int  k = 0; 
    int transp = 0; 

    cout << "ingrese su correspondiente numero de transporte, segun el siguiente criterio." << endl; 
    cout << "1: moto" << endl; 
    cout << "2: camion" << endl; 
    cout << "3: camioneta" << endl; 
    cout << "4: auto" << endl; 
    cin >> vectorRep[i].transporte; 
    while (vectorRep[i].transporte != 0)
    {
        cout << "ingrese su codigo de zona: " << endl; 
        cin >> vectorRep[i].codZona;

        if (funcionDisp (vectorZonas, vectorRep, i) != 0)
        {
         transp = funcionDisp (vectorZonas, vectorRep, i); 
         funcionTransportes(m,k,c,a,transp,i,vectorZonas,vectorCam,vectorAut,vectorMion,vectorMot,vectorRep);
         funcionDatosZonas(vectorZonas,vectorRep,i);  

        }
        else{
        cout << "El vehiculo que ingreso llego a su limite en la zona ingresada " << endl; 
        }
        i++; 
        cout << "ingrese un nuevo repartidor: " << endl;
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
    if (vectorRep[i].transporte == 1)
    {
        vectorzonas[vectorRep[i].codZona - 1].motos++; 
        vectorzonas[vectorRep[i].codZona - 1].repartidores++; 
    }
    if (vectorRep[i].transporte == 2)
    {
        vectorzonas[vectorRep[i].codZona - 1].camiones++; 
        vectorzonas[vectorRep[i].codZona - 1].repartidores++; 
    }
    if (vectorRep[i].transporte == 3)
    {
        vectorzonas[vectorRep[i].codZona - 1].camionetas++; 
        vectorzonas[vectorRep[i].codZona - 1].repartidores++; 
    }
    if (vectorRep[i].transporte == 4)
    {
        vectorzonas[vectorRep[i].codZona - 1].autos++; 
        vectorzonas[vectorRep[i].codZona - 1].repartidores++; 
    }

}

/*Esta funcion lo que hace es cargar a los repartidores en los vectores de sus respectivos
vehiculos de transporte y cargarlos en el vector de repartidores general*/

void funcionTransportes (int &m, int &k, int &c, int &a, int transp, int i,zonas vectorZonas[],
repartidores vectorCam [], repartidores vectorAut [],repartidores vectorMion [],repartidores vectorMot [], repartidores vectorRep [])
{

    if (transp == 1)
    {
        vectorMot[m].codZona = vectorRep[i].codZona; 
        cout << "ingrese su numero de dni sin espacios entre las cifras: " << endl; 
        cin >> vectorMot[m].dni; 
        vectorRep[i].dni = vectorMot[m].dni; 
        cout << "ingrese el numero de patente del vehiculo utilizado para el transporte: " << endl; 
        cin >> vectorMot[m].patente; 
        vectorRep[i].patente = vectorMot[m].patente; 
        // ver como era para que se pueda escribir un string en el cin.
        cout << "ingrese su nombre y apellido: " << endl;
        cin >> vectorMot[m].nombreYapellido; 
        vectorRep[i].nombreYapellido = vectorMot[m].nombreYapellido; 
        m++;
    }
    if (transp == 2)
    {
        cout << "ingrese el codigo de su zona de reparto: " << endl; 
        cin >> vectorMion[k].codZona;
        vectorRep[i].codZona = vectorMion[k].codZona; 
        cout << "ingrese su numero de dni sin espacios entre las cifras: " << endl; 
        cin >> vectorMion[k].dni; 
        vectorRep[i].dni = vectorMion[k].dni; 
        cout << "ingrese el numero de patente del vehiculo utilizado para el transporte: " << endl; 
        cin >> vectorMion[k].patente; 
        vectorRep[i].patente = vectorMion[k].patente; 
        // ver como era para que se pueda escribir un string en el cin.
        cout << "ingrese su nombre y apellido: " << endl;
        cin >> vectorMion[k].nombreYapellido; 
        vectorRep[i].nombreYapellido = vectorMion[k].nombreYapellido; 
        k++;
    }
    if (transp == 3)
    {
        cout << "ingrese el codigo de su zona de reparto: " << endl; 
        cin >> vectorCam[c].codZona;
        vectorRep[i].codZona = vectorCam[c].codZona; 
        cout << "ingrese su numero de dni sin espacios entre las cifras: " << endl; 
        cin >> vectorCam[c].dni; 
        vectorRep[i].dni = vectorCam[c].dni; 
        cout << "ingrese el numero de patente del vehiculo utilizado para el transporte: " << endl; 
        cin >> vectorCam[c].patente; 
        vectorRep[i].patente = vectorCam[c].patente; 
        // ver como era para que se pueda escribir un string en el cin.
        cout << "ingrese su nombre y apellido: " << endl;
        cin >> vectorCam[c].nombreYapellido; 
        vectorRep[i].nombreYapellido = vectorCam[c].nombreYapellido; 
        c++;
    }
    if (transp == 4)
    {
        cout << "ingrese el codigo de su zona de reparto: " << endl; 
        cin >> vectorAut[a].codZona;
        vectorRep[i].codZona = vectorAut[a].codZona; 
        cout << "ingrese su numero de dni sin espacios entre las cifras: " << endl; 
        cin >> vectorAut[a].dni; 
        vectorRep[i].dni = vectorAut[a].dni; 
        cout << "ingrese el numero de patente del vehiculo utilizado para el transporte: " << endl; 
        cin >> vectorAut[a].patente; 
        vectorRep[i].patente = vectorAut[a].patente; 
        // ver como era para que se pueda escribir un string en el cin.
        cout << "ingrese su nombre y apellido: " << endl;
        cin >> vectorAut[a].nombreYapellido; 
        vectorRep[i].nombreYapellido = vectorAut[a].nombreYapellido; 
        a++;
    }

}

void ordenar(repartidores transporte[],int max)
{
    repartidores aux;
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max-i-1;j++)
        {
            if(transporte[i].dni<transporte[i+1].dni)
            {
                aux=transporte[i];
                transporte[i]=transporte[i+1];
                transporte[i+1]=aux;
            }
        }
    }
}
/*Hacer funcion para ordenar los vectores de cada transporte por dni, usar vectorCam vectorMion etc.. */

/*Hacer funcion para ver si alguno de los transportes no tiene inscriptos. Usar la m, k, c y a de la funcion transportes
y usar if para ver cual quedo en cero*/

/*Hacer funcion maximo usando el vector zonas.repartidores para ver cual tiene mas*/

/*Para el punto 2 hacer una funcion que use el vector zonas y vaya haciendo un cout de cada transporte por cada zona*/