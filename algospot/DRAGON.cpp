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

long long int table[51];
int n, p, l;
char temp[5][5] = { " -YF", " -FX", "", " +FX", " +YF" };
void recursion(int first, int second, int step, int K);

int main(void) {
	freopen("test.txt", "r", stdin);
	table[0] = 3;
	for (int i = 1; i <= 50; i++) {
		table[i] = table[i - 1] * 2;
	}

	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d %d %d", &n, &p, &l);
		if (n == 0) {
			for (int j = 1; j <= l; j++) {
				printf("%c", temp[3][p + j]);
			}
		}
		else {
			for (int j = 1; j <= l; j++) {
				recursion(1, 2, 1, p + j);
			}
		}
		printf("\n");
	}
}

void recursion(int first, int second, int step, int K) {
	if (step == n) {
		if (K <= 3) {
			printf("%c", temp[first + 2][K]);
		}
		else {
			K -= 3;
			printf("%c", temp[second + 2][K]);
		}
		return;
	}

	if (K <= table[n - step]) {
		if (first == 1) {
			recursion(1, 2, step + 1, K);
		}
		else {
			recursion(-1, 2, step + 1, K);
		}
	}
	else {
		if (second == 2) {
			recursion(1, -2, step + 1, K - table[n - step]);
		}
		else {
			recursion(-1, -2, step + 1, K - table[n - step]);
		}
	}
}