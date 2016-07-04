#include<stdio.h>

int main(void){
	int N, T, K;
	int temp;
	int i, j;
	int sum = 0;

	scanf("%d", &T);

	for (i = 1; i <= T; i++){
		scanf("%d %d", &N, &K);
		sum = 0;
		for (j = 1; j <= N; j++){
			scanf("%d", &temp);
			sum += (temp / K);
		}
		printf("%d\n", sum);
	}
}
