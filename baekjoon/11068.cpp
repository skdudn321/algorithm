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
int table[30];

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		int N;
		int pcheck = false;
		scanf("%d", &N);
		for (int j = 2; j <= 64; j++) {
			int temp = N;
			int ind = 1;
			bool check = true;
			while (temp != 0) {
				table[ind++] = temp % j;
				temp = temp / j;
			}
			ind -= 1;
			for (int k = 1; k <= ind / 2; k++) {
				if (table[k] != table[ind - k + 1]) {
					check = false;
					break;
				}
			}
			if (check) {
				printf("1\n");
				pcheck = true;
				break;
			}
		}
		if (!pcheck) {
			printf("0\n");
		}
	}
}