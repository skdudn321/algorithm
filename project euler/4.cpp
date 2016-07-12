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
bool check(int N);
char bae[10];

int main(void) {
	int ans = 0;
	for (int i = 100; i <= 999; i++) {
		for (int j = 100; j <= 999; j++) {
			if (check(i * j)) {
				ans = max(i * j, ans);
			}
		}
	}
	printf("%d", ans);
}

bool check(int N) {
	sprintf(bae, "%d", N);
	int len = strlen(bae);
	bool check = true;
	for (int i = 0; i < len / 2; i++) {
		if (bae[i] != bae[len - i - 1]) {
			check = false;
			break;
		}
	}
	return check;
}