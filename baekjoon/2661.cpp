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
int num[100];
int N;
bool check = false;
void recursion(int ind);
bool good_check(int ind);

int main(void) {
	scanf("%d", &N);
	recursion(1);
	for (int i = 1; i <= N; i++) {
		printf("%d", num[i]);
	}
}

void recursion(int ind) {
	if (ind == N + 1) {
		check = true;
		return;
	}
	if (check) {
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (check) {
			return;
		}
		num[ind] = i;
		if (good_check(ind)) {
			recursion(ind + 1);
		}
	}
}

bool good_check(int ind) {
	int j = 1;
	for (int i = ind; i >= ind - (ind / 2) + 1; i--, j++) {
		int f_start = i - j, s_start = i;

		for (int k = 0; k < j; k++) {
			if (num[f_start + k] != num[s_start + k]) {
				break;
			}
			if (k == j - 1) {
				return false;
			}
		}
	}

	return true;
}