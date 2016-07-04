#include<stdio.h>

int sosu[10010];

void makesosu(void);

int main(void){
	int N;
	int temp;
	int sum = 0;

	scanf("%d", &N);

	makesosu();

	for (int i = 1; i <= N; i++){
		scanf("%d", &temp);
		if (sosu[temp] == 1){
			sum++;
		}
	}

	printf("%d", sum);
}

void makesosu(){
	int i, j;

	for (i = 2; i <= 1000; i++){
		if (sosu[i] == 0){
			sosu[i] = 1;
			for (j = 2; i * j <= 1000; j++){
				sosu[i * j] = -1;
			}
		}
	}
}