#include<stdio.h>
#include<stdlib.h>
//Altere o programa das m�dias, para que calcule duas m�dias, a dos valores pares e a dos �mpares.

int main()
{
    int numero,i,contadorimp=0,contadorpar=0;
    float mediaimpar,mediapar;
    for(i=0;i<6;i++){
        printf("Digite uma nota para fazermos as medias pares e impares:\n");
        scanf("%d",&numero);
        if(numero%2==0){
            mediapar += numero;
            contadorpar++;
        } else if (numero%2!=0){
            mediaimpar += numero;
            contadorimp++;
        }
        printf("---*---\n");
    }
    printf("A media dos impares deu: %.1f\nA media dos pares deu: %.1f\n",mediaimpar/contadorimp,mediapar/contadorpar);
    printf("---*---\n");
    return 0;
}
