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

int main(void) {
	char temp;
	while ((temp = getchar()) != EOF) {
		if (temp <= 'Z' && temp >= 'A') {
			printf("%c", temp - 'A' + 'a');
		}
		if (temp <= 'z' && temp >= 'a') {
			printf("%c", temp - 'a' + 'A');
		}
	}
}