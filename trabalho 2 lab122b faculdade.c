#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool multiplo(int a, int b)
{
  return a%b == 0;
}

bool primo(int x)
{
  if (x < 2) return false;
  for (int n = 2; n < x; n++) {
    if (multiplo(x, n)) return false;
  }
  return true;
}

int contar_primos(int comeco, int fim)
{
    int primos=0;
    for(comeco;comeco<fim;comeco++)
    {
        if(primo(comeco))
        {
            primos++;
        }
    }
    return primos;
}

int encontra_menor_intervalo(int menor,int limite, int quantia)
{
    int comeco=1, fim = limite ;
    int rotacao = 1 , total_primos=0;
    int intervalo;
    do{
        total_primos = contar_primos(comeco, fim);
        if(total_primos == menor)
        {
            intervalo = rotacao;
        }
        comeco += limite;
        fim += limite;
        rotacao++;
    } while(fim<=limite*quantia);
    return intervalo;
}

int verificar_menor_quantia_primos(int primos, int rotacoes)
{
    int menor, menor_intervalo;
    if(menor>primos)
    {
        menor = primos;
        menor_intervalo = rotacoes;
    }
    return menor;
}

int definir_limite(int limite, int quantia)
{
    int comeco, fim, rotacoes=1;
    int total_primos = 0, menor;
    int menor_intervalo;
    comeco = 1;
    fim = limite;
    do{
        total_primos = contar_primos(comeco,fim); // recebe o retorno de primos
        menor = verificar_menor_quantia_primos(total_primos,rotacoes); // recebe o retorno de verificar menor quantia
        comeco += limite;
        fim += limite;
        rotacoes++;
    } while(fim<=limite*quantia);
    menor_intervalo = encontra_menor_intervalo(menor,limite,quantia);
    printf("\n\t\t---RESULTADO---\n");
    printf("\n\tValor do limite:\t[%d]\n\tValor do Intervalo:\t[%d]\n",limite,quantia);
    printf("\t\t----=----=----\n");
    printf("\tIntervalo com menos primos comeca em:\t[%d]\n\tIntervalo termina em:\t[%d]\n\tTendo um total de:\t[%d primos]\n",1+((menor_intervalo-1)*limite),(menor_intervalo*limite),menor);
}

int main(void)
{
    int limite, quantia;
    printf("Digite o limite:\n");
    scanf("%d",&limite);
    printf("Digite a quantia de intervalos:\n");
    scanf("%d",&quantia);
    system("cls");
    printf("\n\tEstou pensando no seu resultado.....\n");
    system("pause");
    definir_limite(limite,quantia);
    return 0;
}