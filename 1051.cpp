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

int square[51][51];

int main(void) {
	int N, M;
	int ans = 1;

	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &square[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int k = 1;
			while (k + i <= N && k + j <= M) {
				if (square[i][j] == square[i][j + k] && square[i + k][j] == square[i + k][j + k] && square[i][j] == square[i + k][j + k]) {
					ans = max(ans, (k + 1)*(k + 1));
				}
				k++;
			}
		}
	}

	printf("%d", ans);
}