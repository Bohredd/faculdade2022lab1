#include<stdio.h>
#include<stdlib.h>
//Um laborat�rio tem duas col�nias de bact�rias. A primeira tem 5000 indiv�duos, e a popula��o dobra a cada hora.
//A segunda tem 100000 indiv�duos, que t�m sua popula��o multiplicada por 1,8 a cada hora. Fa�a um programa, usando repeti��o,
//para calcular quantas horas ser�o necess�rias para que a popula��o da primeira col�nia seja maior que da segunda.
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
