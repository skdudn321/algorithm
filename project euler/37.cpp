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
bool sosu[1000100];

bool check(int N);

int main(void) {
	for (int i = 2; i <= 1000000; i++) {
		sosu[i] = true;
	}
	for (int i = 2; i <= 1000000; i++) {
		if (sosu[i]) {
			for (int j = 2; i * j <= 1000000; j++) {
				sosu[i * j] = false;
			}
		}
	}
	int cou = 0;
	for (int i = 10; i <= 1000000; i++) {
		if (sosu[i]) {
			if (check(i)) {
				cou++;
				printf("case %d : %d\n",cou, i);
				ans += i;
			}
		}
	}
	printf("%d", ans);
}

bool check(int N) {
	char num[10];
	bool flag = true;
	sprintf(num, "%d", N);

	for (int i = 0; num[i] != 0; i++) {
		if (!sosu[atoi(num + i)]) {
			flag = false;
			break;
		}
	}
	if (flag == false) {
		return flag;
	}
	while (N != 0) {
		if (!sosu[N]) {
			flag = false;
			break;
		}
		N /= 10;
	}
	return flag;
}