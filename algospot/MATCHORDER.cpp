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

int ans;
int RU[101];
int KO[101];

int main(void) {
	freopen("test.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		int N;
		scanf("%d", &N);
		for (int j = 1; j <= N; j++) {
			scanf("%d", &RU[j]);
		}
		for (int j = 1; j <= N; j++) {
			scanf("%d", &KO[j]);
 		}
		ans = 0;
		sort(RU + 1, RU + N + 1, greater<int>());
		sort(KO + 1, KO + N + 1, greater<int>());
		int st = 1;
		for (int j = 1; j <= N; j++) {
			if (KO[st] >= RU[j]) {
				ans++;
				st++;
			}
		}
		printf("%d\n", ans);
	}
}