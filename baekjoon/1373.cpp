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

int len;
int fir;
char num[1000010];

void print(int st, int cou);

int main(void) {
	gets(num);
	len = strlen(num);
	fir = len % 3;
	if (fir == 0) {
		fir = 3;
	}
	print(0, fir);
}

void print(int st, int cou) {
	if (st == len) {
		return;
	}
	int val = 1;
	int ans = 0;
	for (int i = 1; i < cou; i++) {
		val *= 2;
	}
	for (int i = 0; i < cou; i++) {
		ans += val * (num[st + i] - '0');
		val /= 2;
	}
	
	printf("%d", ans);
	print(st + cou, 3);
}