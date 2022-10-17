#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
  int segredo;
  srand(time(NULL));
  segredo = rand()%20;
  int palpite,contador=0;
  printf("Digite seu palpite entre 0 e 20\n");
  scanf("%d",&palpite);
  do{
    if (palpite < segredo){
      printf("O numero secreto é maior que seu palpite!\n");
    } else {
      printf("O numero secreto é menor que seu palpite!\n");
    }
    printf("Digite seu palpite entre 0 e 20\n");
    scanf("%d",&palpite);
    contador++;
  } while (palpite!=segredo);
  printf("Parabéns voce acertou o numero secreto com um total de %d tentativas!\n",contador);
  return 0;
}
