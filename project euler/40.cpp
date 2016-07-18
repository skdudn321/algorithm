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

char table[1000100];


int main(void) {
	int ind = 1;
	for (int i = 1; ind <= 1000000; i++) {
		sprintf(table + ind, "%d", i);
		while (table[ind] != 0) {
			ind++;
		}
	}
	printf("%d", (table[1] - '0') * (table[10] - '0') * (table[100] - '0') * (table[1000] - '0') * (table[10000] - '0') * (table[100000] - '0') * (table[1000000] - '0'));
}