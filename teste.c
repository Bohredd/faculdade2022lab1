#include<stdio.h>
#include<stdio.h>
#include<time.h>

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

void desenha_cabecalho_resposta(int tentativa) //8 linhas
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

int pegar_cor(int valor_cor,int cores_rgb[8][3],int cor) // 2 linhas
{
    cor = cores_rgb[valor_cor][cor];
    return cor;
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

void loop_jogo(int historicos[9][6],int cores_rgb[8][3],int tentativa,char letras[8][3]){

}

int main(void)
{
    char letras[8] = {};
    int tentativa = 0,continuidade = 1;
    int historico[9][6] = {}, cores_rgb[8][3] = {};
    preenche_letras(letras);
    preenche_cores(cores_rgb);
    while(continuidade=1){
        
    }
}