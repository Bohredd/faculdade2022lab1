#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

int definir_menor_quantia(int intervalo,int *vet,int limite)
{
    int menor,y=1,qual_intervalo;
    int aux=0;
    menor = vet[y];
    for(y;y<=intervalo;y++)
    {
        if(vet[y]<menor)
        {
            menor = vet[y];
            qual_intervalo = y;
            printf("menor = %d",menor);
            aux = 0;
        } else if (vet[y] == menor)
        {
            aux++;
        }
    }
    if(qual_intervalo == 0 )
    {
        qual_intervalo++;
    }

    if(aux==0)
    {
        printf("A menor quantidade de primos eh %d e foi no intervalo %d",menor,qual_intervalo);
    } else if (aux>=1)
    {
        printf("A menor quantidade de primos eh %d e teve sua primeira aparicao no intervalo %d",menor,qual_intervalo);
    }
}

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

int setar_intervalos(int limite,int intervalo)
{
    int percorre=1,qual_intervalo=1;
    int quantia_primos=0;
    int vet[intervalo];
    do
    {
        for(percorre;percorre<=limite*qual_intervalo;percorre++)
        {
            if(primo(percorre))
            {
                quantia_primos++;
            }
        }
        printf("primos %d\n",quantia_primos);
        vet[qual_intervalo] = quantia_primos;
        quantia_primos = 0;
        qual_intervalo++;
    } while (percorre<=limite*intervalo) ;
    printf("intervalo = %d\n vetor = %d\n limite = %d",intervalo,vet,limite);
    definir_menor_quantia(intervalo,vet,limite);
}

int main(void)
{
    int limite, intervalo;
    printf("Digite o valor do limite:\n");
    scanf("%d",&limite);
    printf("Digite a quantia de intervalos:\n");
    scanf("%d",&intervalo);
    setar_intervalos(limite,intervalo);
}