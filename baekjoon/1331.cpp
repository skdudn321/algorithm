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
bool check[10][10];

bool can_go(ii start, ii dest);

int main(void) {
	char temp;
	int t1, t2;

	scanf("%c%d\n", &temp, &t2);
	t1 = temp - 'A' + 1;
	if (t1 < 1 || t1 > 6 || t2 < 1 || t2 > 6) {
		printf("Invalid");
		return 0;
	}
	ii start = ii(t1, t2);
	ii cur = ii(t1, t2);

	check[t1][t2] = true;
	
	for (int i = 2; i <= 36; i++) {
		scanf("%c%d\n", &temp, &t2);
		t1 = temp - 'A' + 1;
		if (t1 < 1 || t1 > 6 || t2 < 1 || t2 > 6) {
			printf("Invalid");
			break;
		}
		if (can_go(cur, ii(t1, t2)) && !check[t1][t2]) {
			cur = ii(t1, t2);
			check[t1][t2] = true;
		}
		else {
			printf("Invalid");
			break;
		}
		if (i == 36) {
			if (can_go(cur, start)) {
				printf("Valid");
			}
			else {
				printf("Invalid");
			}
		}
	}
}

bool can_go(ii start, ii dest) {
	int t1 = start.first - dest.first;
	int t2 = start.second - dest.second;
	if (t1 < 0) {
		t1 = -t1;
	}
	if (t2 < 0) {
		t2 = -t2;
	}

	if (t1 + t2 == 3 && (t1 == 1 || t1 == 2)) {
		return true;
	}
	return false;
}