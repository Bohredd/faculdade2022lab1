#include<stdio.h>
int main()
{
	int numero;
	printf("Digite um numero:\n");
	scanf("%d",&numero);
	if (numero%2 == 0) 
	{
		printf("Seu numero eh par!");
	} else {
		printf("Seu numero eh impar!");
	}
	return 0;
}
