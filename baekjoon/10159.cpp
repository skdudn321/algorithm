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

bool check[101][101];
vector<int> ve[101];
void recursion(int x, int y);

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		check[i][i] = 1;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		ve[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		recursion(i, i);
	}

	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= N; j++) {
			temp += check[i][j];
		}
		printf("%d\n", N - temp);
	}
}

void recursion(int x, int y) {
	check[y][x] = 1;
	check[x][y] = 1;

	if (ve[x].empty()) {
		return;
	}

	for (int i = 0; i < ve[x].size(); i++) {
		if (!check[y][ve[x][i]]) {
			recursion(ve[x][i], y);
		}
	}
}