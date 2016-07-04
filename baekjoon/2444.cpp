#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int main(void){
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++){
		for (int j = i; j < N; j++){
			printf(" ");
		}
		for (int j = 1; j <= 2 * i - 1; j++){
			printf("*");
		}
		printf("\n");
	}
	for (int i = 2; i <= N; i++){
		for (int j = N - i; j < N - 1; j++){
			printf(" ");
		}
		for (int j = 1; j <= 2 * (N - i) + 1; j++){
			printf("*");
		}
		printf("\n");
	}
}