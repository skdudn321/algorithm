#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int A[1010];
int B[1010];
int jadu[31][1010];

int main(void) {
	int T, W;
	int temp;
	int ans = 0;

	scanf("%d %d", &T, &W);
	
	for (int i = 1; i <= T; i++) {
		scanf("%d", &temp);
		if (temp == 1) {
			A[i] = 1;
		}
		else {
			B[i] = 1;
		}
	}

	for (int i = T; i >= 1; i--) {
		A[i] += A[i + 1];
		B[i] += B[i + 1];
	}

	for (int i = 0; i <= T; i++) {
		jadu[0][i] = A[1];
	}

	for (int i = 1; i <= W; i++) {
		for (int j = 0; j <= T; j++) {
			int high = 0;
			for (int k = 0; k <= j; k++) {
				high = max(high, jadu[i - 1][k]);
			}
			if (i % 2 == 0) {
				jadu[i][j] = high - B[j + 1] + A[j + 1];
			}
			else {
				jadu[i][j] = high - A[j + 1] + B[j + 1];
			}
		}
	}

	for (int i = 0; i <= T; i++) {
		ans = ans < jadu[W][i] ? jadu[W][i] : ans;
	}

	printf("%d", ans);
}