#include<stdio.h>

int odd_pa[2010];
int jja_pa[2010];
int num[2010];

int main(void){
	int N, K;
	int i, j;
	int temp1, temp2;
	int S, E;

	scanf("%d", &N);

	for (i = 1; i <= N; i++){
		scanf("%d", &num[i]);
	}

	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			if (i - j < 1 || i + j > N){
				break;
			}
			if (num[i - j] == num[i + j]){
				odd_pa[i]++;
			}
			else{
				break;
			}
		}
	}

	for (i = 1; i < N; i++){
		for (j = 0; j <= N; j++){
			if (i - j < 1 || i + 1 + j > N){
				break;
			}
			if (num[i - j] == num[i + 1 + j]){
				jja_pa[i]++;
			}
			else{
				break;
			}
		}
	}

	scanf("%d", &K);
	for (i = 1; i <= K; i++){
		scanf("%d %d", &S, &E);
		if (S > E){
			temp1 = E;
			E = S;
			S = temp1;
		}

		if ((E + S) % 2 == 0){
			if (odd_pa[(E + S) / 2] + ((E + S) / 2) >= E){
				printf("1");
			}
			else{
				printf("0");
			}
		}
		else{
			if (jja_pa[(E + S) / 2] + ((E + S) / 2) >= E){
				printf("1");
			}
			else{
				printf("0");
			}
		}

		if (i != K){
			printf("\n");
		}
	}
}