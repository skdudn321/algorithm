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

int ans;
ii dosirak[10001];

int main(void) {
	int T;
	scanf("%d", &T);
	for (int j = 1; j <= T; j++) {
		int N;
		int hap = 0;
		ans = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			int temp;
			scanf("%d", &temp);
			dosirak[i].second = temp;
		}
		for (int i = 0; i < N; i++) {
			int temp;
			scanf("%d", &temp);
			dosirak[i].first = temp;
		}
		sort(dosirak, dosirak + N, greater<ii>());
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += dosirak[i].second;
			ans = max(sum + dosirak[i].first, ans);
		}
		printf("%d\n", ans);
	}
}