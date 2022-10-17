#include<stdio.h>

int main()
{
  int valordiesel, tamanhotanque , totalprecoreais, totalprecocents;
  printf("Digite o valor do diesel:\n");
  scanf("%d",&valordiesel);
  printf("Digite o tamanho do tanque do caminhão:\n");
  scanf("%d",&tamanhotanque);
  totalprecoreais =  tamanhotanque*valordiesel;
  totalprecoreais = totalprecoreais/1000;
  totalprecocents = tamanhotanque*valordiesel;
  totalprecocents = totalprecocents%100;
  printf("Deu %d reais e %d centavos",totalprecoreais,totalprecocents);
  return 0;
}
