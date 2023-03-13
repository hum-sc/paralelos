#include <iostream>
#include <array>
#include <math.h>

using namespace std;
int A[2][2];
int B[2][2];
int c[2][2][2];
int n=2;

void MatMultCREW()
{
    // Paso 1
    #pragma omp parallel for
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                c[i][j][k] = A[i][k] * B[k][j];
            }
        }
    }
    //Paso 2

    for (int L = 1; L <= (int)n/2; L++)
    {
        #pragma omp parallel for
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = 0; k <= (int)n/2; k++)
                {
                    if (((int)pow(2,k) % (int)pow(2,L))==0)
                    {

                        c[i][j][2*k] = c[i][j][2*k]+c[i][j][2*k-((int)pow(2,(L-1)))];

                        
                    }
                }
            }
        }
    }  
}
void imprimir(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<c[i][j][n]<<" \t";
        }
        cout<<"\n";
    }
}

int main (){

    cout<<">>>>>>>>>>>>> Bienvenido al programa de Multiplicacion de matrices <<<<<<<<<<<<<"<<endl;
    int x;

    cout<<"\nMatriz A: "<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<"Ingrese el digito en la posicion ("<<i<<", "<<j<<")"<<": "; cin>>x;
            A[i][j]= x;
        }
    }

    cout<<"\nMatriz B: "<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<"Ingrese el digito en la posicion ("<<i<<", "<<j<<")"<<": "; cin>>x;
            B[i][j]= x;
        }
    }

    MatMultCREW();
    imprimir();
    return 0;
}

