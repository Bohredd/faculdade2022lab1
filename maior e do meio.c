#include<stdio.h>
int main()
{
	int n1,n2,n3;
	printf("Digite um numero:\n");
	scanf("%d",&n1);
	printf("Digite um numero:\n");
	scanf("%d",&n2);
	printf("Digite um numero:\n");
	scanf("%d",&n3);
	if (n1>n2 && n1>n3) {
		printf("O maior eh n1, %d\n",n1);
		if (n2> n3) {
			printf("O numero do meio eh n2, %d\n",n2);
		}
		else {
			printf("O numero do meio eh n3, %d\n",n3);
		}
	} else if (n2>n1 && n2 > n3) {
		printf("O maior eh n2, %d\n",n2);
		if (n1> n3) {
			printf("O numero do meio eh n1, %d\n",n1);
		}
		else {
			printf("O numero do meio eh n3, %d\n",n3);
		}
	} else if (n3>n1 && n3>n2) {
		printf("O maior eh n3, %d\n",n3);
		if (n2> n1) {
			printf("O numero do meio eh n2, %d\n",n2);
		}
		else {
			printf("O numero do meio eh n3, %d\n",n1);
		}
	}
}
