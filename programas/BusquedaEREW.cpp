#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void Broadcast(int x, int n, double log, int temp[]){
    temp[0]=x;

    for (int i = 1; i <=log; i++)
    {
        
        #pragma omp parallel for
        for (int j = (int)pow(2,i-1); j <= (int)pow(2,i); j++)
        {
            temp[j] = temp[j-(int)pow(2,i-1)];
        }
        

    }
 
}

void busquedaEREW(int n, int L[], int temp[]){
   #pragma omp parallel for
    for (int i = 1; i <= n; i++)
    {
        
        if (L[i] == temp[i])
        {
            temp[i] = i;
        }
        else
        {
            temp[i] = 0;
        }
        
            
    }
}

void minimo (int n, double log, int temp[], int L[]){
    
    for (int j = 1; j <log+1; j++)
    {
        #pragma omp parallel for
        for (int i = 1; i <= (n/(int)pow(2,j)); i++)
        {
            if (temp[(int)(pow(2,i)-1)] > temp[(int)pow(2,i)])
            {
                temp[i]=temp[(int)pow(2,i)];
            }
            else
            {
                temp[i]=temp[(int)(pow(2,i)-1)];
            }
        }
    }

    cout<<"\nMinimo: ";
    for (int i = 0; i <= n; i++)
    {
        cout<<" "<<temp[i]<<", ";
    }
}

int main(){
    //int temp[] = {0,0,0,0};
    int x = 5;
    int L [] = {2,-1,23,-4,2,5,-2,0,5,1,5,-5,8,5,3,-2};
    int n1 = (sizeof(L)/sizeof(L[0]))-1;

    int temp[n1+1];
    for (int i = 0; i <= n1; i++)
    {
        temp[i]=0;
    }
    int n = (sizeof(temp)/sizeof(temp[0]))-1;

    double log = (log2(n+1));
    

    Broadcast(x,n,log,temp);
    cout<<"\nBroadcast: ";
    for (int i = 0; i <= n; i++)
    {
        cout<<" "<<temp[i]<<", ";
    } 

    //int L [] = {2,-1,23,-4,2,5,-2,0,5,1,5,-5,8,5,3,-2};
    //int L [] = {95,10,6,15};
    //int n1 = (sizeof(temp)/sizeof(temp[0]))-1;

    busquedaEREW(n1,L,temp);
    
    cout<<"\nBusqueda: ";
    for (int i = 0; i <= n; i++)
    {
        cout<<" "<<temp[i]<<", ";
    }
    

    minimo(n1,log,temp, L);
    int h=1, pos = 0;
    int n2 = (sizeof(temp)/sizeof(temp[0]))-1;
    while(h<n2){
        if(temp[h]!=0){
            pos=temp[h];
        break;
        }  
    h=h+1;
    }
    


    cout<<"\nResultado: "<<pos;
    return 0;
}
