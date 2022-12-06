// T5 - Diogo Antonio Bohrer Pereira
#include<stdio.h> //INCLUDES
#include<stdlib.h>
#include<time.h>
#include<string.h>
//maximo de linhas por funcao = 22 linhas 
void cor_texto(int vermelho, int verde, int azul) //1 linha
{
    printf("\e[38;2;%d;%d;%dm", vermelho, verde, azul);
}

void cor_fundo(int vermelho, int verde, int azul) //1 linha
{
    printf("\e[48;2;%d;%d;%dm", vermelho, verde, azul);
}

void cor_normal(void) //1 linha
{
     printf("\e[m");
}

void tabelamento_cores() //17 linhas
{
    printf("----------\n");
    cor_texto(255,0,0);
    printf("Vermelho - r\n");
    cor_texto(0,0,255);
    printf("Azul - b\n");
    cor_texto(0,255,0);
    printf("Verde - g\n");
    cor_texto(255,255,0);
    printf("Amarelo - y\n");
    cor_texto(255,203,219);
    printf("Rosa - k\n");
    cor_texto(148,0,211);
    printf("Roxo - p\n");
    cor_texto(255,127,0);
    printf("Laranja - o\n");
    cor_normal();
    printf("----------\n");
}

void desenha_inicio() //11 linhas
{
    printf("----------\n");
    printf("Bem vindo ao MasterMind de Lab1!\n");
    printf("Siga os passos abaixo para um bom andamento do jogo!\n");
    printf("Cores e suas siglas\n");
    tabelamento_cores();
    printf("Durante o jogo, entre os palpites voce tambem pode visualizar");printf("suas jogadas anteriores digitando [!]\ne pode visualizar tambem as");
    printf("cores e seus codigos respectivos digitando [?]\n");
    printf("----------\n");
}

void gera_escolhas_pc(int tam,int escolhas_pc[tam]) //18 linhas 
{
    int escolha = 0,aux=0;
    srand(time(NULL));
    escolha = 1+rand()%7;
    escolhas_pc[0] = escolha;
    for(int i=0;i<tam;i++){
        escolha = 1+rand()%7;
        for(int j=0;j<i;j++){
            if(escolhas_pc[j] == escolha){
                aux = escolha;
                while(escolha==aux){
                    escolha = 1+rand()%7;
                    printf("tenho q trocar %d por %d\n",aux,escolha);
                };
                escolhas_pc[i] = escolha;
            } else {
                escolhas_pc[i] = escolha;
            }
        }
        //log 
        printf("escolha_pc %d = %d\n",i+1,escolhas_pc[i]);
    }
}

void preenche_letras(char letras[8]) //7 linhas
{
    letras[1] = 'r';
    letras[2] = 'b';
    letras[3] = 'g';
    letras[4] = 'y';
    letras[5] = 'k';
    letras[6] = 'p';
    letras[7] = 'o';
}

void preenche_cores(int cores_rgb[8][3]) // 21 linhas
{
    //vermelho
    cores_rgb[1][0] = 255;
    cores_rgb[1][1] = 0;
    cores_rgb[1][2] = 0;
    //azul
    cores_rgb[2][0] = 0;
    cores_rgb[2][1] = 0;
    cores_rgb[2][2] = 255;
    //verde
    cores_rgb[3][0] = 0;
    cores_rgb[3][1] = 255;
    cores_rgb[3][2] = 0;
    //amarelo
    cores_rgb[4][0] = 255;
    cores_rgb[4][1] = 255;
    cores_rgb[4][2] = 0;
    //rosa
    cores_rgb[5][0] = 255;
    cores_rgb[5][1] = 203;
    cores_rgb[5][2] = 219;
    //roxo
    cores_rgb[6][0] = 148;
    cores_rgb[6][1] = 0;
    cores_rgb[6][2] = 211;
    //laranja
    cores_rgb[7][0] = 255;
    cores_rgb[7][1] = 127;
    cores_rgb[7][2] = 0;
}

