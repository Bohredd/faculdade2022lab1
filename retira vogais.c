#include<stdio.h>

void verifica_quantia_vogais(int tam,char palavra[tam])
{
    char vogais[10] = {'a','A','e','E','i','I','o','O','u','U'};
    char nova_palavra[173] = {};
    int indice = 0;
    for(int i=0;i<tam;i++)
    {
        //printf("%c",palavra[i]);
        for(int j=0;j<10;j++)
        {
            if(palavra[i] == vogais[j])
            {
                indice = 1;
            }
        }
        if(indice == 0)
        {
            printf("%c",palavra[i]);
        }
        indice = 0;
    }
}

int verifica_tamanho_string(int tam,char palavra[tam])
{
    int tamanho = 0;
    while(palavra[tamanho] != '\0')
    {
        tamanho++;
    }
    tamanho+=2;
    if(palavra[tamanho] != '\0')
    {
        while(palavra[tamanho] != '\0')
        {
            tamanho++;
        }
    }
    else {
        tamanho-=2;
    }
    return tamanho;
}

int main(void)
{
    int tam = 173, quantia_vogais = 0;
    char palavra[173] = {};
    printf("Digite uma palavra:\n");
    fgets(palavra,173,stdin);
    printf("palavra = %s",palavra);
    tam = verifica_tamanho_string(tam,palavra);
    printf("tamanho = %d\n",tam);
    verifica_quantia_vogais(tam,palavra);
    return 0;
}