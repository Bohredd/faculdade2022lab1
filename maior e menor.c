#include<stdio.h>
int main()
{
    int n1,n2;
    printf("Digite um numero:\n");
    scanf("%d",&n1);
    printf("Digite outro numero:\n");
    scanf("%d",&n2);
    if (n1 > n2)
    {
        printf("O Maior numero eh: %d",n1);
    } else if (n2 > n1) {
        printf("O Maior numero eh: %d",n2);
    } else {
        printf("Nao existe maior numero! Ambos sao iguais!");
    }
    return 0;
}
