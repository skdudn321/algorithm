#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<tuple>
#include<functional>

using namespace std;

typedef tuple<int, int, int> ii;
vector<ii> ve;
int map[502][502];
int N, M;
int dp[502][502];

int in_x[4] = { -1, 1, 0, 0 };
int in_y[4] = { 0, 0, -1, 1 };

void bfs(int x, int y);

int main(void){
	
	for (int i = 0; i < 502; i++){
		map[0][i] = 2000000000;
		map[501][i] = 2000000000;
		map[i][0] = 2000000000;
		map[i][501] = 2000000000;
	}

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			scanf("%d", &map[i][j]);
			ve.push_back(ii(map[i][j], i, j));
		}
	}

	dp[1][1] = 1;
	sort(ve.begin(), ve.end(), greater<ii>());
	for (int i = 0; i < (int)ve.size(); i++){
		for (int j = 0; j < 4; j++){
			if (map[get<1>(ve[i])][get<2>(ve[i])] > map[get<1>(ve[i]) + in_x[j]][get<2>(ve[i]) + in_y[j]]){
				dp[get<1>(ve[i]) + in_x[j]][get<2>(ve[i]) + in_y[j]] += dp[get<1>(ve[i])][get<2>(ve[i])];
			}
		}
	}

	printf("%d", dp[N][M]);
}