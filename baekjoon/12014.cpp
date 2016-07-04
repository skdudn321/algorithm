#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int ans;
int table[10001];
vector<int> ve;

int main(void) {
	int T;
	int N, M;
	int i, j, k;

	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		scanf("%d %d", &N, &M);
		for (int j = 1; j <= N; j++) {
			int tt;
			scanf("%d", &tt);
			vector<int>::iterator temp = lower_bound(ve.begin(), ve.end(), tt);
			if (temp == ve.end()) {
				ve.push_back(tt);
			}
			else {
				*temp = tt;
			}
		}

		if (M <= ve.size()) {
			ans = 1;
		}
		else {
			ans = 0;
		}

		printf("Case #%d\n%d\n", i, ans);

		ve.clear();
	}


}