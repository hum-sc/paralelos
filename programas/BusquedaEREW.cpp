#include <iostream>
#include <array>
#include <math.h>

using namespace std;
int temp[100];

void Broadcast(int temp[], int bus, int n);
void minimo (int L[], int n);
void busquedaEREW(int L[], int bus, int n);

int main(){
    cout<<">>>>>>>>>>>>> Bienvenido al programa de BusquedaEREW <<<<<<<<<<<<<";
    int n, x, bus, resultado;
    cout<<"\n\nIngrese el numero total de numeros: "; cin>>n;
    n++;
    int L[n];
    L[0]=0;

    for (int i = 1; i < n; i++)
    {
        cout<<"Ingrese el digito "<<i<<": "; cin>>x;
        L[i]= x;
    }
    cout<<"Ingrese el numero que quiere buscar: "; cin>>bus;

    
    busquedaEREW(L,bus,n-1);
    return 0;
}

void Broadcast(int temp[], int bus, int n){
    temp[1]=bus;

    for (int i = 1; i <= ceil(log2(n)); i++)
    {
        
        #pragma omp parallel forshared(j, i)
        for (int j = (int)(pow(2, i - 1) + 1); j <= (int)pow(2,i); j++)
        {
            temp[j] = temp[j-((int)pow(2, i - 1))];
        }
    }

    cout<<"\nBroadcast: ";
    for (int i = 1; i <= n; i++)
    {
        cout<<" "<<temp[i]<<", ";
    } 
}

void minimo (int L[], int n)
{
    for (int j = 1; j <= ceil(log2(n)); j++)
    {
        #pragma omp parallel for
        
        for (int i = 1; i <= n/((int)(pow(2,j))); i++)
        {
            if (L[(2*i)-1] > L[2*i])
            {
                L[i] = L[2*i];

            }
            else
            {
                L[i]=L[(2*i)-1];
            }
        }
        for (int k = (n/((int)(pow(2,j))))+1; k <= n; k++)
        {
            L[k]=0;
        }
    }
    cout<<"\nMinimo: ";
    for (int i = 1; i <= n; i++)
    {
        cout<<" "<<L[i]<<", ";
    }
    cout<<"\nSe encuentra en la posicion: "<<temp[1]; 
}
void busquedaEREW(int L[], int bus, int n){
    Broadcast(temp,bus, n);

    #pragma omp parallel for
    for (int i = 1; i <= n; i++)
    {
        
        if (L[i] == temp[i])
        {
            temp[i] = i;
        }
        else
        {
            temp[i] = 100000;
        }            
    }

    cout<<"\nBusqueda: ";
    for (int i = 1; i <= n; i++)
    {
        cout<<" "<<temp[i]<<", ";
    }
    minimo(temp, n);
}

