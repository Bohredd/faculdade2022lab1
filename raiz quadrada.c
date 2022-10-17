#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	float a,b,c,result,bhask,delt;
	printf("Digite o valor de A: \n");
	scanf("%f",&a);
	printf("Digite o valor de B: \n");
	scanf("%f",&b);
	printf("Digite o valor de C: \n");
	scanf("%f",&c);
	system("clear");
	delt = sqrt((b*b)-4*a*c);
	bhask = -b+delt;
	bhask = bhask/(2*a);
	printf("Primeira raíz: %.2f\n",bhask);
	bhask = -b-delt;
	bhask = bhask/(2*a);
	printf("Segunda raíz: %.2f\n",bhask);
	return 0;
}
