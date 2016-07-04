#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int dp_table[31][20];
int ans = 0;

int main(void){
	int N;
	scanf("%d", &N);

	dp_table[2][0] = 3;
	for (int i = 1; i <= 14; i++){
		dp_table[i * 2 + 2][i] = 2;
	}

	for (int i = 4; i <= 30; i += 2){
		for (int j = 0; j < 20; j++){
			dp_table[i][0] += dp_table[i - 2][j];
		}
		dp_table[i][0] *= 3;
		for (int j = 1; j < (i / 2) - 1; j++){
			for (int k = 0; k < 20; k++){
				dp_table[i][j] += dp_table[i - (j + 1) * 2][k];
			}
			dp_table[i][j] *= 2;
		}
	}

	for (int i = 0; i < 20; i++){
		ans += dp_table[N][i];
	}

	printf("%d", ans);
}