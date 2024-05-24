/*El gobierno de la Ciudad de Buenos Aires realiza una encuesta en casas de familia. De cada
familia encuestada se conoce: domicilio, tipo de vivienda (‘C’: casa, ‘D’: departamento) y
cantidad de integrantes.
De cada integrante de la familia se conoce: nombre y apellido, edad, sexo (‘F’, ‘M’), nivel de
estudios alcanzados (‘N’: no posee, ‘P’: primario, ‘S’: secundario, ‘T’: terciario), y un indicador
(‘I’: Incompleto, ‘C’: Completo) referente al ítem anterior.
Se identifica el fin de ingreso de datos con un cero como cantidad de integrantes.
Informar:
a) La cantidad de encuestados que han completado los estudios primarios,
b) el porcentaje de analfabetismo en la ciudad (se consideran analfabetos a los mayores de
10 años que no poseen estudios),
c) el domicilio de la familia con mayor cantidad de integrantes que viven en un
departamento,
d) la edad promedio de todos los habitantes de la ciudad,
e) la mayor edad promedio de las familias,
f) la cantidad de encuestados con estudios secundarios incompletos,
g) el porcentaje de encuestados de sexo femenino con estudios terciarios completos.*/
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
    char domicilio[10],vivienda,nombre[10],apellido[10],sexo,estudios,indicadorEstudio,domMasHab[10],tipoDomMasHab,porciento='%',deptoMasHab[10];
    int cantHab=1,encuestados=0,edad,cantEstudiosPrim=0,cantAnashe=0,promEdad=0,masHab,porcAnashe=0,j,promEdadFlia=0,sumEdad=0,mayPromEdad=0,cantSecInc=0,porcMujeTerc=0,cantMujeTerc=0,cantMujeres=0;
    bool prim=true;
    while(cantHab!=0)
    {
        printf("Ingrese domicilio, tipo de vivienda 'C' si es casa, 'D' si es depto y cantidad de habitantes en la misma\n");
        scanf("%s %c %d",&domicilio,&vivienda,&cantHab);
        if(cantHab==0) break;
        if(prim==true)
        {
            masHab=cantHab;
            strcpy(domMasHab,domicilio);
            tipoDomMasHab=vivienda;
            prim=false;
        }
        if(cantHab>masHab)
        {
            masHab=cantHab;
            tipoDomMasHab=vivienda;
            strcpy(domMasHab,domicilio);
        }
        for(j=0;j<cantHab;j++)
        {
            printf("Ingrese nombre, apellido, sexo, edad, nivel de estudio y si completo sus estudios o aun se encuentra cursando\n");
            scanf("%s %s %c %d %c %c",&nombre,&apellido,&sexo,&edad,&estudios,&indicadorEstudio);
            sumEdad+=edad;
            //promEdadFlia+=edad;
            if((estudios=='S'||estudios=='T') && (indicadorEstudio=='C'||indicadorEstudio=='I')) cantEstudiosPrim++;
            if(edad>10 && estudios=='N') cantAnashe++;
            if(tipoDomMasHab=='D') strcpy(deptoMasHab,domMasHab);
            if(estudios=='S'&&indicadorEstudio=='I') cantSecInc++;
            if(sexo=='F' && estudios=='T' && indicadorEstudio=='C') cantMujeTerc++;
            if(sexo=='F') cantMujeres++;
        }
        promEdadFlia+=sumEdad;
        promEdad+=sumEdad;
        sumEdad=0;
        promEdadFlia/=cantHab;
        if(promEdadFlia>mayPromEdad) mayPromEdad=promEdadFlia;
        promEdadFlia=0;
        encuestados++;
    }
    porcAnashe=(cantAnashe*100)/encuestados;
    promEdad/=encuestados;
    porcMujeTerc=(cantMujeTerc*100)/cantMujeres;
    printf("De %d viviendas encuestadas, %d habitantes han completado el nivel primario\n",encuestados,cantEstudiosPrim);   //a)
    printf("De %d viviendas encuestadas, un %d%c de habitantes son analfabetos\n",encuestados,porcAnashe,porciento);       //b)
    printf("El departamento con mayor cantidad de habitantes se encuentra en la calle %s\n",deptoMasHab);   //c)
    printf("La edad promedio de las personas encuestadas es de %d anios\n",promEdad);            //d)
    printf("La familia con mayor promedio de edad es de %d anios\n",mayPromEdad);                //e)
    printf("Hay un total de %d personas que no tienen el secundario completo\n",cantSecInc);     //f)
    printf("De %d mujeres encuestadas, un %d%c tiene sus estudios terciarios completos\n",cantMujeres,porcMujeTerc,porciento); //g)
    getch();
}