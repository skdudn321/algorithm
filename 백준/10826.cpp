#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

char pibo[3][10002];
int ind = 10000;

void recursion(int N);

int main(void){
	int N;

	scanf("%d", &N);

	for (int i = 0; i <= 10000; i++){
		pibo[0][i] = '0';
		pibo[1][i] = '0';
		pibo[2][i] = '0';
	}
	pibo[0][10001] = 0;
	pibo[1][10001] = 0;
	pibo[2][10001] = 0;
	pibo[1][10000] = '1';
	pibo[2][10000] = '1';

	if (N == 0){
		printf("0");
	}
	else if (N == 1){
		printf("1");
	}
	else{
		recursion(N - 2);
		printf("%s", &pibo[2][ind]);
	}
}

void recursion(int N){
	if (N == 0){
		return;
	}
	for (int i = 1; i <= N; i++){
		strcpy(pibo[0], pibo[1]);
		strcpy(pibo[1], pibo[2]);
		int sum = 0;
		for (int j = 10000; j >= 0; j--){
			pibo[2][j] = pibo[1][j] + pibo[0][j] + sum - '0';
			sum = 0;
			if (pibo[2][j] > '9'){
				pibo[2][j] -= 10;
				sum = 1;
			}
		}
	}
	
	for (int i = 0; i <= 10000; i++){
		if (pibo[2][i] != '0'){
			ind = i;
			break;
		}
	}
}