#include<stdio.h>
#include<stdlib.h>


int main()
{
    int i=100,n,aux;
    while(i<=999){
        n = i*i;
        aux = n/1000;
        n = n%1000;
        if (n+aux == i){
            printf("%d eh um numero de kaprekar\n",i);
        }
        n = 0;
        aux = 0;
        i++;
    }
    return 0;
}