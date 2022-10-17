#include<stdio.h>
int main()
{
	float cat1, cat2, hip, area;
	printf("---- EXERCÍCIO 1 ----\n");
	printf("Digite o 1° cateto: \n");
	scanf("%f",&cat1);
	printf("DIgite o 2° cateto: \n");
	scanf("%f",&cat2);
	area = (cat1*cat2)/2;
	printf("A área é de : %.2f",area);
	return 0;
}
