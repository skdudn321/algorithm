#include<stdio.h>

int coin[11];

int main(void) {
	int N, K;
	int num = 0;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &coin[i]);
	}

	for (int i = N; i >= 1; i--) {
		num += (K / coin[i]);
		K -= (coin[i] * (K / coin[i]));
	}

	printf("%d", num);
}