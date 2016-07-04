#include<stdio.h>

#define none 2

int paper[2200][2200];

int zero, one, minus;

int recursion(int left, int top, int right, int bottom){
	int cut = (bottom - top + 1)/3;
	int i, j;
	int check[4] = { 0, 0, 0, 0 };

	if (cut == 1){
		for (i = left; i <= right; i += cut){
			for (j = top; j <= bottom; j += cut){
				(*(check + 1 + paper[i][j]))++;
			}
		}

		if (check[0] == 9){
			return -1;
		}
		else if (check[1] == 9){
			return 0;
		}
		else if (check[2] == 9){
			return 1;
		}
		else{
			minus += check[0];
			zero += check[1];
			one += check[2];
			return none;
		}
	}
	else{
		for (i = left; i <= right; i += cut){
			for (j = top; j <= bottom; j += cut){
				(*(check + 1 + recursion(i, j, i + cut - 1, j + cut - 1)))++;
			}
		}

		if (check[0] == 9){
			return -1;
		}
		else if (check[1] == 9){
			return 0;
		}
		else if (check[2] == 9){
			return 1;
		}
		else{
			minus += check[0];
			zero += check[1];
			one += check[2];
			return none;
		}
	}
}

int main(void){
	int N;
	int i, j;

	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			scanf("%d", &paper[i][j]);
		}
	}

	recursion(1, 1, N, N);

	printf("%d\n%d\n%d\n", minus, zero, one);
}