int pegar_cor(int valor_cor,int cores_rgb[8][3],int cor) // 2 linhas
{
    cor = cores_rgb[valor_cor][cor];
    return cor;
}

void desenha_cabecalho_resposta(int tentativa) // 7 linhas
{
    for(int j=0;j<21;j++){
        printf("-");
    }
    printf("PALPITE %d",tentativa+1);
    for(int j=0;j<21;j++){
        printf("-");
    }
    printf("\n");
}

void desenha_pino_branco() // 8 linhas
{
    int r = 255, g = 255, b = 255; //cor branca
    cor_fundo(r,g,b);
    for(int j=0;j<5;j++)
    {
        printf(" ");
    }
    cor_normal();
    printf(" ");
}

void desenha_pino_preto() // 8 linhas
{
    int r = 0, g = 0, b = 0; //cor preta
    cor_fundo(r,g,b);
    for(int j=0;j<5;j++)
    {
        printf(" ");
    }
    cor_normal();
    printf(" ");
}

void desenha_quadrado_cor(int tentativa,int i,int historico[tentativa][i],int cores_rgb[8][3],int linhas,char letras[8]) //19 linhas
{
    int r = 0, g = 1, b = 2, valor_letra = 0;
    char letra = ' ';
    r = pegar_cor((historico[tentativa][i]),cores_rgb,r);
    g = pegar_cor((historico[tentativa][i]),cores_rgb,g);
    b = pegar_cor((historico[tentativa][i]),cores_rgb,b);
    valor_letra = historico[tentativa][i];
    cor_fundo(r,g,b);
    for(int j=0;j<5;j++){
        if(j==2 && linhas==1){
            letra = letras[valor_letra];
            printf("%c",letra);
        } 
        else {
            printf(" ");
        }
    }
    cor_normal();
    printf(" ");
}

void desenha_palpite_rodada(int tentativa,int historico[tentativa][6],int cores_rgb[8][3],char letras[8]) // 15 linhas
{
    desenha_cabecalho_resposta(tentativa);
    for(int linhas=0;linhas<3;linhas++){
        for(int i=0;i<4;i++){
            desenha_quadrado_cor(tentativa,i,historico,cores_rgb,linhas,letras);
        }
        for(int i=0;i<3;i++){
            printf(" ");
        }
        for(int i=0;i<historico[tentativa][4];i++){
            desenha_pino_preto();
        }
        for(int i=0;i<historico[tentativa][5];i++){
            desenha_pino_branco();
        }
        printf("\n");
    }
}

int conta_acertos_pino_preto(int tam,int escolhas_pc[tam],int escolhas_jogador[tam]) //7 linhas
{
    int acertos = 0;
    for(int i=0;i<tam;i++){
        if(escolhas_pc[i] == escolhas_jogador[i]){
            acertos++;
        }
    }
    return acertos;
}

int conta_acertos_pino_branco(int tam,int escolhas_pc[tam],int escolhas_jogador[tam],int acertos_pretos)//15 linhas
{
    int acertos_brancos = 0,escolha_pc = 0, escolha_jogador = 0;
    for(int i=0;i<tam;i++){
        escolha_jogador = escolhas_jogador[i];
        for(int j=0;j<tam;j++){
            escolha_pc = escolhas_pc[j];
            if(escolha_jogador == escolha_pc){
                acertos_brancos++;
            }
        }
    }
    if(acertos_brancos>1){
        acertos_brancos -= acertos_pretos;
    }
    //printf("ha %d pinos brancos para printar\n",acertos_brancos);
    return acertos_brancos;
}

int converte_letra_palpite_para_numero(char palpite,int valor)//22 linhas 
{
    if(palpite=='r'){ // troca o vermelho pelo valor 1 
        valor = 1;
    } 
    else if(palpite == 'b'){//troca o azul pelo valor 2
        valor= 2;
    } 
    else if (palpite == 'g'){ //troca o verde pelo valor 3
        valor= 3;
    } 
    else if (palpite == 'y'){//troca o amarelo pelo valor 4
        valor= 4;
    } 
    else if(palpite == 'k'){//troca o rosa pelo valor 5 
        valor= 5;
    } 
    else if(palpite == 'p'){//troca o roxo pelo valor 6
        valor= 6;
    } 
    else if(palpite == 'o'){//troca o laranja pelo valor 7
        valor= 7;
    }
    return valor;
}

