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

int soinsu(long long int N);

int main(void) {
	long long int N = 1;
	long long int i = 2;
	while (1) {
		int temp = soinsu(N);
		if (temp >= 500) {
			break;
		}
		N += i++;
	}
	printf("%lld", N);
}

int soinsu(long long int N) {
	long long int num = (long long int)sqrt(N);
	int ret;
	if (num * num == N) {
		ret = 1;
	}
	else {
		ret = 0;
	}
	for (int i = 1; i < num; i++) {
		if (N % i == 0) {
			ret += 2;
		}
	}
	return ret;
}