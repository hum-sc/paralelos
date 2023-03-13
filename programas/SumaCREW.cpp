#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <array>
#include <math.h>

using namespace std;

void Thread(int i, int j, int A[])
{
    A[j] = A[j] + A[j - (int)(pow(2, i - 1))];
}

int main(){
    cout<<">>>>>>>>>>>>> Bienvenido al programa de SumasCREW <<<<<<<<<<<<<"<<endl;


    int n;
    int x;

    cout<<"Ingrese el numero total de numeros: "; cin>>n;
    int A [n];

    for (int i = 0; i < n; i++)
    {
        cout<<"Ingrese el digito "<<i+1<<": "; cin>>x;
        A[i] = x;

    }

    int log = ceil(log2(n));

    for (int i = 1; i <= log; i++)
    {
        #pragma omp parallel for
        for (int j=n; j >=((int)pow(2,i-1)); j--)
        {  
            Thread(i,j,A);
        }

        cout<<"\nPaso numero "<<i<<":"<<endl;
        for (int k = 0; k < n; k++)
        {
            cout<<""<<A[k]<<", ";
        }
    }
    cout<<"\n\nResultado: "<<A[n-1];
    return 0;
}