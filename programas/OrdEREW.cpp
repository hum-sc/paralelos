#include <iostream>
#include <array>
#include <math.h>

using namespace std;


void mergeSort(int L[], int n);
void interchange(int L[], int a, int b);
void oddEvenSplit(int L[], int odd[], int even[], int n);
void oddEvenMerge(int L[], int n);


int main(){
    cout<<">>>>>>>>>>>>> Bienvenido al programa de OrdenamientoEREW <<<<<<<<<<<<<";
    int n;
    int x;

    cout<<"\n\nIngrese el numero total de numeros: "; cin>>n;
    
    int L[n];
    
    
    for (int i = 0; i < n; i++)
    {
        cout<<"Ingrese el digito "<<i+1<<": "; cin>>x;
        L[i]= x;
    }
    //*/
    cout<<"Arreglo original: ";

    for (int x = 0; x < n; x++)
    {
        cout<<L[x]<<", ";
    }

    mergeSort(L,n);

    
    cout<<"\nArreglo acomodado: ";

    for (int x = 0; x < n; x++)
    {
        cout<<L[x]<<", ";
    }
    
    return 0;
}

void mergeSort(int L[],int n){
    
    //cout<<"\nInicio de la funcion";
        
    if (n >= 2)
    {
        int m = (int)n / 2;

        int B[m];
        for (int i = 0; i < m; i++)
        {
            B[i] = L[2 * i];
        }

        int C[m];
        for (int i = m; i < n; i++)
        {
            C[i - m] = L[2 * (i - m) + 1];
        }


        #pragma omp critical 
        {
            
            mergeSort(B, m);
            mergeSort(C, m);
        }
        oddEvenMerge(L, n);
  
    } 
}

void interchange(int L[], int a, int b)
{
    int aux;
    aux = L[a];
    L[a] = L[b];
    L[b] = aux;
}

void oddEvenSplit(int L[], int odd[], int even[], int n)
{
#pragma omp parallel for
    for (int i = 0; i < (int)n / 2; i++)
    {
        odd[i] = L[2 * i];
        even[i] = L[2 * i + 1];
    }
}

void oddEvenMerge(int L[], int n)
{
    if (n == 2)
    {
        if (L[0] > L[1])
        {
            interchange(L, 0, 1);
        }
    }
    else
    {
        
        int m = (int)n / 2;
        int odd[m];
        int even[m];

        oddEvenSplit(L, odd, even, n);

        #pragma omp critical 
        {
            oddEvenMerge(odd, m);
            oddEvenMerge(even, m);
        }

        #pragma omp parallel for
        for (int i = 0; i < (int)n / 2; i++)
        {
            L[2 * i] = odd[i];
            L[2 * i + 1] = even[i];
        }

        #pragma omp parallel for
        for (int i = 0; i < n - 1; i++)
        {

            if ((L[i]) > (L[i + 1]))
            {
                interchange(L, i, i + 1);
            }
        }
    }
}
