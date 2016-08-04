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

char str[101];

int main(void) {
	gets(str);
	int length = (strlen(str) - 1) / 10;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%c", str[j + i * 10]);
		}
		printf("\n");
	}
	printf("%s", str + length * 10);
}