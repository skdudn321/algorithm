#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<functional>
#include<math.h>

#define mod 86400

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

using namespace std;

int ans;

int main(void) {
	int all_sec;
	int h, m, s;
	int tc;

	scanf("%d %d %d", &h, &m, &s);
	all_sec = s + m * 60 + h * 60 * 60;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i++) {
		int t1, t2;
		scanf("%d", &t1);
		if (t1 == 3) {
			s = all_sec % 60;
			h = all_sec / 3600;
			m = (all_sec / 60) % 60;
			printf("%d %d %d\n", h, m, s);
		}
		else {
			scanf("%d", &t2);
			if (t1 == 1) {
				all_sec = (all_sec + t2) % mod;
			}
			else {
				all_sec -= t2 % mod;
				if (all_sec < 0) {
					all_sec += mod;
				}
			}
		}
	}
}