#include<stdio.h>
#include<stdlib.h>
//Um laboratório tem duas colônias de bactérias. A primeira tem 5000 indivíduos, e a população dobra a cada hora.
//A segunda tem 100000 indivíduos, que têm sua população multiplicada por 1,8 a cada hora. Faça um programa, usando repetição,
//para calcular quantas horas serão necessárias para que a população da primeira colônia seja maior que da segunda.
int main()
{
    float colonia1,colonia2;
    int contadorhoras=0;
    colonia1 = 5000;
    colonia2 = 100000;
    do{
        colonia1 *= 2;
        colonia2 *= 1.8;
        contadorhoras++;
    } while(colonia2>colonia1);
    printf("Foram necessarias: %d horas para que a colonia 1 tenha mais individuos que a colonia 2!\n",contadorhoras);
    printf("A primeria colonia possui: %.0f individuos\nA segunda colonia possui: %.0f individuos\n",colonia1,colonia2);
    printf("Ou seja, uma diferenca de %.0f individuos a mais para a colonia 1!\n",colonia1-colonia2);
    return 0;
}
