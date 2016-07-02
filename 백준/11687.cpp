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

int ans;

int recursion(int N);

int main(void) {
	int N;

	scanf("%d", &N);

	printf("%d", recursion(N));
}

int recursion(int N) {
	int temp, temp2 = N;

	for (temp = 61035156; temp >= 5; temp = (temp - 1) / 5) {
		if (temp2 % temp == temp - 1) {
			return -1;
		}
		temp2 = temp2 - (temp2 / temp);
	}

	return temp2 * 5;
}