#include<stdio.h>

int main(void){
	int N;
	int temp;
	int count = 0;

	scanf("%d", &N);

	for (int i = 0; i < 5; i++){
		scanf("%d", &temp);
		if (temp == N){
			count++;
		}
	}

	printf("%d", count);
}