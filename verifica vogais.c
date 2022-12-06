#include<stdio.h>

int verifica_quantia_vogais(int tam,char palavra[tam])
{
    char vogais[10] = {'a','A','e','E','i','I','o','O','u','U'};
    int quantia_vogais = 0;
    for(int i=0;i<tam;i++)
    {
        printf("%c",palavra[i]);
        for(int j=0;j<10;j++)
        {
            if(palavra[i] == vogais[j])
            {
                quantia_vogais++;
                printf("quantia de vogais = %d\n",quantia_vogais);
            }
        }
    }
    return quantia_vogais;
}

int verifica_tamanho_string(int tam,char palavra[tam])
{
    int tamanho = 0;
    while(palavra[tamanho] != '\0')
    {
        tamanho++;
    }
    return tamanho;
}

int main(void)
{
    int tam = 173, quantia_vogais = 0;
    char palavra[173] = {};
    printf("Digite uma palavra:\n");
    scanf("%s",palavra);
    tam = verifica_tamanho_string(tam,palavra);
    //printf("Tamanho da palavra eh de %d\n",tam);
    quantia_vogais = verifica_quantia_vogais(tam,palavra);
    printf("A palavra tem %d vogais",quantia_vogais);
    return 0;
}