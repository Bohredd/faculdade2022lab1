#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//T5
//Aluno: Diogo Antonio Bohrer Pereira
//Matrícula: 202220628
//Login NCC: dapereira

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
    cores_rgb[5][1] = 0;
    cores_rgb[5][2] = 132;
    //roxo
    cores_rgb[6][0] = 148;
    cores_rgb[6][1] = 0;
    cores_rgb[6][2] = 211;
    //laranja
    cores_rgb[7][0] = 255;
    cores_rgb[7][1] = 127;
    cores_rgb[7][2] = 0;
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


void estrela()
{
    cor_texto(255,255,0);
    for(int i=0;i<5;i++){
        printf(" ");
    }
    printf("X");
    for(int i=0;i<5;i++){
        printf(" ");
    }
    printf("\n");
    cor_normal();
}

int sorteia_bola_vermelha(int i,int bola_vermelha)
{
    srand(time(NULL));
    bola_vermelha = rand()%i+1;
    return bola_vermelha;
}

void arvore()
{
    int riscos = 0,bola_vermelha = 0;
    for(int i=1;i<=12;i++){
        riscos = 11-i;
        riscos /= 2;
        bola_vermelha = sorteia_bola_vermelha(i,bola_vermelha);
        for(int j=riscos;j>=1;j--){
            printf(" ");
        }
        for(int h=0;h<i;h++){
            if(h==bola_vermelha){
                cor_texto(255,0,0);
                printf("*");
                cor_texto(0,255,0);
            } else printf("*");
        }
        for(int j=riscos;j>=1;j--){
            printf(" ");
        }
        printf("\n");
        i++;
    }
}

void caule()
{
    cor_texto(150,75,0);
    for(int i=0;i<5;i++){
        printf(" ");
    }
    printf("T");
    for(int i=0;i<5;i++){
        printf(" ");
    }
    printf("\n");
    cor_normal();
}

void arvore_natal()
{
    estrela();
    cor_texto(0,255,0);
    arvore();   
    cor_normal();
    caule();
    cor_texto(0,255,0);
    printf("Feliz natal!\n");
    cor_normal();
}

void desenha_tracos() // 4 linhas
{
    for(int i=0;i<50;i++){
        printf("-");
    }
    printf("\n");
}

void tabelamento_cores() //17 linhas
{
    desenha_tracos();
    cor_texto(255,0,0);
    printf("Vermelho - r\n");
    cor_texto(0,0,255);
    printf("Azul - b\n");
    cor_texto(0,255,0);
    printf("Verde - g\n");
    cor_texto(255,255,0);
    printf("Amarelo - y\n");
    cor_texto(255,0,132);
    printf("Rosa - k\n");
    cor_texto(148,0,211);
    printf("Roxo - p\n");
    cor_texto(255,127,0);
    printf("Laranja - o\n");
    cor_normal();
    desenha_tracos();
}

void desenha_inicio() //21 linhas
{
    desenha_tracos();
    cor_texto(255,255,0);
    printf("Bem vindo ao MasterMind de Lab1!\n");
    cor_normal();
    printf("Siga os passos abaixo para um bom andamento do jogo!\n");
    printf("Cores e suas siglas\n");
    tabelamento_cores();
    printf("Durante o jogo, entre os palpites voce tambem pode\nvisualizar");
    printf(" suas jogadas anteriores digitando ");
    cor_texto(255,255,0);
    printf("[!]\n");
    cor_normal();
    printf("e pode visualizar tambem as");
    printf("cores e seus codigos \nrespectivos digitando ");
    cor_texto(255,255,0);
    printf("[?]\n");
    cor_normal();
    printf("Caso nao consiga ganhar da nossa inteligencia, \ndigite ");
    cor_texto(255,255,0);
    printf("desistir!\n");
    cor_normal();
    desenha_tracos();
}

int converte_letra_palpite_para_numero(int i,char palpite[i],int valor)//22 linhas 
{
    if(palpite[i] == 'R'){ // troca o vermelho pelo valor 1 
        valor = 1;
    } 
    else if(palpite[i] == 'B'){//troca o azul pelo valor 2
        valor= 2;
    } 
    else if (palpite[i] == 'G'){ //troca o verde pelo valor 3
        valor= 3;
    } 
    else if (palpite[i] == 'Y'){//troca o amarelo pelo valor 4
        valor= 4;
    } 
    else if(palpite[i] == 'K'){//troca o rosa pelo valor 5 
        valor= 5;
    } 
    else if(palpite[i] == 'P'){//troca o roxo pelo valor 6
        valor= 6;
    } 
    else if(palpite[i] == 'O'){//troca o laranja pelo valor 7
        valor= 7;
    }
    return valor;
}

