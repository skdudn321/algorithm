#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include<tuple>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

typedef tuple<int, int, int> ii;
int table[102][102][102];
int ans;
queue<ii> qu;

int xx[6] = { 1, -1, 0, 0, 0, 0 };
int yy[6] = { 0, 0, 1, -1, 0, 0 };
int zz[6] = { 0, 0, 0, 0, 1, -1 };

int main(void) {
	int N, M, H;


	for (int i = 0; i <= 101; i++) {
		for (int j = 0; j <= 101; j++) {
			for (int k = 0; k <= 101; k++) {
				table[i][j][k] = -1;
			}
		}
	}

	scanf("%d %d %d", &M, &N, &H);

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				int temp;
				scanf("%d", &temp);
				if (temp == 0) {
					table[i][j][k] = 1000000000;
				}
				else if (temp == 1) {
					table[i][j][k] = 0;
					qu.push(ii(i, j, k));
				}
				else {
					table[i][j][k] = temp;
				}
			}
		}
	}

	while (!qu.empty()) {
		for (int i = 0; i < 6; i++) {
			if (table[get<0>(qu.front()) + xx[i]][get<1>(qu.front()) + yy[i]][get<2>(qu.front()) + zz[i]] > table[get<0>(qu.front())][get<1>(qu.front())][get<2>(qu.front())] + 1) {
				table[get<0>(qu.front()) + xx[i]][get<1>(qu.front()) + yy[i]][get<2>(qu.front()) + zz[i]] = table[get<0>(qu.front())][get<1>(qu.front())][get<2>(qu.front())] + 1;
				qu.push(ii(get<0>(qu.front()) + xx[i], get<1>(qu.front()) + yy[i], get<2>(qu.front()) + zz[i]));
			}
		}
		qu.pop();
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				ans = max(ans, table[i][j][k]);
			}
		}
	}
	if (ans == 1000000000) {
		printf("-1");
		return 0;
	}
	printf("%d", ans);

}