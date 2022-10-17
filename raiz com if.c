#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int avancar;
	float delta,a,b,c,x1,x2,aux;
	printf("Digite os valores de A, B e C respectivamente: \n");
	scanf("%f %f %f", &a, &b, &c);
	delta = ( b * b - 4 * a * c );
	system("clear");
	if (delta < 0) {
		printf("Não existem raízes reais nesta função! \n");
		printf("Caso deseja saber o resultado do número imaginário, escreva 1, para sair digite 0\n");
		scanf("%d",&avancar);
		if ( avancar == 1 ) {
			system("clear");
			aux = delta * (-1);
			x1 = ( -b / (2 * a));
			x2 = sqrt(aux);
			x2 = x2 / (2 * a);
			printf("Parte real: %.2f\nParte imaginária: +i e -i, onde i= %.0f\n",x1,x2);
			printf("Result 1: %.1f+%.0f(i)\nResult 2: %.1f-%.0f(i)\n",x1,x2,x1,x2);
		} else {
			return 1;
		}
	} else if ( delta > 0 ) {
		x1 = ( -b + sqrt(delta) ) / (2 * a);
		x2 = ( -b - sqrt(delta) )/ (2 * a);
		printf("Sua função possuí 2 raízes diferentes e reais!\n");
		printf("Primeira raíz: %.2f\n",x1);
		printf("Segunda raíz: %.2f\n",x2);
	} else {
		x1 = ( -b + sqrt(delta) ) / (2 * a);
		printf("Suas raízes são reais e iguais, tendo valor: %.2f \n",x1);
	}
	return 0;
}
