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
char make_num[30];
int check[10];

int main(void) {
	for (int i = 1; i <= 9999; i++) {
		int j = 1;
		int ind = 1;
		while (1) {
			sprintf(make_num + ind, "%d", i * j);
			j++;
			while (make_num[ind] != 0) {
				ind++;
			}
			if (ind > 9) {
				break;
			}
		}
		if (ind == 10) {
			for (int i = 1; i <= 9; i++) {
				check[i] = 0;
			}
			for (int i = 1; i <= 9; i++) {
				if (check[make_num[i] - '0'] == 0) {
					check[make_num[i] - '0'] = 1;
				}
				else {
					break;
				}

				if (i == 9) {
					ans = max(ans, atoi(make_num + 1));
				}
			}
		}
	}
	printf("%d", ans);
}