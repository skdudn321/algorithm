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

int table[1001];
int ans;

int main(void) {

	freopen("test.txt", "r", stdin);
	for (int i = 1; i <= 1000; i++) {
		scanf("%1d", &table[i]);
	}
	for (int i = 1; i <= 996; i++) {
		int temp = 1;
		for (int j = 0; j <= 4; j++) {
			temp *= table[i + j];
		}
		ans = max(temp, ans);
	}
	printf("%d", ans);
}