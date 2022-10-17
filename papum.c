#include<stdio.h>
#include<stdlib.h>
//pa = 3
//pum = 5
//papum = 3,5

int main()
{
  int i,n;
  printf("Digite um numero N\n");
  scanf("%d",&n);
  system("clear");
  for(i=1;i<=n;i++){
    if(i%3==0 && i%5==0){
	printf("Pa pum!\n");
    } else if (i%5==0){
	printf("Pum!\n");
    } else if (i%3==0){
	printf("Pa!\n");
    } else {
	printf("%d\n",i);
    }
  }
  return 0;
}
