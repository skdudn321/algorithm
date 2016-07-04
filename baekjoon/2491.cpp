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

#define upper 1
#define lower -1

int ans = 1;
int state;
int check = 1;
int num;
int same;

int main(void) {
	int N;

	scanf("%d %d", &N, &num);
	for (int i = 1; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp > num) {
			if (state == lower) {
				if (check + same > ans) {
					ans = check + same;
				}
				state = upper;
				check = same + 2;
				same = 0;
			}
			else {
				check++;
				check += same;
				same = 0;
				state = upper;
			}
		}
		else if (temp < num) {
			if (state == upper) {
				if (check + same > ans) {
					ans = check + same;
				}
				state = lower;
				check = same + 2;
				same = 0;
			}
			else {
				check++;
				check += same;
				same = 0;
				state = lower;
			}
		}
		else {
			same++;
		}
		num = temp;

		if (i == N - 1) {
			if (check + same > ans) {
				ans = check + same;
			}
		}
	}

	printf("%d", ans);
}