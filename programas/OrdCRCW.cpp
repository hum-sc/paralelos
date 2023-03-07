#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void sortCRCW(int L[], int win[], int n){
    int L2[n];
    #pragma omp parallel for
        for (int i = 0; i < n; i++)
        {
            win[i]=0;
            L2[i]=0;
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
                        win[i]=win[i]+1;
                    }else
                    {
                        win[j]=win[j]+1;
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
        L2[win[i]]=L[i];
    }
    
    
    cout<<"\nResultado: ";
    for (int i = 0; i < n; i++)
    {
        cout<<L2[i]<<", ";
    }
    
}

int main(){
    int n;
    int x;

    cout<<"Ingrese el numero total de numeros: "; cin>>n;
    
    int L[n];
    int win[n];
    
    for (int i = 0; i < n; i++)
    {
        cout<<"Ingrese el digito "<<i+1<<": "; cin>>x;
        L[i]= x;
    }

    sortCRCW(L,win,n);
    /*
    int L [] = {95,10,6,15};
    int L [] = {2,-1,23,-4,2,5,-2,0,5,1,5,-5,8,5,3,-2};
    int n = (sizeof(L)/sizeof(L[0]))-1;
    int win[n];
    int indexMin=0;
    cout<<"\nValor L: ";
    for (int i = 0; i <= n; i++)
    {
        cout<<" "<<L[i]<<", ";
    }
    
    sortCRCW(L,win,n);
    */
    

    return 0;
}