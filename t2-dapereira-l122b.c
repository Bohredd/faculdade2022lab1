#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

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
    int quantia_primos=0,numero_intervalo;
    int menor_quantia,repeticoes=0;
    for(percorre;percorre<=limite;percorre++)
    {
        if(primo(percorre))
        {
            quantia_primos++;
        }
    }
    numero_intervalo = 1;
    menor_quantia = quantia_primos;
    percorre=1;
    do
    {
        for(percorre;percorre<=limite*qual_intervalo;percorre++)
        {
            if(primo(percorre))
            {
                quantia_primos++;
            }
        }

        if(quantia_primos<menor_quantia)
        {
            menor_quantia = quantia_primos;
            numero_intervalo = qual_intervalo;
            repeticoes = 1;
        } else if (quantia_primos == menor_quantia)
        {
            repeticoes++;
        }
        quantia_primos = 0;
        qual_intervalo++;

    } while (percorre<=limite*intervalo);

    if(repeticoes==1)
    {
        printf("Valor limite: [%d]\nValor intervalo: [%d]\n",limite,intervalo);
        printf("------=------\n");
        printf("""O intervalo com menos primos eh o: [%d]\nTendo comeco em: [%d] Termino em: [%d]\n------=------\nNeste intervalo ha um total de numeros primos: [%d]",numero_intervalo,((numero_intervalo-1)*limite)+1,numero_intervalo*limite,menor_quantia);
    } else if (repeticoes > 1)
    {
        printf("Valor limite: [%d]\nValor intervalo: [%d]\n",limite,intervalo);
        printf("------=------\n");
        printf("O intervalo com menos primos se repetiu : [%d vezes]\nSua primeira aparicao foi no intervalo: [%d]\nTendo comeco em: [%d] Termino em: [%d]\n------=------\nNeste intervalo ha um total de numeros primos: [%d]",repeticoes,numero_intervalo,((numero_intervalo-1)*limite)+1,numero_intervalo*limite,menor_quantia);
    }
}

int main(void)
{
    int limite, intervalo;
    printf("Digite o valor do limite:\n");
    scanf("%d",&limite);
    printf("Digite a quantia de intervalos:\n");
    scanf("%d",&intervalo);
    system("cls");
    printf("Estamos raciocinando para solucionar seu problema...\n");
    system("pause");
    setar_intervalos(limite,intervalo);
}
