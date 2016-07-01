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

typedef pair<int, int> ii;

int ans;
ii bingo[26];
int check[6][6];

bool test(void);

int main(void) {

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			int temp;
			scanf("%d", &temp);
			bingo[temp] = ii(i, j);
		}
	}

	for (int i = 1; i <= 10; i++) {
		int temp;
		scanf("%d", &temp);
		check[bingo[temp].first][bingo[temp].second] = true;
	}
	for (int i = 11; i <= 25; i++) {
		int temp;
		scanf("%d", &temp);
		check[bingo[temp].first][bingo[temp].second] = true;
		if (test()) {
			printf("%d", i);
			return 0;
		}
	}
}

bool test(void) {
	int count = 0;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (!check[i][j]) {
				break;
			}
			if (j == 5) {
				count++;
			}
		}
		for (int j = 1; j <= 5; j++) {
			if (!check[j][i]) {
				break;
			}
			if (j == 5) {
				count++;
			}
		}
	}
	for (int i = 1; i <= 5; i++) {
		if (!check[i][i]) {
			break;
		}
		if (i == 5) {
			count++;
		}
	}
	for (int i = 5; i >= 1; i--) {
		if (!check[i][6 - i]) {
			break;
		}
		if (i == 1) {
			count++;
		}
	}
	if (count >= 3) {
		return true;
	}
	else {
		return false;
	}
}