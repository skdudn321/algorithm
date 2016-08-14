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
int change[26];
char str[1010];

int main(void) {
	for (int i = 0; i <= 25; i++) {
		change[i] = (i + 13) % 26;
	}
	gets_s(str);
	int i = 0;
	while (str[i] != 0) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = change[str[i] - 'A'] + 'A';
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = change[str[i] - 'a'] + 'a';
		}

		printf("%c", str[i]);

		i++;
	}
}