void converter_letra_numero(char palpites[4],int escolhas_jogador[4]) // 6 linhas
{
    int valor = 0;
    for(int i=0;i<4;i++){
        valor = converte_letra_palpite_para_numero(i,palpites,valor);
        escolhas_jogador[i] = valor;
        valor = 0;
    }
}

int gera_num_ate_nao_ter_na_escolha(int tam,int escolha_pc[tam]) //19 linhas
{
    int help = 0,escolha = 0, aux = 0;
    srand(time(NULL));
    while(aux == 0){
        escolha=1+rand()%7;
        for(int i=0;i<tam;i++){
            if(escolha==escolha_pc[i]){
                help++;
            }
        }
        if(help == 0){
            aux=1;
        } 
        else {
            aux = 0;
        }
        help = 0;
    }
    return escolha;
}

int verifica_se_ja_existe_na_escolha(int i,int tam,int escolha_pc[tam],int escolha) //7 linhas
{
    int resposta = 1;
    for(int j=0;j<i;j++){
        if(escolha==escolha_pc[j]){
            resposta = 0;
        }
    }
    return resposta;
}

void sorteia_cores_pc(int tam,int escolha_pc[tam]) //14 linhas
{
    int escolha = 0, resposta = 0;
    srand(time(NULL));
    for(int i=0;i<tam;i++){
        escolha = 1+rand()%7;
        resposta = verifica_se_ja_existe_na_escolha(i,tam,escolha_pc,escolha);
        if(resposta==1){
            escolha_pc[i] = escolha;
        } 
        else{
            escolha = gera_num_ate_nao_ter_na_escolha(tam,escolha_pc);
            escolha_pc[i] = escolha;
        }
        resposta = 0;
    }
}

void preenche_letras(char letras[8]) //7 linhas
{
    letras[1] = 'R';
    letras[2] = 'B';
    letras[3] = 'G';
    letras[4] = 'Y';
    letras[5] = 'K';
    letras[6] = 'P';
    letras[7] = 'O';
}

int verifica_vetor_palpite(int p[4]) //11 linhas
{
    int aux = 0;
    for(int i=0;i<4;i++){
        if(p[i] == 1){
            aux = 1;
        } else {
            aux = 0;
            return aux;
            break;
        }
    }
    return aux;
}

int verifica_palpite_real(char palpites[4]) //15 linhas
{
    char letras[8] = {};
    preenche_letras(letras);
    int p[4] = {}, aux = 0;
    for(int i=0;i<4;i++){
        for(int j=1;j<8;j++){
            if(palpites[i] == letras[j]){
                aux = 1;
            } 
        }
        if(aux == 1){
            p[i] = aux;
            aux = 0;
        }
    }
    aux = verifica_vetor_palpite(p);
    return aux;
}

void zera_palpites(char palpites[4]) //3 linhas
{
    for(int i=0;i<4;i++){
        palpites[i] = '\0';
    }
}

void deixa_maiusculo(char palpites[4]) //3 linhas
{
    for(int i=0;i<4;i++){
        palpites[i] = toupper(palpites[i]);
    }
}

int descobre_tamanho_string(char palpites[9]) // 5 linhas
{
    int p = 0;
    while(palpites[p] != '\0'){
        p++;
    }
    return p;
}

int pegar_cor(int valor_cor,int cores_rgb[8][3],int cor) // 2 linhas
{
    cor = cores_rgb[valor_cor][cor];
    return cor;
}

void desenha_quadrado_cor(int i,int tentativas,int historico[9][6],char letras[8],int cores_rgb[8][3],int linha) // 15 linhas
{
    int r = 0, g = 1 , b = 2;
    r = pegar_cor(historico[tentativas][i],cores_rgb,r);
    g = pegar_cor(historico[tentativas][i],cores_rgb,g);
    b = pegar_cor(historico[tentativas][i],cores_rgb,b);
    printf(" ");
    for(int coluna=0;coluna<5;coluna++){
        cor_fundo(r,g,b);
        if(linha == 1 && coluna == 2){
            printf("%c",letras[historico[tentativas][i]]);
        } else
        {
            printf(" ");
        }
    }   
    cor_normal();
    printf(" ");
}

void printar_palpite_rodada(int tentativas,int palpites[4],int acertos_brancos,int acertos_pretos,int historico[9][6]) //18 linhas
{
    char letras[8] = {};
    int cores_rgb[8][3] = {};
    preenche_cores(cores_rgb);
    preenche_letras(letras);
    for(int linhas=0;linhas<3;linhas++){
        for(int i=0;i<4;i++){
            desenha_quadrado_cor(i,tentativas,historico,letras,cores_rgb,linhas);
        }
        for(int i=0;i<3;i++){
            printf(" ");
        }
        for(int i=0;i<acertos_pretos;i++){
            desenha_pino_preto();
        }
        for(int i=0;i<acertos_brancos;i++){
            desenha_pino_branco();
        }
        printf("\n");
    }
}

