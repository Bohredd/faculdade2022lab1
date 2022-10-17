#include<stdio.h>
int main()
{
    int chuva,vento,sol;
    printf("Bem vindo ao sistema do coletor solar!\nDigite os seguintes dados a seguir para que possamos realizar com seguranca nosso procedimento...\n");
    printf("-------------------------------\n");
    printf("Tabela padrao de niveis:\n[0]Nada\n[1]Fraca\n[2]Moderada\n[3]Forte\n");
    printf("-------------------------------\n");
    printf("Digite o nivel de chuva que esta no momento:\n");
    scanf("%d",&chuva);
    printf("Digite o nivel de vento do momento:\n");
    scanf("%d",&vento);
    printf("Digite o nivel de sol no momento:\n");
    scanf("%d",&sol);
    if(sol==3 && chuva==0 || chuva==1 || chuva == 2){
        printf("Pode funcionar sem problemas!\n");
    } else if (sol==2 && chuva==0 || chuva==1){
        printf("Pode funcionar sem problemas!\n");
    } else if (vento==2 || vento==3){
        printf("Nao pode funcionar!\n");
    } else if (chuva==3){
        printf("Nao pode funcionar!\n");
    } else {
        printf("Nao pode funcionar!\n");
    }
    return 0;
}
