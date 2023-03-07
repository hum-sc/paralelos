#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <array>
#include <math.h>

using namespace std;

int main(){
    int A [] = {5,2,10,1,8,12,7,3};
    int longitud = sizeof(A)/sizeof(A[0]);

    int a = longitud-1;
    
    double log = (log2(longitud));

    for (int i = 1; i <= log; i++)
    {
        #pragma omp parallel for
            for (int j = (int)pow(2,i)-1; j<=a; j+= (int)pow(2,i))
            {
                A[j] = A[j] + A[j-((int)pow(2,i-1))];
            }
    }

    for (int i = 0; i <= a; i++)
    {
        cout<<" "<<A[i]<<", ";
    }

    return 0;
}