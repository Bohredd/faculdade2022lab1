#include<stdio.h>
#include<stdlib.h>

int main()
{
  float acumulador,digitado,contador=0;
  while (1) {
    printf("Digite o valor da nota do aluno:\nCaso deseja sair,digite [0]!\n");
    scanf("%f",&digitado);
    if (digitado <= 0){
      break; // ou return 0;
    } else {
       acumulador += digitado;
    }
    contador++;
  }
  printf("Voce digitou o numero 0 para encerrar o somatório, contudo, voce digitou:\n");
  printf("%.0f notas e a media final foi de: %.2f",contador,acumulador/contador);
  return 0;
}
