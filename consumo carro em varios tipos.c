#include<stdio.h>

int main()
{
	float gasolina, odometro, odometrofinal, kml, milgalao, milhas, galao, kml2;
	printf("----EXERCÍCIO 2----\n");
	printf("Digite a quantia de gasolina para encher o tanque do carro: \n");
	scanf("%f",&gasolina);
	printf("Digite os KM escritos no odômetro no exato momento: \n");
	scanf("%f",&odometro);
	printf("========================\n");
	printf("*----RODANDO O CARRO----*\n");
	printf("========================\n");
	printf("*--REABASTECENDO TANQUE--*\n");
	printf("Digite os KM escritos no odômetro agora que você gastou toda a gasolina do tanque: \n");
	scanf("%f",&odometrofinal);
	printf("========================\n");
	kml = odometrofinal-odometro;
	kml = kml/gasolina;
	milhas = odometrofinal-odometro;
	milhas = milhas/1,609;
	galao = gasolina/3,79;
	milgalao = milhas/galao;
	kml2 = 100/kml;
	printf("Andou um total de %.2f KM e usou um total de %.2f L de gasolina\n",odometrofinal-odometro,gasolina);
	printf("Seu carro no padrão brasileiro faz: %.2f KM/l de gasolina\n",kml);
	printf("Seu carro no padrão 100KM/xL precisa de: %.2f para rodar 100KM \n",kml2); 
	printf("Seu carro no padrão gringo faz: %.2f ML/gal de gasolina",milgalao); 
	return 0;
}
