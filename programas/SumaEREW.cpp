#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <array>
#include <math.h>

using namespace std;

int main(){
    cout<<">>>>>>>>>>>>> Bienvenido al programa de SumasEREW <<<<<<<<<<<<<";
    int n;
    int x;
    cout<<"Ingrese el numero total de numeros: "; cin>>n;
    
    int L[n];

    for (int i = 0; i < n; i++)
    {
        cout<<"Ingrese el digito "<<i+1<<": "; cin>>x;
        L[i]= x;
    }
    int log = ceil(log2(n));
    
    for (int i = 1; i <= log; i++)
    {
        #pragma omp parallel for
            for (int j = (int)pow(2,i)-1; j< n; j+= (int)pow(2,i))
            {
                L[j] = L[j] + L[j-((int)pow(2,i-1))];
            }


        cout<<"\nPaso numero "<<i<<":"<<endl;
        for (int k = 0; k < n; k++)
        {
            cout<<""<<L[k]<<", ";
        }
    }

    cout<<"El resultado es: "<<L[n-1];
    return 0;
}