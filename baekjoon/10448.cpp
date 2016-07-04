#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int sam[45];
int dp[3000];

int main(void){
	int T, N = 0;

	for (int i = 1; i <= 44; i++){
		N += i;
		sam[i] = N;
	}

	for (int i = 1; i <= 44; i++){
		for (int j = 1; j <= 44; j++){
			for (int k = 1; k <= 44; k++){
				dp[sam[i] + sam[j] + sam[k]] = 1;
			}
		}
	}

	scanf("%d", &T);

	for (int i = 0; i < T; i++){
		scanf("%d", &N);
		if (dp[N] == 1){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
	}
}