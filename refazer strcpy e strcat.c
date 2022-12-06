#include<stdio.h>
#include<string.h>

int descobrir_tam(char v[])
{
    int c=0;
    while(v[c] != '\0')
    {
        c++;
    }
    return c;
}

void meustrcpy(char e[],char f[])
{
    int tamanho,p=0;
    int a=0;
    tamanho = descobrir_tam(f);
    //copia o segundo vetor para o primeiro vetor
    printf("o vetor c tem tamanho de %d\n",tamanho-1);
    while(p<tamanho)
    {
        e[p] = f[p];
        if(e[p] == '\0'){
            break;
        };
        p++;
    }
    printf("%s\n",e);
}

void meustrcat(char d[],char o[])
{
    // copia o vetor o para o final do vetor d
    int tamanho_vetorA = 0,tamanho_vetorB = 0;
    int p = 0, tamanho_vetorC = 0;
    tamanho_vetorA = descobrir_tam(o);
    tamanho_vetorB = descobrir_tam(d);
    tamanho_vetorC = tamanho_vetorA+tamanho_vetorB;
    tamanho_vetorC++;
    char vetor_resultante[tamanho_vetorC] = {};
    while(tamanho_vetorA>p)
    {
        vetor_resultante[p] = o[p];
        p++;
    }
    p = 0;
    vetor_resultante[tamanho_vetorA+1] = "\0";
    while(tamanho_vetorB>=p)
    {
        vetor_resultante[tamanho_vetorA+p+1] = d[p];
        p++;
        
    }
    for(int i=0;i<tamanho_vetorC;i++)
    {
        printf("%c",vetor_resultante[i]);
    }
}

int main(void)
{
  char a[10];
  char b[20] = "teste";
  char c[] = "abacate";
  printf("digite algo:\n");
  fgets(c,8,stdin);
  meustrcpy(a,c); //passa o vetor c para o vetor a 
  meustrcat(b,a); //passa o vetor a para o final do vetor b 
}