#include<stdio.h>

int main()
{
  int ano;
  printf("Digite o ano que você deseja testar:\n");
  scanf("%d",&ano);
  if ( ano % 400 == 0 || ano % 4 == 0 && ano%100 != 0)
  {
    printf("Seu ano é bissexto! ");
  } else {
    printf("Seu ano NÃO É bissexto!");
  }
  return 0;
}
