#include<stdio.h>

int main(void){
	int N, temp;

	scanf("%d", &N);

	while (true){
		scanf("%d", &temp);
		if (temp == 0){
			break;
		}

		if (temp % N == 0){
			printf("%d is a multiple of %d.\n", temp, N);
		}
		else{
			printf("%d is NOT a multiple of %d.\n", temp, N);
		}
	}
}