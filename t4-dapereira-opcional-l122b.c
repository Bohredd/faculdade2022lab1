//Diogo Antonio Bohrer Pereira
//Matrícula: 202220628

#include<stdio.h>
#include<math.h>

void desenhar_rodape()
{
    printf("\u258F");
    for(int i=0;i<166;i++)
    {
        printf(" ");
    }
    printf("\u2595");
}

void verificar_igualdade(int qt_espacos,int quantia_meioblocos,int quantia_blocos)
{
    if(qt_espacos+quantia_blocos+quantia_meioblocos==69)
    {
        qt_espacos = qt_espacos+1;
    } else 
    {}
}

void cor_fundo(int vermelho, int verde, int azul)
{
    printf("\e[48;2;%d;%d;%dm", vermelho, verde, azul);
}

void desenhar_espacos(int qt_espacos)
{
    for(int i=0;i<qt_espacos;i++)
    {
        printf(" ");
    }
}

void descobrir_meiobloco_blococompleto(int tam,float qtx[tam],int recomeco,int lado,int qt_espacos)
{
    //lado 0 = esquerda
    //lado 1 = direita
    int quantia_blocos=0;
    int quantia_meioblocos=0;
    float aux;
    quantia_blocos = qtx[recomeco]/2;
    aux = fmod(qtx[recomeco],2);
    quantia_meioblocos = (aux*10)/5;
    aux = quantia_meioblocos;
    //meio 3 = +1 completo 1 meio
    //meio 2 = +1 completo 0 meio
    //meio 1 = +0 completo 1 meio
    //meio 0 = 0 completo 0 meio
    quantia_blocos *=2;
    if(quantia_meioblocos == 3)
    {
        quantia_blocos = quantia_blocos+1;
        quantia_meioblocos=1;
    } else if(quantia_meioblocos==2)
    {
        quantia_blocos = quantia_blocos+1;
        quantia_meioblocos=0;
    } else if(quantia_meioblocos ==1)
    {
        quantia_meioblocos=1;
    } else{}
    verificar_igualdade(qt_espacos,quantia_meioblocos,quantia_blocos);
    if(lado==0)
    {
        printf("\u2590");
        for(int i=0;i<quantia_blocos;i++)
        {
            printf("\u2588");
        }
    } else if(lado==1)
    {
        for(int i=0;i<quantia_blocos;i++)
        {
            printf("\u2588");
        }
        printf("\u258c");
    }
}

void cor_texto(int vermelho, int verde, int azul)
{
    printf("\e[38;2;%d;%d;%dm", vermelho, verde, azul);
}

void cor_normal(void)
{
    printf("\e[m");
}

void desenhar_piramide(int tam,float qtx_homem[tam],float qtx_mulher[tam])
{
    int qt_espacos;
    for(int j=20;j>=0;j--)
    {
        //pintura
        if(j>=0 && j<=3)
        {
            cor_texto(0,255,0);
        }
        if(j>=4 && j<=13)
        {
            cor_texto(0,0,255);
        } else if(j>=14 && j<=20){
            cor_texto(255,255,0);
        }
        qt_espacos = 70-qtx_homem[j];
        if(j==20 || j==9)
        {
            qt_espacos = qt_espacos-1;
        }
        printf("\u258F");
        desenhar_espacos(qt_espacos);
        descobrir_meiobloco_blococompleto(21,qtx_homem,j,0,qt_espacos);
        printf("\t\t%d\t\t",j*5);
        qt_espacos = 70-qtx_mulher[j];
        qt_espacos = qt_espacos+1;
        descobrir_meiobloco_blococompleto(21,qtx_mulher,j,1,qt_espacos);
        if(j==20)
        {
            qt_espacos = qt_espacos-1;
        } else if(j==2)
        {
            qt_espacos = qt_espacos -2;
        }
        desenhar_espacos(qt_espacos);
        printf("\u2595");
        printf("\n");
    }
    for(int i=0;i<168;i++)
    {
        printf("\u2581");
    }
    printf("\n");
}

void desenhar_cabecalho()
{
    cor_texto(255,255,0);
    for(int i=0;i<168;i++)
    {
        printf("\u2581");
    }
    printf("\n");
    printf("\u258F");
    for(int i=0;i<63;i++)
    {
        printf(" ");
    }
    printf("HOMENS  ");
    for(int i=0;i<6;i++)
    {
        printf(" ");
    }
    printf("IDADES  ");
    for(int i=0;i<10;i++)
    {
        printf(" ");
    }
    printf("MULHERES");
    for(int i=0;i<63;i++)
    {
        printf(" ");
    }
    printf("\u2595");
    printf("\n");
}

float quantia_x(float maiorindice,int tam,float ph[tam],float pf[tam])
{
    float qtx_homem[21],qtx_mulher[21];
    for(int i=0;i<21;i++)
    {
        qtx_homem[i] = ph[i]/maiorindice*70;
        qtx_mulher[i] = pf[i]/maiorindice*70;
    }
    desenhar_cabecalho();
    desenhar_piramide(21,qtx_homem,qtx_mulher);
}

float maior_indice(int tam,float ph[tam],float pf[tam])
{
    int maior;
    maior = ph[0];
    if(maior < pf[0])
    {
        maior = pf[0];
    }
    for(int i=0;i<21;i++)
    {
        if(ph[i] > maior)
        {
            maior = ph[i];
        } else if(pf[i] > maior)
        {
            maior = pf[i];
        }
    }
    return maior;
}

int main(void)
{
    float maiorindice;
    float ph[21] = { 200, 190, 180, 170, 160, 150, 140, 129, 120, 110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0 };
    float pf[21] = { 200, 190, 220, 170, 160, 150, 140, 129, 120, 40, 100, 90, 80, 70, 70, 50, 40, 30, 20, 10, 0 };
    maiorindice = maior_indice(21,ph,pf);
    quantia_x(maiorindice,21,ph,pf);
    return 0;
}