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

int paper[101][101];
int ans;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				paper[i + a][j + b] = 1;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paper[i][j]) {
				ans++;
			}
		}
	}

	printf("%d", ans);
}