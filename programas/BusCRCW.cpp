#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void minCRCW(int L[], int win[], int n, int indexMin){
    #pragma omp parallel for
        for (int i = 0; i <= n; i++)
        {
            win[i]=0;
            //cout<<"\n"<<i<<", ";
        }

    
    cout<<"\nPaso 1: ";
    for (int i = 0; i <= n; i++)
    {
        cout<<" "<<win[i]<<", ";
    }
    
    #pragma omp parallel for
        for (int i = 0; i <=n; i++)
        {
            for (int j = 0; j <= n; j++)
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
    for (int i = 0; i <= n; i++)
    {
        cout<<" "<<win[i]<<", ";
    }
    #pragma omp parallel for
    for (int i = 0; i <= n; i++)
    {
        if (win[i]==0)
        {
            indexMin=i;
        }
    }



    cout<<"\nPaso 3, indice minimo: "<<indexMin;
    cout<<"\nResultado: "<<L[indexMin];
}

int main(){
    int L [] = {95,10,6,15};
    int n = (sizeof(L)/sizeof(L[0]))-1;
    int win[n];
    int indexMin=0;
    cout<<"\nValor L: ";
    for (int i = 0; i <= n; i++)
    {
        cout<<" "<<L[i]<<", ";
    }
    
    minCRCW(L,win,n,indexMin);

    return 0;
}
