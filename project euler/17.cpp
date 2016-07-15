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
char table[10][10] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
char table2[10][10] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char table3[10][10] = { "twenty", "thirty" ,"forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main(void) {
	for (int i = 0; i <= 8; i++) {
		ans += (strlen(table[i]) * 9);
		ans += strlen(table2[i]);
	}

	ans += strlen(table2[9]);

	for (int i = 0; i <= 7; i++) {
		ans += (strlen(table3[i]) * 10);
	}

	ans *= 10;
	for (int i = 0; i <= 8; i++) {
		ans += (((strlen(table[i]) + 7) * 100) + (3 * 99));
	}

	printf("%d", ans + 11);
}