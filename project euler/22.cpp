#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<math.h>
#include<string>

using namespace std;

string name[10000];
int table[10000];

int main(void) {
	freopen("test.txt", "r", stdin);
	char temp;
	long long int ans = 0;
	int num = 0;
	int ind = 0;
	while ((temp = getchar()) != EOF) {
		if (temp == '"') {
			continue;
		}
		else if (temp == ',') {
			num++;
		}
		else {
			name[num].push_back(temp);
		}
	}

	sort(name, name + num + 1);

	for (int i = 0; i <= num; i++) {
		for (int j = 0; j < name[i].size(); j++) {
			table[i] += name[i][j] - 'A' + 1;
		}
		table[i] *= (i + 1);
		ans += table[i];
	}
	printf("%lld", ans);
}