void desenha_quadrado_resposta(int i,char letras[8],int cores_rgb[8][3],int linhas,int escolhas_pc[4])
{
    int r = 0, g = 1 , b = 2;
    r = pegar_cor(escolhas_pc[i],cores_rgb,r);
    g = pegar_cor(escolhas_pc[i],cores_rgb,g);
    b = pegar_cor(escolhas_pc[i],cores_rgb,b);
    printf(" ");
    for(int coluna=0;coluna<5;coluna++){
        cor_fundo(r,g,b);
        if(linhas == 1 && coluna == 2){
            printf("%c",letras[escolhas_pc[i]]);
        } else
        {
            printf(" ");
        }
    }   
    cor_normal();
    printf(" ");
}

void printar_resposta_certa(int escolhas_pc[4])
{
    char letras[8] = {};
    int cores_rgb[8][3] = {};
    preenche_cores(cores_rgb);
    preenche_letras(letras);
    for(int linhas=0;linhas<3;linhas++){
        for(int i=0;i<4;i++){
            desenha_quadrado_resposta(i,letras,cores_rgb,linhas,escolhas_pc);
        }
        for(int i=0;i<3;i++){
            printf(" ");
        }
        printf(" \n");
    }
}

void perdeu(int escolhas_pc[4])
{
    cor_texto(255,0,0);
    printf("Voce perdeu...\n");
    cor_normal();
    printf("Respostas certas seriam...\n");
    printar_resposta_certa(escolhas_pc);
}

void desistindo(int escolhas_pc[4])
{ //10 linhas
    cor_texto(255,0,0);
    printf("\n");
    printf("Voce desistiu...\n");
    cor_normal();
    printf("Respostas certas seriam...\n");
    printar_resposta_certa(escolhas_pc);
    exit(3);
}

int verifica_acertos_brancos(int escolha_pc[4],int palpites_jogador[4],int acertos_brancos,int acertos_pretos) //14 linhas
{
    int escolha_pcs = 0, escolha_jogador = 0;
    for(int i=0;i<4;i++){
        escolha_jogador = palpites_jogador[i];
        for(int j=0;j<4;j++){
            escolha_pcs = escolha_pc[j];
            if(escolha_jogador == escolha_pcs){
                acertos_brancos++;
            }
        }
    }
    if(acertos_brancos>1){
        acertos_brancos -= acertos_pretos;
    }
    return acertos_brancos;
}

int verifica_acertos_pretos(int escolhas_jogador[4],int escolhas_pc[4]) // 7 linhas
{
    int acertos_pretos = 0;
    for(int i=0;i<4;i++){
        if(escolhas_jogador[i] == escolhas_pc[i]){
            acertos_pretos++;
        }
    }
    return acertos_pretos;
}

void insere_historico(int acertos_pretos,int acertos_brancos,int escolhas_jogador[4],int historico[9][6],int rodadas) // 5 linhas
{
    for(int i=0;i<4;i++){
        historico[rodadas][i] = escolhas_jogador[i];
    }
    historico[rodadas][4] = acertos_pretos;
    historico[rodadas][5] = acertos_brancos;
}

void printar_historico(int rodadas,int historico[9][6],int escolhas_jogador[4],int escolhas_pc[4]) // 7 linhas
{
    int acertos_brancos = 0, acertos_pretos = 0;
    for(int f=1;f<rodadas;f++){
        printf("RODADA %d TEVE PALPITES...\n",f);
        acertos_pretos = historico[f][4];
        acertos_brancos = historico[f][5];
        printar_palpite_rodada(f,escolhas_jogador,acertos_brancos,acertos_pretos,historico);
    }
}

void faz_funcao_do_tamanho(int tamanho,char palpites[9],int escolhas_pc[4],int rodadas,int historico[9][6],int escolhas_jogador[4],int acertos_brancos,int acertos_pretos)//17 linhas
{
    if(tamanho == 2){
        if(palpites[0] == '!'){
            printar_historico(rodadas,historico,escolhas_jogador,escolhas_pc);
        }
        else if(palpites[0] == '?'){
            tabelamento_cores();
        }
        else {
            printf("escreveu algo errado!\n");
        }
    } 
    else if(tamanho == 8){
        char desistir[9] = "desistir";
        if(strcmp(palpites,desistir)==0){
            desistindo(escolhas_pc);
        }
        else printf("erro!\n");
    }
}

