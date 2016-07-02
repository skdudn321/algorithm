#include<stdio.h>

int main(void) {
	int N;
	int i;
	char temp;
	int sum = 0;
	
	scanf("%d\n", &N);

	for (i = 0; i < N; i++) {
		temp = getchar();
		sum += temp - '0';
	}

	printf("%d", sum);
}