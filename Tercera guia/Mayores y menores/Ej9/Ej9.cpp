/*Un buque de carga traslada contenedores a tres diferentes puertos del país. Los puertos se
identifican con los números 1, 2 y 3.
De cada contenedor que el buque traslade se registran los siguientes datos:
- Identificación del contenedor
- Peso del contenedor en kg
- Puerto de arribo (un valor de 1 a 3).
El ingreso de datos finaliza con la identificación de un contenedor igual a cero.
Se pide calcular e informar:
a) El peso total que el buque debe trasladar.
b) La identificación del contenedor de mayor peso.
c) La cantidad de contenedores que debe trasladar a cada puerto*/
#include<stdio.h>
#include<conio.h>

int main()
{
    int puerto=0,i=0,peso=0,id=1,pesoTotal=0,mayorPeso=0,cantP1=0,cantP2=0,cantP3=0,idMayorPeso=0;
    bool prim=true;
    printf("Ingrese codigo de identificacion de la carga, peso del contenedor y puerto de arribo\n");
    while(id!=0)
    {  
        scanf("%d %d %d",&id,&peso,&puerto);
        if(id==0) break;
        pesoTotal+=peso;
        if(prim == true)
        {
            mayorPeso=peso;
            idMayorPeso=id;
            prim=false;
        }
        if(peso>mayorPeso)
        {
            mayorPeso=peso;
            idMayorPeso=id;
        } 
        switch (puerto)
        {
        case 1:
            cantP1++;
            break;
        
        case 2:
            cantP2++;
            break;
        case 3:
            cantP3++;
            break;
        }
    }
    printf("El buque debe trasladar %dKG en total\n",pesoTotal);
    printf("El contenedor de mayor peso es el %d\n",idMayorPeso);
    printf("Al puerto 1 corresponden %d contenedores, al puerto 2: %d y al puerto 3: %d\n",cantP1,cantP2,cantP3);
    getch();
}