#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int main(void) {
	int w, h;
	int x, y;
	int t;

	scanf("%d %d", &w, &h);
	scanf("%d %d", &x, &y);
	scanf("%d", &t);

	x += t; y += t;
	x %= (w * 2);
	y %= (h * 2);
	if (x > w) {
		x = 2 * w - x;
	}
	if (y > h) {
		y = 2 * h - y;
	}

	printf("%d %d", x, y);
}