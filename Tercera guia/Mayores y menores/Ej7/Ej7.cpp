/*Un jugador arroja 5 dados y se registra como puntaje la suma de los dos valores más altos. Dada
una serie de tiros, que finaliza al ingresar ‘N’ ante la consulta “Continúa? S/N”, determinar e
imprimir la cantidad de tiros, el máximo puntaje obtenido, y el puntaje promedio.*/
#include<stdio.h>
#include<conio.h>
#define MAX 5

int main()
{
    int puntaje=0,i,cantTiros=0,max=0,val=0,may1=0,may2=0,mayPuntaje=0;
    bool prim=true;
    char contin;
    float prom=0;
    printf("Ingrese valores\n");
    //Valores de cada dado (son 5)
    while(contin!='N')
    {
        for(i=0;i<MAX;i++)
        {
            scanf("%d",&val);
            if(prim==true)
            {
                max=val;
                prim=false;
            }
            if(val>0 && val<7)
            {
                if(val>may1)
                {
                    may1=val;
                } 
                if(val>may2 && i%2!=0)
                {
                    may2=val;
                }
                puntaje=may1+may2;
                if(puntaje>mayPuntaje) mayPuntaje=puntaje;
            }
        } 
        prom+=(float)puntaje;
        cantTiros++;
        printf("Continua? S/N\n");
        scanf(" %c",&contin);
    }
    prom/=(float)cantTiros;
    printf("Se realizaron %d tiros, donde el maximo puntaje obtenido fue de %d puntos, en promedio se obtuvieron %f puntos",cantTiros,mayPuntaje,prom);
    getch();
}