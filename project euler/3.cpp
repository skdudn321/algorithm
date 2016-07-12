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

int main(void) {
	long long int N = 600851475143;

	long long i = 2;
	while (N != 1) {
		if (N % i == 0) {
			N /= i;
		}
		else {
			i++;
		}
	}
	printf("%lld", i);
}