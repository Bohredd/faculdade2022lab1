#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Nome do Aluno: Diogo Antonio Bohrer Pereira
//Trabalho 1 da Cadeira Laboratório de Programaçacao 1 Turma Benhur

int main(){
    int numerocerto,max,min=0;
    int aux,chutepc,i=1,numeroaleatorio; // i = 1 pq ele sempre roda a primeira vez pq faz o teste depois da primeira repetição, se fizer i=0 e acertar de primeira, vai contar como 0 chutes
    printf("Digite o numero maximo do intervalo:\n");
    scanf("%d",&max);
    printf("Digite um numero para o computador chutar, entre 0 e %d:\n",max);
    scanf("%d",&numerocerto);
    printf("Nao minta para o pc na dica!\n");
    srand(time(NULL));
    numeroaleatorio = rand()%5+1; // para que toda vez ele inicialize um numero aleatorio do intervalo 20/aleatorio(0~5)
    if (numeroaleatorio == 1){ // nao quero usa o numero 1 pq ele vai ficar subtraindo 1 do numero max e assim fica chato feio enjoativo kkkkkk
        numeroaleatorio++;  // conquanto ele vai inicializar o chute como 10,6,5 ou 4, nunca como 20
    }
    do {
        chutepc = (max-min)/numeroaleatorio; // o primeiro chute sempre vai ser o numero do meio do intervalo, no caso 20/numeroaleatorio
        chutepc += min; // incrementa o valor minimo para o chute utilizando +=
        printf("O computador deu o palpite: %d\n",chutepc);
        printf("O numero eh:\n[0]Correto\n[1]Maior\n[2]Menor\n");
        scanf("%d",&aux);
        if (aux == 0){
            printf("------*------\n");
            printf("O computador acertou em um total de %d tentativas",i);
            break;
        } else if (aux==1){
            min = chutepc+1;
        } else{
            max = chutepc-1;
        }
        i++;
        printf("------*------\n");
    } while(numerocerto!=chutepc);
    return 0;
}
