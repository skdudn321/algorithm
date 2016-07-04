#include<stdio.h>

int live[2000000];

int main(void) {
	int a, b, d, N;
	int i;
	int sum;
	int result = 0;
	scanf("%d %d %d %d", &a, &b, &d, &N);

	live[0] = 1;
	sum = 0;
	for (i = a; i < b; i++) {
		sum = (sum + live[i - a]) % 1000;
		live[i] = sum;
	}
	for (i = b; i <= N; i++) {
		sum = (sum - live[i - b] +live[i - a] + 1000) % 1000;
		live[i] = sum;
	}
	if (N < d) {
		d = N + 1;
	}
	for (i = N - d + 1; i <= N; i++) {
		result = (result + live[i]) % 1000;
	}

	printf("%d\n", result);
	return 0;
}