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

int ans[26];
char temp;

int main(void) {
	for (int j = 0; j < 26; j++) {
		ans[j] = -1;
	}
	int i = 0;
	while ((temp = getchar()) != EOF) {
		if (ans[temp - 'a'] == -1) {
			ans[temp - 'a'] = i;
		}
		i++;
	}
	for (int j = 0; j < 26; j++) {
		printf("%d ", ans[j]);
	}
}