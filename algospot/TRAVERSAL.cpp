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

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

using namespace std;

typedef pair<int, int> ii;

int N;
int table[2][101];
void recursion(ii first, ii mid);

int main(void) {
	int T;
	scanf("%d", &T);
	for(int C = 1; C <= T; C++){
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &table[0][i]);
		}
		for (int i = 1; i <= N; i++) {
			scanf("%d", &table[1][i]);
		}

		recursion(ii(1, N), ii(1, N));
	}
}

void recursion(ii first, ii mid) {
	if (first.first == first.second) {
		printf("%d ", table[0][first.first]);
		return;
	}
	int pivot;
	for (pivot = mid.first; pivot <= mid.second; pivot++) {
		if (table[0][first.first] == table[1][pivot]) {
			break;
		}
	}
	int left_size = pivot - mid.first;
	int right_size = mid.second - pivot;

	if (left_size) {
		recursion(ii(first.first + 1, first.first + left_size), ii(mid.first, pivot - 1));
	}
	if (right_size) {
		recursion(ii(first.second - right_size + 1, first.second), ii(pivot + 1, mid.second));
	}
	printf("%d ", table[0][first.first]);
}