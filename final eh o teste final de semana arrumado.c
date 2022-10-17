#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
  struct tm *data_hora_atual;
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);
  char dias[7][8] = {"Segunda","Terca","Quarta","Quinta","Sexta","Sabado","Domingo"};
  printf("Hoje eh %s feira ou nao feira kkkk, portanto...\n",dias[data_hora_atual->tm_wday-1]);
  if (data_hora_atual->tm_wday-1 == 5 || data_hora_atual->tm_wday-1 == 6)
  {
    printf("Viva! Eh final de semana!\n");
  } else {
    printf("Vai ter que acordar cedo amanha...\n");
  }
  return 0;
}
