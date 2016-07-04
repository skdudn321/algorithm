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
long long int table[10010][20];

int main(void) {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		int N, M;
		long long int ans_min = 2000000000, ans_max = -2000000000;
		for (int j = 1; j <= 1000; j++) {
			table[j][0] = 0;
			table[j][1] = 0;
		}
		scanf("%d %d", &N, &M);
		for(int  j = 1; j <= M; j++){
			int t1, t2, t3, t4;
			scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
			table[t1][0] += t3;
			table[t2][1] += t3;
			table[t1][1] += t4;
			table[t2][0] += t4;
		}
		for (int j = 1; j <= N; j++) {
			long long int temp;
			if (table[j][0] == 0 && table[j][1] == 0) {
				temp = 0;
			}
			else {
				temp = (int)((table[j][0] * table[j][0] * 1000) / (table[j][0] * table[j][0] + table[j][1] * table[j][1]));
			}
			ans_min = min(temp, ans_min);
			ans_max = max(temp, ans_max);
		}
		printf("%lld\n%lld\n", ans_max, ans_min);
	}
}