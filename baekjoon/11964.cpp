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

bool full[5000001];

int main(void) {
	int T, A, B;

	scanf("%d %d %d", &T, &A, &B);

	full[0] = 1;
	for (int i = 0; i < T; i++) {
		if (full[i]) {
			if (i + A <= T) {
				full[i + A] = true;
			}
			if (i + B <= T) {
				full[i + B] = true;
			}
			full[i / 2] = true;
		}
	}
	for (int i = 0; i < T; i++) {
		if (full[i]) {
			if (i + A <= T) {
				full[i + A] = true;
			}
			if (i + B <= T) {
				full[i + B] = true;
			}
		}
	}
	for (int i = T; i >= 0; i--) {
		if (full[i]) {
			printf("%d", i);
			return 0;
		}
	}
}