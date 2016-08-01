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

char table[30];

int main(void) {
	scanf("%s", table);
	int len = strlen(table);
	sort(table, table + len, greater<char>());
	printf("%s", table);
}