#include<stdio.h>

int card[150000];

int main(void) {
	int N, temp, check = 0, ans = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		card[temp] = 1;
	}

	for (int i = 1; i <= 2 * N; i++) {
		if (card[i] == 0) {
			if (check > 0) {
				check--;
				ans++;
			}
		}
		else {
			check++;
		}
	}

	printf("%d", ans);
}