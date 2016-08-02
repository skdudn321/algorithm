#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<functional>
#include<math.h>

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

using namespace std;

typedef pair<int, int> ii;
map<int, int> m;

lli ans;
int N;

int main(void) {
	int T;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		scanf("%d", &N);
		ans = 0;
		m.clear();
		for (int i = 1; i <= N; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			map<int, int>::iterator temp_map = m.lower_bound(t1);
			if (temp_map == m.end() || temp_map->second <= t2) {
				m.insert(ii(t1, t2));
				temp_map = m.lower_bound(t1);
				while (temp_map != m.begin()) {
					temp_map--;
					if (temp_map->second >= t2) {
						break;
					}

					map<int, int>::iterator delete_map = temp_map++;
					m.erase(delete_map);
				}
			}

			ans += m.size();
		}
		printf("%lld\n", ans);
	}
}