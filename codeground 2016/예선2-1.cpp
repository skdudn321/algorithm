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

typedef pair<int, int> dot;
typedef pair<dot, dot> rec;
typedef pair<long long int, rec> ii;

vector<ii> ve;
int dp[5001];

int main(int argc, char** argv) {
	freopen("test.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		for (int i = 0; i <= 5000; i++) {
			dp[i] = 1;
		}
		ve.clear();
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);
		for (int i = 1; i <= K; i++) {
			int x1, x2, y1, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			long long int temp = (long long int)(x2 - x1) * (y2 - y1);
			ve.push_back(ii(temp, rec(dot(x1, y1), dot(x2, y2))));
		}
		sort(ve.begin(), ve.end());

		for (int i = K - 2; i >= 0; i--) {
			for (int j = i + 1; j < K; j++) {
				if (ve[i].second.first.first >= ve[j].second.first.first && ve[i].second.second.first <= ve[j].second.second.first) {
					if (ve[i].second.first.second >= ve[j].second.first.second && ve[i].second.second.second <= ve[j].second.second.second) {
						dp[i] = max(dp[i], dp[j] + 1);
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < K; i++) {
			ans = max(dp[i], ans);
		}

		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}

	return 0;
}