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
int ma;
int cou;
int ind;

int main(void) {

	while ((temp = getchar()) != EOF) {
		if (temp >= 'A' && temp <= 'Z') {
			ans[temp - 'A']++;
		}
		else {
			ans[temp - 'a']++;
		}
	}
	for (int i = 0; i <= 25; i++) {
		ma = max(ma, ans[i]);
	}
	for (int i = 0; i <= 25; i++) {
		if (ans[i] == ma) {
			cou++;
			ind = i;
		}
	}
	
	if (cou == 1) {
		printf("%c", ind + 'A');
	}
	else {
		printf("?");
	}
}