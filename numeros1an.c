#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n,i=0;
  printf("Digite o valor N\n");
  scanf("%d",&n);
  system("clear");
  do{
	printf("%d\n",i);
	i++;
  } while (i<=n);
  printf("Chegamos ao N esimo valor !\nEncerrando...\n");
  return 0;
}