void printa_historico(int tentativas,int historico[tentativas][6])//13 linhas
{
    for(int i=0;i<tentativas;i++){
        printf("JOGADA %d\n",i+1);
        printf("----------\n");
        printf("CHUTES:\n");
        for(int j=0;j<4;j++){
            printf("%d ",historico[i][j]);
        }
        printf("\n");
        printf("----------\n");
        printf("ACERTOS:\n");
        printf("pino preto = %d pino branco = %d \n",historico[i][4],historico[i][5]);
        printf("----------\n");
    }
}

void pega_palpites_jogador(int tam,int escolhas_jogador[tam],int tentativas,int historico[9][6]) //21 linhas
{
    char palpite = ' ';
    int valor_palpite = 0, valor = 0;
    for(int i=0;i<tam;i++){
        printf("Digite seu %d palpite:\n",i+1);
        scanf(" %c",&palpite);
        if( palpite == '?'){
            printf("Aqui vao as cores!\n");
            tabelamento_cores();
            i -= 1;
        } 
        else if(palpite == '!'){
            printa_historico(tentativas,historico);
            i -= 1;
        }
        else{
            valor_palpite = converte_letra_palpite_para_numero(palpite,valor);
            escolhas_jogador[i] = valor_palpite;
            //printf("palpite valor = %d\n",escolhas_jogador[i]);
        }
        historico[tentativas][i] = valor_palpite;
    }
}

int loop_jogo(int tam,int escolhas_pc[tam],int escolhas_jogador[tam],int historico[9][6],char letras[8],int cores_rgb[8][3])//20 linhas
{
    int tentativas = 0, acertos_pretos = 0, fim = 0,acertos_brancos = 0;
    desenha_inicio();
    gera_escolhas_pc(4,escolhas_pc);
    while(tentativas<9){
        pega_palpites_jogador(4,escolhas_jogador,tentativas,historico);
        acertos_pretos = conta_acertos_pino_preto(4,escolhas_pc,escolhas_jogador); //conta acertos pretos
        historico[tentativas][4] = acertos_pretos;
        acertos_brancos = conta_acertos_pino_branco(4,escolhas_pc,escolhas_jogador,acertos_pretos); //conta acertos brancos
        historico[tentativas][5] = acertos_brancos;
        //log
        printf("acertos pretos = %d e acertos brancos = %d\n",acertos_pretos,acertos_brancos);
        desenha_palpite_rodada(tentativas,historico,cores_rgb,letras);
        tentativas++;
        if(acertos_pretos==4){
            printf("Parabens! Voce acertou todas as cores nas ordens corretas!\n");
            break;
        }
    }
    fim = 1;
    return fim;
}

int main(void) //19 linhas
{
    char jogar_de_novo[3], letras[8] = {};
    int escolhas_pc[4] = {}, escolhas_jogador[4] = {}, historico[9][6] = {};
    int continuidade = 1, cores_rgb[8][3] = {};
    preenche_cores(cores_rgb);
    preenche_letras(letras);
    while(continuidade!=0){
        continuidade = loop_jogo(4,escolhas_pc,escolhas_jogador,historico,letras,cores_rgb);
        printf("Voce deseja jogar novamente? Sim[sim] Nao[nao]\n");
        scanf("%s",jogar_de_novo);
        if(strcmp(jogar_de_novo,"sim")==0){
            continuidade = loop_jogo(4,escolhas_pc,escolhas_jogador,historico,letras,cores_rgb);
        }
        else if(strcmp(jogar_de_novo,"nao")==0){
            printf("Esperamos que voce volte!\n");
            continuidade = 0;
        }
    }
}