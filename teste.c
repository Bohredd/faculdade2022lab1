#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int numerocerto,max=20,min=0,aux,chutepc,i=1; // i = 1 pq ele sempre roda a primeira vez pq faz o teste depois da primeira repetição, se fizer i=0 e acertar de primeira, vai contar como 0 chutes
    printf("Digite um numero para o computador chutar, entre 0 e 20:\n");
    scanf("%d",&numerocerto);
    srand(time(NULL));
    chutepc = rand()%20;
    do {
        printf("O computador deu o palpite: %d\n",chutepc);
        printf("O numero eh:\n[0]Correto\n[1]Maior\n[2]Menor\n");
        scanf("%d",&aux);
        if (aux == 0 && numerocerto == chutepc){
            printf("O computador acertou em um total de %d tentativas",i);
            break;
        } else if (aux==0 && numerocerto != chutepc){
            printf("Tu disse ser certo mas nao eh o mesmo numero nao! Coisa feia mentiroso...\nVamos continuar ate vc falar a verdade!\n");
        } else if (aux==1){
            chutepc = rand()%20;
            while (chutepc < numerocerto){
                chutepc+=chutepc/2;
            }
        } else {
            chutepc = rand()%chutepc;
            if (chutepc > numerocerto){
                chutepc -= 2;
            }
        }
        i++;
    } while(numerocerto!=chutepc);
    if (numerocerto==chutepc){ // para printar se o computador acertar antes de eu poder dar o valor da var aux 0 1 2
            printf("Acertei na %d tentativa com o palpite %d!!",i,chutepc);
    }
    return 0;
}
