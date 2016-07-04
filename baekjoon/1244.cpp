#include<stdio.h>

#define change(x) (((x)+1)%2)

int swi[110];

int main(void) {
	int N;
	int K;
	int i, j;
	int fr, ba;
	int temp1, temp2;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &swi[i]);
	}
	scanf("%d", &K);
	for (i = 0; i < K; i++) {
		scanf("%d %d", &temp1, &temp2);
		if (temp1 == 1) {
			for (j = 1; j <= N; j++) {
				if (j % temp2 == 0) {
					swi[j] = change(swi[j]);
				}
			}
		}
		else {
			fr = temp2 - 1;
			ba = temp2 + 1;
			swi[temp2] = change(swi[temp2]);
			while (swi[fr] == swi[ba] && fr > 0 && ba <= N) {
				swi[fr] = change(swi[fr]);
				swi[ba] = change(swi[ba]);
				fr--;
				ba++;
			}
		}
	}

	for (i = 1; i <= N; i++) {
		printf("%d", swi[i]);
		if (i == N) {

		}
		else if (i % 20 == 0) {
			printf("\n");
		}
		else {
			printf(" ");
		}
	}
}