int verifica_repeticao(char palpites[4]) // 15 linhas
{
    int aux = 0;
    for(int i=0;i<4;i++){
        for(int j=i;j<4;j++){
            if(palpites[i] == palpites[j]){
                aux++;
            }
        }
    }
    if(aux == 5){
        aux = 0;
        cor_texto(255,0,0);
        printf("Houve repeticao no palpite...\n");
        cor_normal();
    } else aux = 1;
    return aux;
}

int pega_palpites_jogador(char palpites[9],int rodadas,int escolhas_pc[4],int historico[9][6],int escolhas_jogador[4],int acertos_brancos,int acertos_pretos)
{ // 19 linhas
    int tamanho = 0, aux = 0;
    zera_palpites(palpites);
    cor_texto(0,255,0);
    printf("Digite seu palpite da %d rodada!\n",rodadas);
    cor_texto(0,0,255);
    fflush(stdin);
    fgets(palpites,9,stdin);
    cor_normal();
    tamanho = descobre_tamanho_string(palpites);
    faz_funcao_do_tamanho(tamanho,palpites,escolhas_pc,rodadas,historico,escolhas_jogador,acertos_brancos,acertos_pretos);
    if(tamanho == 5){
        deixa_maiusculo(palpites);
        aux = verifica_palpite_real(palpites);
    }
    else if(tamanho == 8 || tamanho == 2){
        aux = 2;
    }
    return aux;
}

void parabens(int rodadas){
    printf("\n\n");
    arvore_natal();
    cor_texto(0,255,0);
    printf("Parabensss!\n");
    printf("Voce ganhou da nossa IA em um total de %d tentativas!...\n",rodadas);
    cor_normal();
    printf("\n");
}

void capatcao_palpites(char palpites[9],int rodadas,int escolhas_pc[4],int historico[9][6],int escolhas_jogador[4],int acertos_brancos,int acertos_pretos) //15 linhas
{
    int aux = 0;
    while(aux == 0){
        zera_palpites(palpites);
        aux = pega_palpites_jogador(palpites,rodadas,escolhas_pc,historico,escolhas_jogador,acertos_brancos,acertos_pretos);
        if(aux == 0){
            cor_texto(255,0,0);
            printf("Voce digitou algo errado...\n");
            cor_normal();
        } 
        else if(aux==2){
            aux = 0;
        } 
        else {
            aux = verifica_repeticao(palpites);
        }
    }
}


int rodada(int rodadas,int escolhas_pc[4],int historico[9][6]) // 10 linhas
{
    int acertos_pretos = 0,acertos_brancos = 0, escolhas_jogador[4] = {};
    char palpites[9];
    capatcao_palpites(palpites,rodadas,escolhas_pc,historico,escolhas_jogador,acertos_brancos,acertos_pretos);
    converter_letra_numero(palpites,escolhas_jogador);
    acertos_pretos = verifica_acertos_pretos(escolhas_jogador,escolhas_pc);
    acertos_brancos = verifica_acertos_brancos(escolhas_pc,escolhas_jogador,acertos_brancos,acertos_pretos);
    insere_historico(acertos_pretos,acertos_brancos,escolhas_jogador,historico,rodadas);
    printf("\n");
    printar_palpite_rodada(rodadas,escolhas_jogador,acertos_brancos,acertos_pretos,historico);
    printf("\n");
    return acertos_pretos;
}

int pegar_continuacao(char jogar[4],int resposta)
{
    printf("Deseja jogar novamente? nao ou sim\n");
    fgets(jogar,4,stdin);
    resposta = strcmp(jogar,"sim");
    return resposta;
}

void passa_escolhas(int tam,int escolhas_pc[tam],int geral[tam])
{
    for(int i=0;i<4;i++){
        geral[i] = escolhas_pc[i];
    }
}

int main(void) //21 linhas
{
    int rodadas = 1, escolhas_pc[4] = {},resposta = 0,historico[9][6] = {}, acertos = 0,geral[4] = {};
    char jogar[4];
    while(resposta==0){
        desenha_inicio();
        sorteia_cores_pc(4,escolhas_pc);
        passa_escolhas(4,escolhas_pc,geral);
        while(rodadas<=9){
            acertos = rodada(rodadas,escolhas_pc,historico);
            if(acertos == 4) break;
            rodadas++;
        }
        if(acertos !=4 && rodadas == 10){
            perdeu(geral);
        } 
        else if(acertos == 4){
            parabens(rodadas);
        }
        rodadas = 1;
        resposta = pegar_continuacao(jogar,resposta);
    }
}