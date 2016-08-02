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

long long int ans;
int N;
stack<ii> st;

int main(void) {
	while (1) {
		scanf("%d", &N);
		if (N == 0) {
			break;
		}
		ans = 0;
		st.push(ii(0, -1));

		int temp;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &temp);
			int ind = st.top().first;
			while (st.top().second >= temp) {
				int height = st.top().second;
				st.pop();
				ans = max(ans, (long long int)height * (ind - st.top().first));
			}
			st.push(ii(i, temp));
		}
		int ind = st.top().first;
		while (st.top().first != 0) {
			int height = st.top().second;
			st.pop();
			ans = max(ans, (long long int)height * (ind - st.top().first));
		}
		st.pop();
		printf("%lld\n", ans);
	}

	return 0;
}