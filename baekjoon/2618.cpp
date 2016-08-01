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

vector<ii> ve;
int ans;
int dp[1001][1001];
int N;
int W;

int recursion(int x, int y);
int move(ii start, ii end);
void print(int x, int y);

int main(void) {
	scanf("%d %d", &N, &W);

	for (int i = 1; i <= W; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		ve.push_back(ii(x, y));
	}
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i <= 1000; i++) {
		dp[i][W] = 0;
		dp[W][i] = 0;
	}
	recursion(0, 0);
	
	printf("%d\n", dp[0][0]);
	print(0, 0);
}

int recursion(int x, int y) {
	if (dp[x][y] != -1) {
		return dp[x][y];
	}

	if (x == 0 && y == 0) {
		dp[x][y] = min(recursion(x, max(x, y) + 1) + move(ii(N, N), ve[max(x, y)]), recursion(max(x, y) + 1, y) + move(ii(1, 1), ve[max(x, y)]));
	}
	else if (x == 0) {
		dp[x][y] = min(recursion(x, max(x, y) + 1) + move(ve[y - 1], ve[max(x, y)]), recursion(max(x, y) + 1, y) + move(ii(1, 1), ve[max(x, y)]));
	}
	else if (y == 0) {
		dp[x][y] = min(recursion(x, max(x, y) + 1) + move(ii(N, N), ve[max(x, y)]), recursion(max(x, y) + 1, y) + move(ve[x - 1], ve[max(x, y)]));
	}
	else {
		dp[x][y] = min(recursion(x, max(x, y) + 1) + move(ve[y - 1], ve[max(x, y)]), recursion(max(x, y) + 1, y) + move(ve[x - 1], ve[max(x, y)]));
	}

	return dp[x][y];
}

int move(ii start, ii end) {
	int x = start.first - end.first;
	int y = start.second - end.second;

	if (x < 0) {
		x = -x;
	}
	if (y < 0) {
		y = -y;
	}

	return x + y;
}

void print(int x, int y) {
	if (x >= W || y >= W) {
		return;
	}
	int next = max(x, y) + 1;
	int move_y;

	if (y == 0) {
		move_y = move(ii(N, N), ve[next - 1]);
	}
	else {
		move_y = move(ve[y - 1], ve[next - 1]);
	}

	if (dp[x][y] == dp[x][next] + move_y) {
		printf("2\n");
		print(x, next);
	}
	else {
		printf("1\n");
		print(next, y);
	}
}