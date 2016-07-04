#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

char alph[7][7];
char str[11];
int len;
bool check;
typedef pair<int, int> ii;

queue<ii> qu;

int xx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int yy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dp[7][7];

int main(void) {
	freopen("test.txt", "r", stdin);
	int T;
	int N;

	scanf("%d\n", &T);

	for (int i = 1; i <= T; i++) {
		for (int k = 1; k <= 5; k++) {
			for (int j = 1; j <= 5; j++) {
				scanf("%c", &alph[k][j]);
			}
			getchar();
		}

		scanf("%d\n", &N);
		
		for (int j = 1; j <= N; j++) {
			scanf("%s\n", str);
			printf("%s ", str);
			len = strlen(str);
			for (int k = 1; k <= 5; k++) {
				for (int x = 1; x <= 5; x++) {
					dp[k][x] = 0;
				}
			}
			check = false;
			for (int y = 0; y < len; y++) {
				for (int k = 1; k <= 5; k++) {
					for (int x = 1; x <= 5; x++) {
						if (str[y] == alph[k][x] && dp[k][x] == y) {
							qu.push(ii(k, x));
						}
					}
				}
				while (!qu.empty()) {
					int k = qu.front().first;
					int x = qu.front().second;
					qu.pop();
					for (int xxx = 0; xxx < 8; xxx++) {
						dp[k + xx[xxx]][x + yy[xxx]] = y + 1;
						if (y + 1 == len) {
							check = true;
						}
					}
				}
			}
			if (check) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
}