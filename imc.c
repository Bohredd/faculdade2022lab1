#include<stdio.h>
int main()
{
  float peso,altura,imc;
  printf("Digite seu peso e sua altura em cm dividos por espaço:\n");
  scanf("%f %f",&peso, &altura);
  altura = altura/100;
  imc = peso/(altura*altura);
  printf("IMC = %.2f\n",imc);

  //<18,5 = abaixo // 18,5 - 24,9 = normal // 25-29,9 = excesso // 30-34,9 = obes 1 // 35-39,9 obes 2 // > 40 = obesidade 3 

  if(imc <= 18.5)
  {
    printf("Seu peso está baixo do normal!");
  }
    else if( imc>=18.5 && imc<=24.9 )
  {
    printf("Seu peso está ideal!");
  }
    else if( imc>=25 && imc<=29.9 )
  {
    printf("Seu peso está em excesso!");
  }
    else if( imc>=30 && imc<=34.9 )
  {
    printf("Seu peso está como obesidade 1");
  }
    else if( imc>=35 && imc<=39.9 )
  {
    printf("Seu peso está como obesidade 2!");
  }
    else
  {
    printf("Seu peso está como obesidade 3!");
  }
 return 0;
}

