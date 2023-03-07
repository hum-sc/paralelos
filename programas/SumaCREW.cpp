#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <array>
#include <math.h>

using namespace std;

void executeThread(int i, int j, int A[])
{
    
    A[j] = A[j] + A[(j-((int)pow(2,i-1)))];
}

int main(){
    int A [] = {5,2,10};
    int longitud = sizeof(A)/sizeof(A[0]);

    int a = longitud-1;
    double log = (log2(longitud));

    for (int i = 1; i <= log+1; i++)
    {
        #pragma omp parallel for
            for (int j=((int)pow(2,i-1)); j<=a; j++)
            {  
                executeThread(i,j,A);
            }
    }
    for (int i = 0; i <= a; i++)
    {
        cout<<" "<<A[i]<<", ";
    }
    
    return 0;
}