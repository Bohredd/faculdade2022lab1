#include<stdio.h>

int verifica_se_existe_letra(int tam,char palavra[tam],char letra)
{
    int indice = -3, resposta = 0;
    for(int i=0;i<tam;i++)
    {
        if(palavra[i] == letra)
        {
            indice = i;
            break;
        }
    }
    if(indice!=-3)
    {
        printf("apareceu no indice %d\n",indice+1);
    } else {
        printf("nao apareceu na palavra\n");
    }
}

int main(void)
{
    int tam = 173;
    char palavra[173] = {},letra;
    printf("Digite uma palavra:\n");
    fgets(palavra,tam,stdin);
    printf("Digite uma letra para procurar:\n");
    scanf("%c",&letra);
    //printf("Palavra = %s e letra = %c",palavra,letra);
    verifica_se_existe_letra(tam,palavra,letra);
}