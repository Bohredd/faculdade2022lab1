//Diogo Antonio Bohrer Pereira
//Matrícula: 202220628


#include<stdio.h>

void desenhar_piramide(int tam,float qtx_homem[tam],float qtx_mulher[tam])
{
    float qt_espacos;
    for(int i=20;i>=0;i--)
    {
        qt_espacos = (35-qtx_homem[i])-1;
        for(int j=0;j<qt_espacos;j++)
        {
            printf(" ");
        }
        for(int j=0;j<qtx_homem[i];j++)
        {
            printf("x");
        }
        for(int j=0;j<4;j++)
        {
            printf(" ");
        }
        printf("%d",i*5);
        if(i==0 || i==1)
        {
            printf(" ");
        }
        for(int j=0;j<4;j++)
        {
            printf(" ");
        }
        qt_espacos = (35-qtx_mulher[i])-1;
        for(int j=0;j<qtx_mulher[i];j++)
        {
            printf("x");
        }
        for(int j=0;j<qt_espacos;j++)
        {
            printf(" ");
        }
        printf("\n");
    }
    for(int i=0;i<80;i++)
    {
        printf("-");
    }
    printf("\n");
}

void desenhar_cabecalho()
{
    for(int i=0;i<80;i++)
    {
        printf("-");
    }
    printf("\n");
    for(int i=0;i<29;i++)
    {
        printf(" ");
    }
    printf("HOMENS  ");
    printf("IDADES  ");
    printf("MULHERES");
    for(int i=0;i<27;i++)
    {
        printf(" ");
    }
    printf("\n");
}

float quantia_x(float maiorindice,int tam,float ph[tam],float pf[tam])
{
    float qtx_homem[21],qtx_mulher[21];
    for(int i=0;i<21;i++)
    {
        qtx_homem[i] = (ph[i]/maiorindice*35)-1;
        qtx_mulher[i] = (pf[i]/maiorindice*35)-1;
        //printf("Homem = %f\n",qtx_homem[i]);
        //printf("Mulher = %f\n",qtx_mulher[i]);
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
     //printf("maior = %.0f",maiorindice);
     quantia_x(maiorindice,21,ph,pf);
     return 0;
   }