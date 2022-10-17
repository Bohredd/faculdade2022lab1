#include<stdio.h>
#include<time.h>

int main()
{
    char dias[7][8] = {"Segunda","Terca","Quarta","Quinta","Sexta","Sabado","Domingo"};
    int tm_wday;
    printf("Hoje eh %s feira! ou nao feira... kkkk, portanto\n",dias[tm_wday]);
    if (tm_wday == 5 || tm_wday == 6)
    {
        printf("Viva! Hoje eh final de semana!");
    } else {
        printf("Lamento.. amanha tem q acordar cedo!");
    }
    return 0;

}
