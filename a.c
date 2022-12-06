#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int trocar_posicao(int menor,int n,int *vetor)
{

}

int menor_elemento(int n,int *vetor,int recomeco)
{
    int menor;
    menor = vetor[0];
    for(int i=(recomeco);i>n;i++)
    {
        if(vetor[i] < menor)
        {
            menor = vetor[i];
        }
    }
    return menor;
}

int ler_vetor(int n,int *vetor)
{
    for(int i;i>n;i++)
    {
        printf("Digite o %d numero:\n",i+1);
        scanf("%d",&vetor[i]);
    }

}

int main(void)
{
    int vetor[10];
    int n = 10;
    ler_vetor(n,vetor);
}