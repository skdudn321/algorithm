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

int ans;
int table[10];
char temp;

int main(void) {
	freopen("test.txt", "r", stdin);
	while ((temp = getchar()) != EOF) {
		if (temp <= '9' && temp >= '0') {
			table[temp - '0']++;
			ans += (temp - '0');
		}
	}

	if (table[0] == 0 || ans % 3 != 0) {
		printf("-1");
	}
	else {
		for (int i = 9; i >= 0; i--) {
			for (int j = 1; j <= table[i]; j++) {
				printf("%d", i);
			}
		}
	}
}