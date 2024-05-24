/*Desarrollar la metodología necesaria para escribir un algoritmo que Grabe un archivo maestro de series
actualizado, ActSeries.dat, con el mismo diseño y orden que los anteriores.*/
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct series
{
    unsigned Id_serie;
    char titulo[20];
    char genero[10];
};
void apareo(FILE*aAct,FILE*aSer,FILE*aNov);

int main()
{
    FILE *aSer,*aNov,*aAct;
    aAct=fopen("ActSeries.DAT","wb");
    if(aAct!=NULL)
    {
        aSer=fopen("Series.DAT","rb");
        if(aSer!=NULL)
        {
            aNov=fopen("NovSeries.DAT","rb");
            if(aNov!=NULL)
            {
                apareo(aAct,aSer,aNov);
            }
            else cout<<"ERROR"<<endl;
            fclose(aNov);
        }
        else cout<<"ERROR"<<endl;
        fclose(aSer);
    }
    else cout<<"ERROR"<<endl;
    fclose(aAct);
    getch();
}

void apareo(FILE *aAct,FILE *aSer,FILE *aNov)
{
    series s1,s2;
    fread(&s1,sizeof(series),1,aSer);
    fread(&s2,sizeof(series),1,aNov);
    while(!feof(aSer) && !feof(aNov))
    {
        if(s1.Id_serie<s2.Id_serie)
        {
            cout<<s1.Id_serie<<endl;
            fwrite(&s1,sizeof(series),1,aAct);
            fread(&s1,sizeof(series),1,aSer);
        }
        else
        {
            if(s1.Id_serie==s2.Id_serie)
            {
                cout<<s1.Id_serie<<endl;
                fwrite(&s1,sizeof(series),1,aAct);
                fwrite(&s2,sizeof(series),1,aAct);
                fread(&s1,sizeof(series),1,aSer);
                fread(&s2,sizeof(series),1,aNov);
            }
            else
            {
                cout<<s2.Id_serie<<endl;
                fwrite(&s2,sizeof(series),1,aAct);
                fread(&s2,sizeof(series),1,aNov);
            }
        }
    }
        while(!feof(aSer))
    {
        cout<<s1.Id_serie<<endl;
        fread(&s1,sizeof(series),1,aSer);
        fwrite(&s1,sizeof(series),1,aAct);
    }
    while(!feof(aNov))
    {
        cout<<s2.Id_serie<<endl;
        fread(&s2,sizeof(series),1,aNov);
        fwrite(&s2,sizeof(series),1,aAct);
    }
}