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

int paper[7];
int ans;

int main(void) {
	int temp, temp2;

	for (int i = 1; i <= 6; i++) {
		scanf("%d", &paper[i]);
	}

	ans += paper[6];
	ans += paper[5];
	paper[1] -= paper[5] * 11;
	ans += paper[4];
	temp = paper[4] * 5;
	if (temp > paper[2]) {
		temp -= paper[2];
		paper[2] = 0;
		paper[1] -= temp * 4;
	}
	else {
		paper[2] -= temp;
	}
	ans += paper[3] / 4;
	paper[3] %= 4;
	paper[3] = (4 - paper[3]) % 4;
	if (paper[3] != 0) {
		ans++;
		temp = paper[3] * 2 - 1;
		paper[1] -= paper[3] + 4;
	}
	else {
		temp = 0;
	}
	if (temp > paper[2]) {
		temp -= paper[2];
		paper[2] = 0;
		paper[1] -= temp * 4;
	}
	else {
		paper[2] -= temp;
	}

	ans += paper[2] / 9;
	paper[2] %= 9;
	if (paper[2] != 0) {
		ans++;
		paper[1] -= (9 - paper[2]) * 4;
	}

	if (paper[1] > 0) {
		ans += ((paper[1] + 24) / 25);
	}

	printf("%d", ans);
}