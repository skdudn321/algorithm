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

#define first 1983

typedef unsigned int ui;
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ull ans;
queue<int> qu;

int main(void) {
	int T;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		ui cur = first;
		ull hap = first;
		while (!qu.empty()) {
			qu.pop();
		}
		int num, cou;
		ans = 0;
		scanf("%d %d", &num, &cou);
		qu.push(cur);
		if (hap == num) {
			ans++;
		}
		for (int i = 2; i <= cou; i++) {
			while (hap >= num) {
				hap -= qu.front();
				qu.pop();
				if (hap == num) {
					ans++;
				}
			}
			cur = cur * 214013 + 2531011;
			hap += (cur % 10000) + 1;
			qu.push((cur % 10000) + 1);
			if (hap == num) {
				ans++;
			}
		}
		printf("%lld\n", ans);
	}
}