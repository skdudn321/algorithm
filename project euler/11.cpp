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

int ans;
int table[21][21];

int main(void) {
	freopen("test.txt", "r", stdin);

	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			scanf("%d", &table[i][j]);
		}
	}

	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			int temp;
			if (i <= 17 && j <= 17) {
				temp = table[i][j] * table[i + 1][j] * table[i + 2][j] * table[i + 3][j];
				ans = max(temp, ans);
				temp = table[i][j] * table[i][j + 1] * table[i][j + 2] * table[i][j + 3];
				ans = max(temp, ans);
				temp = table[i][j] * table[i + 1][j + 1] * table[i + 2][j + 2] * table[i + 3][j + 3];
				ans = max(temp, ans);
			}
			else if (i <= 17) {
				temp = table[i][j] * table[i + 1][j] * table[i + 2][j] * table[i + 3][j];
				ans = max(temp, ans);
			}
			else if (j <= 17) {
				temp = table[i][j] * table[i][j + 1] * table[i][j + 2] * table[i][j + 3];
				ans = max(temp, ans);
			}
			if (i >= 4 && j <= 17) {
				temp = table[i][j] * table[i - 1][j + 1] * table[i - 2][j + 2] * table[i - 3][j + 3];
				ans = max(ans, temp);
			}
		}
	}
	printf("%d", ans);
}