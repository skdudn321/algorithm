#include<stdio.h>

int fast[101];
int fast2[101];

int main(void) {
	int N, M, temp1, temp2, start, ans = 0;
	scanf("%d %d", &N, &M);

	start = 1;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &temp1, &temp2);
		for (int j = start; j < temp1 + start; j++) {
			fast[j] = temp2;
		}
		start += temp1;
	}

	start = 1;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &temp1, &temp2);
		for (int j = start; j < temp1 + start; j++) {
			fast2[j] = temp2;
		}
		start += temp1;
	}

	for (int i = 1; i <= 100; i++) {
		ans = ans > fast2[i] - fast[i] ? ans : fast2[i] - fast[i];
	}

	printf("%d", ans);
}