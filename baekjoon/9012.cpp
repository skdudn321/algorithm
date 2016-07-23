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
char str[100];

int main(void) {
	int T;
	scanf("%d\n", &T);
	for (int i = 1; i <= T; i++) {
		gets(str);
		int j = 0;
		int cou = 0;
		while (str[j] != 0) {
			if (str[j] == '(') {
				cou++;
			}
			else {
				cou--;
				if (cou < 0) {
					break;
				}
			}
			j++;
		}
		if (cou == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}