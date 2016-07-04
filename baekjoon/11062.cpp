#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

typedef pair<int, int> ii;
ii dp[1001][1001];
int card[1001];

int main(void){
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++){
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++){
			scanf("%d", &card[i]);
		}
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N - i + 1; j++){
				if (i % 2 == 0){
					if (dp[i - 1][j].second + card[j + i - 1] > dp[i - 1][j + 1].second + card[j]){
						dp[i][j] = ii(dp[i - 1][j].first, dp[i - 1][j].second + card[j + i - 1]);
					}
					else{
						dp[i][j] = ii(dp[i - 1][j + 1].first, dp[i - 1][j + 1].second + card[j]);
					}
				}
				else{
					if (dp[i - 1][j].first + card[j + i - 1] > dp[i - 1][j + 1].first + card[j]){
						dp[i][j] = ii(dp[i - 1][j].first + card[j + i - 1], dp[i-1][j].second);
					}
					else{
						dp[i][j] = ii(dp[i - 1][j + 1].first + card[j], dp[i - 1][j + 1].second);
					} 
				}
			}
		}
		if (N % 2 == 0){
			printf("%d\n", dp[N][1].second);
		}
		else{
			printf("%d\n", dp[N][1].first);
		}
	}
}