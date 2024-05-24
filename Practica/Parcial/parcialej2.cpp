#include<iostream>
using namespace std;

void invertir(bool[8][8]);
void mostrar(bool[8][8]);
int main()
{
    bool mat[8][8] {0,1,0,0,0,0,0,0,
                    1,1,1,0,0,0,0,0,
                    1,1,1,0,0,0,0,0,
                    1,1,1,1,0,0,0,0,
                    0,0,0,0,1,1,1,1,
                    0,0,0,0,0,1,1,1,
                    0,0,0,0,0,1,1,1,
                    0,0,0,0,0,0,1,0};
    mostrar(mat);
    invertir(mat);
    return 0;
}

void mostrar(bool mat[8][8])
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void invertir(bool mat[8][8])
{
    bool aux;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<4;j++)
        {
            aux=mat[i][j];
            mat[i][j]=mat[i][8-j-1];
            mat[i][8-j-1]=aux;
        }   
    }
    mostrar(mat);
}