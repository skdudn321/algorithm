#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int main(void) {
	int T;
	int temp;
	int small = int_max, large = int_min;

	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		scanf("%d", &temp);
		if (temp > large) {
			large = temp;
		}
		if (temp < small) {
			small = temp;
		}
	}

	printf("%d", small * large);
}