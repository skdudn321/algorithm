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

int main(void) {
	freopen("out.txt", "w", stdout);

	table[1000] = 1;

	for (int i = 1; i <= 1000; i++) {
		int up = 0;
		for(int j = 1000; j >= 1; j--){
			table[j] *= 2;
			table[j] += up;
			up = table[j] / 10;
			table[j] %= 10;
		}
	}

	int ans = 0;
	for (int i = 1; i <= 1000; i++) {
		ans += table[i];
	}
	printf("%d", ans);
}