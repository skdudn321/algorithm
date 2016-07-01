#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int ans;
int want[10001];
int N;
int money;
int index1, index2, pivot;

bool check(void);

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &want[i]);
	}
	scanf("%d", &money);

	sort(want, want + N, greater<int>());

	index1 = 0;
	index2 = want[0];
	while (index1 < index2) {
		pivot = (index1 + index2 + 1) / 2;
		if (check()) {
			index1 = pivot;
		}
		else {
			index2 = pivot - 1;
		}
	}

	printf("%d", index1);
}

bool check(void) {
	int sum = 0;

	for (int i = 0; i < N; i++) {
		if (want[i] > pivot) {
			sum += pivot;
		}
		else {
			sum += want[i];
		}
	}

	if (sum > money) {
		return false;
	}
	else {
		return true;
	}
}