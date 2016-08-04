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

int ans;
lli first_up, first_down;
lli second_up, second_down;

lli gcd(lli first_num, lli second_num);

int main(void) {
	scanf("%lld %lld", &first_up, &first_down);
	scanf("%lld %lld", &second_up, &second_down);

	if (first_down < second_down) {
		lli temp = first_down;
		first_down = second_down;
		second_down = temp;
		temp = first_up;
		first_up = second_up;
		second_up = temp;
	}

	lli down = first_down * second_down / gcd(first_down, second_down);
	lli up = (first_up * down / first_down) + (second_up * down / second_down);

	if (up > down) {
		lli temp = gcd(up, down);
		up /= temp;
		down /= temp;
	}
	else {
		lli temp = gcd(down, up);
		up /= temp;
		down /= temp;
	}

	printf("%lld %lld", up, down);
}

lli gcd(lli first_num, lli second_num) {
	if (second_num == 0) {
		return first_num;
	}

	return gcd(second_num, first_num % second_num);
}