#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<math.h>

using namespace std;

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;

int N;
int ma;
int table[10001];
bool search(int ind, int num);

int main(void) {
	int T;
	scanf("%d", &T);

	for (int C = 1; C <= T; C++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &table[i]);
		}
		ma = 0;
		for (int i = 1; i <= N; i++) {
			ma += table[i];
			if (search(i + 1, ma)) {
				printf("%d\n", ma);
				break;
			}
		}
	}
}

bool search(int ind, int num) {
	if (ind == N + 1) {
		return true;
	}

	int temp = 0;
	while (ind <= N && temp < num) {
		temp += table[ind++];
	}

	if (temp == num) {
		return search(ind, num);
	}
	return false;
}