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

int table[30];
char alpa[10];
int ans;

int main(void) {
	int N;
	scanf("%d\n", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s\n", alpa);
		int len = strlen(alpa);
		int val = 1;
		for (int j = len - 1; j >= 0; j--, val *= 10) {
			table[alpa[j] - 'A'] += val;
		}
	}

	sort(table, table + 30, greater<int>());

	int ind = 9;
	for (int i = 0; i < 30; i++) {
		if (table[i] == 0) {
			break;
		}
		ans += table[i] * ind--;
	}

	printf("%d", ans);
}