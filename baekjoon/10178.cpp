#include<stdio.h>

int main(void){
	int N;
	int temp1, temp2;
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		scanf("%d %d", &temp1, &temp2);
		printf("You get %d piece(s) and your dad gets %d piece(s).", temp1 / temp2, temp1%temp2);
		if (i != N - 1){
			printf("\n");
		}
	}
}