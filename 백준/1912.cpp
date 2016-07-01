#include<stdio.h>

int num[100001];

int main(void){
	int N;
	int max = -2000000000;
	int temp;
	int i, j, k;

	scanf("%d", &N);

	for (i = 1; i <= N; i++){
		scanf("%d", &temp);
		num[i] = temp > temp + num[i - 1] ? temp : temp + num[i - 1];
		if (num[i] > max){
			max = num[i];
		}
	}

	printf("%d", max);
	
}
