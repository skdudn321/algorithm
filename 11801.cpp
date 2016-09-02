#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<math.h>

using namespace std;

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;

lli ans;
int S, N;
vector<ii> ve;
vector<ii> sosu;
lli dp[5001];

int main(void) {
	freopen("test.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		scanf("%d %d", &N, &S);

		for (int i = 0; i <= N; i++) {
			dp[i] = 0;
		}
		ve.clear();
		sosu.clear();
		ans = 0;

		for (int i = 1; i <= N; i++) {
			if (N % i == 0) {
				sosu.push_back(ii(N / i, i));
			}
		}
		for (int i = 1; i <= S; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			ve.push_back(ii(t2, t1));
		}
		sort(ve.begin(), ve.end(), greater<ii>());
		dp[0] = 1;
		int ind = 0;
		for (int i = 0; i < sosu.size(); i++) {
			while (ind != ve.size() && ve[ind].first >= sosu[i].first) {
				for (int j = N; j >= ve[ind].second; j--) {
					dp[j] += dp[j - ve[ind].second];
				}
				ind++;
			}
			ans += dp[sosu[i].second];
		}
		printf("Case %d: %lld\n", C, ans);
	}
}