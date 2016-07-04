#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<math.h>

using namespace std;

typedef pair<int, int> squ;

int N, M;
int ans;
vector<squ> yaksu;
int table[101][101];

int main(void){
	int a, b, temp;

	scanf("%d %d", &N, &M);
	temp = (int)sqrt((double)M);

	for (int i = 1; i <= temp; i++){
		if (M % i == 0){
			if (M / i <= N){
				yaksu.push_back(squ(i, M / i));
				yaksu.push_back(squ(M / i, i));
			}
		}
	}

	for (int i = 0; i < M; i++){
		scanf("%d %d", &a, &b);
		table[a][b] = 1;
	}

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			table[i][j] = table[i - 1][j] + table[i][j - 1] + table[i][j] - table[i - 1][j - 1];
		}
	}

	for (int i = 0; i < (int)yaksu.size(); i++){
		for (int j = yaksu[i].first; j <= N; j++){
			for (int k = yaksu[i].second; k <= N; k++){
				ans = max(ans, table[j][k] - table[j - yaksu[i].first][k] - table[j][k - yaksu[i].second] + table[j - yaksu[i].first][k - yaksu[i].second]);
			}
		}
	}

	printf("%d", M - ans);
}