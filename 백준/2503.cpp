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

int ans;
int N;
int table[5][101];

bool check(int num1, int num2, int num3);

int main(void) {

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%1d %1d %1d %d %d", &table[0][i], &table[1][i], &table[2][i], &table[3][i], &table[4][i]);
	}

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i == j) {
				continue;
			}
			for (int k = 1; k <= 9; k++) {
				if (i == k || j == k) {
					continue;
				}
				if (check(i, j, k)) {
					ans++;
				}
			}
		}
	}

	printf("%d", ans);
}

bool check(int num1, int num2, int num3) {
	for (int i = 1; i <= N; i++) {
		int strike = 0, ball = 0;
		for (int j = 0; j < 3; j++) {
			if (table[j][i] == num1) {
				if (j == 0) {
					strike++;
				}
				else {
					ball++;
				}
			}
			if (table[j][i] == num2) {
				if (j == 1) {
					strike++;
				}
				else {
					ball++;
				}
			}
			if (table[j][i] == num3) {
				if (j == 2) {
					strike++;
				}
				else {
					ball++;
				}
			}
		}
		if (strike != table[3][i] || ball != table[4][i]) {
			return false;
		}
	}

	return true;
}