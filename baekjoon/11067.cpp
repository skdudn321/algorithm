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

typedef pair<int, int> ii;

vector<int> table[100001];
bool check[100001];
ii ans[100001];

int main(void) {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		for (int i = 0; i <= 100000; i++) {
			table[i].clear();
			check[i] = false;
		}
		int N, ind = 1, cur_y = 0;
		scanf("%d", &N);
		for (int j = 1; j <= N; j++) {
			int x, y;
			scanf("%d %d", &x, &y);
			table[x].push_back(y);
			check[x] = true;
		}
		for (int j = 0; j <= 100000; j++) {
			if (check[j]) {
				sort(table[j].begin(), table[j].end());
				if (table[j].size() == 1) {
					ans[ind++] = ii(j, table[j][0]);
					cur_y = table[j][0];
				}
				else if (table[j].front() == cur_y) {
					for (int k = 0; k < table[j].size(); k++) {
						ans[ind++] = ii(j, table[j][k]);
						cur_y = table[j][k];
					}
				}
				else {
					for (int k = table[j].size() - 1; k >= 0; k--) {
						ans[ind++] = ii(j, table[j][k]);
						cur_y = table[j][k];
					}
				}
			}
		}
		scanf("%d", &N);
		for (int j = 1; j <= N; j++) {
			int temp;
			scanf("%d", &temp);
			printf("%d %d\n", ans[temp].first, ans[temp].second);
		}
	}
}