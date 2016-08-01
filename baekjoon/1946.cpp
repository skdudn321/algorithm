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
int check;
int table[100001];

int main(void) {
	int T;
	scanf("%d", &T);
	
	for (int C = 1; C <= T; C++) {
		int N;
		scanf("%d", &N);
		ans = 0;
		check = 2000000;
		for (int i = 1; i <= N; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			table[t1] = t2;
		}
		for (int i = 1; i <= N; i++) {
			if (table[i] < check) {
				ans++;
				check = table[i];
			}
		}
		printf("%d\n", ans);
	}
}