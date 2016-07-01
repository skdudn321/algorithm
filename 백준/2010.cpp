#include<stdio.h>

int main(void){
	int N;
	int sum = 1;
	int temp;

	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d", &temp);
		sum += temp - 1;
	}
    printf("%d", sum);
}