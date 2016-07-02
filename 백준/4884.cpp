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

int ans;
unsigned int make[70000];

int main(void) {
	long long int G, A, T, D;
	
	for (int i = 1; i < 70000; i++) {
		make[i] = make[i - 1] + i;
	}
	while (1) {
		scanf("%lld %lld %lld %lld", &G, &T, &A, &D);
		if (G == A && T == D && G == -1) {
			break;
		}
		long long int i = 1, x = 0, y = 0;
		long long int team = G * A + D;
		while (i < team) {
			i *= 2;
		}
		y = i - team;
		x += i - 1;
		x += make[T - 1] * G;
		printf("%lld*%lld/%lld+%lld=%lld+%lld\n", G, A, T, D, x, y);
	}
}