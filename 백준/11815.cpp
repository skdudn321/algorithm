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

int main(void) {
	int N;
	long long int temp;
	double ttemp;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &temp);
		ttemp = sqrt((double)temp);
		if (temp == (long long int)ttemp * (long long int)ttemp) {
			printf("1 ");
		}
		else {
			printf("0 ");
		}
	}
}