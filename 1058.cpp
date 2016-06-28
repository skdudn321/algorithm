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

int table[51][51];
int check[51][51];
int ans;

queue<int> qu;

int main(void) {
	int N;
	char temp;
	int high;

	scanf("%d\n", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			temp = getchar();
			if (temp == 'Y') {
				table[i][j] = 1;
			}
		}
		getchar();
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (table[i][j] && i != j) {
				check[i][j] = 1;
				qu.push(j);
			}
		}
		while (!qu.empty()) {
			for (int j = 1; j <= N; j++) {
				if (table[qu.front()][j] && j != i) {
					check[i][j] = 1;
				}
			}
			qu.pop();
		}
		high = 0;
		for (int j = 1; j <= N; j++) {
			if (check[i][j]) {
				high++;
			}
		}
		ans = max(ans, high);
	}

	printf("%d", ans);
}