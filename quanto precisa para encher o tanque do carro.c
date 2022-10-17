#include<stdio.h>

int main()
{
	float odometro1,odometro2, gasolina,aux;
	printf("Digite o valor no odomêtro inicial: \n");
	scanf("%f",&odometro1);
	printf("Digite o valor no odomêtro final: \n");
	scanf("%f",&odometro2);
	printf("Digite quantos L de gasolina para encher o tanque: \n");
	scanf("%f",&gasolina);
	odometro2 = odometro2-odometro1;
	aux = odometro2;
	odometro1 = odometro2/gasolina;
	printf("Seu carro faz %.2f KM/l \n",odometro1);
	odometro1 = odometro2/1,609;
	odometro2 = gasolina/3,79;
	odometro1 = odometro1/odometro2;
	printf("Seu carro faz %.2f MIL/gal \n",odometro1);
	odometro1 = aux/gasolina;
	odometro1 = 100/odometro1;
	printf("seu carro precisa de %.2f L de gasolina para rodar 100KM \n",odometro1);
	return 0;
}
