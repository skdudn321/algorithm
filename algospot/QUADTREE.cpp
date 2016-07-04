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
char str[1010];

void recursion(int st, int la);

int main(void) {
	int T, len;
	scanf("%d\n", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%s\n", str);
		len = strlen(str);
		recursion(0, len - 1);
		printf("%s\n", str);
	}
}

void recursion(int st, int la) {
	if (str[st] != 'x') {
		return;
	}
	else {
		int check[5];
		check[0] = st;
		check[4] = la;
		int cou = 1;
		int ind = 1;
		for (int i = 1; i <= la; i++) {
			if (str[st + i] == 'x') {
				cou += 3;
			}
			else {
				cou--;
			}

			if (cou == 0) {
				check[ind++] = i + st;
				cou = 1;
				if (ind == 4) {
					break;
				}
			}
		}
		for (int i = 0; i <= 3; i++) {
			recursion(check[i] + 1, check[i + 1]);
		}
		char temp_str[1001];
		strncpy(temp_str, str + check[2] + 1, check[4] - check[2]);
		temp_str[check[4] - check[2]] = 0;
		strncat(temp_str, str + check[0] + 1, check[2] - check[0]);
		strncpy(str + check[0] + 1, temp_str, check[4] - check[0]);
	}
}