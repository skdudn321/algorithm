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

#define can 1
#define cant 0
#define cant_temp -1

int check[21][21];
bool line[21];
int ans;
int N;

void recursion(int ind, int num);

int main(void) {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &check[i][j]);
		}
	}
	for (int i = 1; i <= 2 * N; i++) {
		line[i] = true;
	}

	recursion(2, 0);

	printf("%d", ans);
}

void recursion(int ind, int num) {
	int flag = true;
	if (ind == 2 * N + 1) {
		ans = max(ans, num);
		return;
	}

	if (ind <= N + 1) {
		for (int i = 1; i < ind; i++) {
			if (line[ind - i - i + N] && check[i][ind - i] == can) {
				line[ind - i - i + N] = false;
				flag = false;
				recursion(ind + 1, num + 1);
				line[ind - i - i + N] = true;
			}
		}
	}
	else {
		for (int i = ind - N; i <= N; i++) {
			if (line[ind - i - i + N] && check[i][ind - i] == can) {
				line[ind - i - i + N] = false;
				flag = false;
				recursion(ind + 1, num + 1);
				line[ind - i - i + N] = true;
			}
		}
	}

	if (flag) {
		recursion(ind + 1, num);
	}
}