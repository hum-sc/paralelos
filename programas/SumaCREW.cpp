#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <array>
#include <math.h>

using namespace std;

void Thread(int i, int j, int A[])
{
    A[j] = A[j] + A[(j-((int)pow(2,i-1)))];
}

int main(){
    
    int n;
    int x;
    cout<<"Ingrese el numero total de numeros: "; cin>>n;
    
    int A [n];
    int B [n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Ingrese el digito "<<i+1<<": "; cin>>x;
        A[i] = x;
        B[i] = x;
    }

    double log = (log2(n));

    for (int i = 1; i <= log+1; i++)
    {
        #pragma omp parallel for
            for (int j=((int)pow(2,i-1)); j< n; j++)
            {  
                Thread(i,j,A);
                Thread(i,j,B);
            }
    }

    cout<<"A: ";
    for (int i = 0; i < n; i++)
    {
        cout<<""<<A[i]<<", ";
    }

    cout<<"\nB: ";
    for (int i = 0; i < n; i++)
    {
        cout<<" "<<B[i]<<", ";
    }
    
    
    /*
    int A [] = {0,5,2,10,1,8};
    int B [] = {0,5,2,10,1,8};
    int longitud = sizeof(A)/sizeof(A[0]);

    int a = longitud-1;
    double log = (log2(a));

    for (int i = 1; i <= log+1; i++)
    {
        #pragma omp parallel for
            for (int j=((int)pow(2,i-1)+1); j <= a; j++)
            {  
                Thread(i,j,A);
                Thread(i,j,B); 
                
            }

    }
    cout<<"\nA: ";
    for (int i = 0; i <= a; i++)
    {
        cout<<" "<<A[i]<<", ";
    }
    cout<<"\nB: ";
    for (int i = 0; i <= a; i++)
    {
        
        cout<<" "<<B[i]<<", ";
    }
    */

    return 0;
}