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

int table[11][11];
int check[11];
int N, M;

void recursion(int ind);

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		ans = 0;
		for (int j = 1; j <= 10; j++) {
			for (int k = 1; k <= 10; k++) {
				table[j][k] = 0;
			}
			check[j] = 0;
		}
		scanf("%d %d", &N, &M);
		if (N % 2 == 1) {
			printf("0\n");
			continue;
		}
		for (int j = 1; j <= M; j++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			table[t1 + 1][t2 + 1] = 1;
			table[t2 + 1][t1 + 1] = 1;
		}
		recursion(N);
		printf("%d\n", ans);
	}
}

void recursion(int ind) {
	if (ind == 0) {
		ans++;
		return;
	}
	int i;
	for (i = 1; i <= N; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			break;
		}
	}
	for (int j = i + 1; j <= N; j++) {
		if (check[j] == 0 && table[i][j] == 1) {
			check[j] = 1;
			recursion(ind - 2);
			check[j] = 0;
		}
	}
	check[i] = 0;
}