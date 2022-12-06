#include<stdio.h>
#include<stdbool.h>

bool verifica_palindromo(int tam,char vetor_invertido[tam],char palavra[tam])
{
    int aux = 0;
    for(int i=0;i<tam;i++)
    {
        printf("%c = %c\n",vetor_invertido[i],palavra[i]);
        if(vetor_invertido[i] == palavra[i])
        {
            aux++;
        } else {
        }
        printf("aux = %d\n",aux);
    }
    if(aux == tam)
    {
        return true;
    } else {
        return false;
    }
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

void cria_vetor_invertido(int tam,char palavra[tam])
{
    char vetor_invertido[173] = {};
    int aux = 0;
    bool resposta;
    aux = tam;
    for(int i=0;i<tam;i++)
    {
        aux--;
        vetor_invertido[aux] = palavra[i];
        //printf("%c",vetor_invertido[i]);
        //aux--;
    }
    printf("\n");
    printf("-------\n");
    for(int i=0;i<tam;i++)
    {
        printf("%c",vetor_invertido[i]);
    }
    printf("\n");
    resposta = verifica_palindromo(tam,vetor_invertido,palavra);
    if(resposta)
    {
        
    }
}

int main(void)
{
    int tam = 173;
    char palavra[173] = {};
    printf("Digite uma palavra para testar se eh um palindromo:\n");
    scanf("%s",palavra);
    tam = verifica_tamanho_string(tam,palavra);
    //    printf("Tamanho da string eh de %d\n",aux);
    cria_vetor_invertido(tam,palavra);
}