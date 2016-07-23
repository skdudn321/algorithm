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


int main(void) {
	char temp;
	char ans[100];
	int ind = 0;
	while ((temp = getchar()) != EOF) {
		if (temp >= 'A' && temp <= 'Z') {
			ans[ind++] = temp;
		}
	}
	ans[ind] = 0;
	printf("%s", ans);
}