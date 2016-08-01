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

long long int ans;
char * str[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
long long int num[10] = {0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9};
long long int mul[10] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
char temp[100];

int main(void) {
	gets(temp);
	for (int i = 0; i <= 9; i++) {
		if (strcmp(temp, str[i]) == 0) {
			ans += num[i] * 10;
		}
	}
	gets(temp);
	for (int i = 0; i <= 9; i++) {
		if (strcmp(temp, str[i]) == 0) {
			ans += num[i];
		}
	}
	gets(temp);
	for (int i = 0; i <= 9; i++) {
		if (strcmp(temp, str[i]) == 0) {
			ans *= mul[i];
		}
	}
	printf("%lld", ans);
}