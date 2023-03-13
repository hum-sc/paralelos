#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void minCRCW(int L[], int win[], int n, int indexMin){
    #pragma omp parallel for
        for (int i = 0; i < n; i++)
        {
            win[i]=0;
        }

    
    cout<<"\nPaso 1: ";
    for (int i = 0; i < n; i++)
    {
        cout<<" "<<win[i]<<", ";
    }
    
    #pragma omp parallel for
        for (int i = 0; i <n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i<j)
                {
                    if (L[i] > L[j])
                    {
                        win[i]=1;
                    }else
                    {
                        win[j]=1;
                    }
                } 
            }
        }
    cout<<"\nPaso 2: ";
    for (int i = 0; i < n; i++)
    {
        cout<<" "<<win[i]<<", ";
    }
    #pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        if (win[i]==0)
        {
            indexMin=i;
        }
    }



    cout<<"\nPaso 3, se encuentra en la posicion: "<<indexMin+1;
    cout<<"\nNumero encontrado: "<<L[indexMin];
}

int main(){
    cout<<">>>>>>>>>>>>> Bienvenido al programa de BusquedaCRCW <<<<<<<<<<<<<"<<endl;
    cout<<"Se buscara el numero mas pequeño que sea ingresado";
    int n;
    int x;
    int indexMin=0;
    cout<<"\n\nIngrese el numero total de numeros: "; cin>>n;
    
    int L[n];
    int win[n];
    
    for (int i = 0; i < n; i++)
    {
        cout<<"Ingrese el digito "<<i+1<<": "; cin>>x;
        L[i]= x;
    }
    minCRCW(L,win,n,indexMin);
    return 0;
}
