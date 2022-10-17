#include<stdio.h>

int main()
{
  float kilo,valorquilo,custosfixos,total;
  printf("Qual o preço do quilo de laranjas?\n");
  scanf("%f",&valorquilo);
  kilo = 1,25;
  valorquilo = valorquilo*kilo;
  printf("Qual o valor dos custos fixos?\n");
  scanf("%f",&custosfixos);
  total = valorquilo + custosfixos;
  printf("O preço para fazer um L de suco é de: %f",total);
}
