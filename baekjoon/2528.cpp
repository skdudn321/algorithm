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

int N, M;

int table[3001][2];
int vec[3001];
int lay = 1;
int ans;

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d %d", &temp, &vec[i]);
		if (vec[i] == 0) {
			table[i][0] = 0;
			table[i][1] = temp;
		}
		else {
			table[i][0] = M - temp;
			table[i][1] = M;
		}
	}

	while (lay < N) {
		if (table[lay][0] < table[lay + 1][0]) {
			if (table[lay][1] >= table[lay + 1][0]) {
				lay++;
				continue;
			}
		}
		else if (table[lay][0] > table[lay + 1][0]) {
			if (table[lay + 1][1] >= table[lay][0]) {
				lay++;
				continue;
			}
		}
		else {
			lay++;
			continue;
		}

		for (int i = lay; i <= N; i++) {
			if (vec[i] == 0) {
				table[i][0]++;
				table[i][1]++;
				if (table[i][1] == M) {
					vec[i] = 1;
				}
			}
			else {
				table[i][0]--;
				table[i][1]--;
				if (table[i][0] == 0) {
					vec[i] = 0;
				}
			}
		}

		ans++;
	}

	printf("%d", ans);
}