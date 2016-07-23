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
bool table[1000000];
vector<int> ve;
bool check(int x, int y);

int main(void) {
	for (int i = 1; i < 10000; i++) {
		for (int j = 1; j < 10000; j++) {
			if (check(i, j) && table[i * j] == false) {
				ve.push_back(i * j);
				table[i * j] = true;
			}
		}
	}
	for(int i = 0; i < ve.size(); i++){
		ans += ve[i];
	}
	printf("%d", ans);
}

bool check(int x, int y) {
	bool check[10];
	for (int i = 1; i <= 9; i++) {
		check[i] = false;
	}
	int mul = x * y;
	int cou = 0;

	while (x != 0) {
		if (check[x % 10]) {
			return false;
		}
		check[x % 10] = true;
		cou++;
		x /= 10;
	}
	while (y != 0) {
		if (check[y % 10]) {
			return false;
		}
		check[y % 10] = true;
		cou++;
		y /= 10;
	}
	while (mul != 0) {
		if (check[mul % 10]) {
			return false;
		}
		check[mul % 10] = true;
		cou++;
		mul /= 10;
	}
	if (cou == 9) {
		return true;
	}
	else {
		return false;
	}
}