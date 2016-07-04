#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int ans;
int recursion2();
int recursion3();
bool check = false;

int main(void) {
	char temp;
	while ((temp = getchar()) != EOF && temp != '\n') {
		if (temp == '(') {
			ans += recursion2();
		}
		else if (temp == '[') {
			ans += recursion3();
		}
		else {
			check = true;
		}
	}

	if (check) {
		printf("0");
	}
	else {
		printf("%d", ans);
	}
}

int recursion2() {
	char temp;
	int r_value = 0;

	while (temp = getchar()) {
		if (temp == '(') {
			r_value += recursion2();
		}
		else if (temp == '[') {
			r_value += recursion3();
		}
		else if (temp == ')') {
			if (r_value == 0) {
				r_value = 1;
			}
			return r_value * 2;
		}
		else {
			check = true;
			return 0;
		}
	}
}

int recursion3() {
	char temp;
	int r_value = 0;

	while (temp = getchar()) {
		if (temp == '(') {
			r_value += recursion2();
		}
		else if (temp == '[') {
			r_value += recursion3();
		}
		else if (temp == ']') {
			if (r_value == 0) {
				r_value = 1;
			}
			return r_value * 3;
		}
		else {
			check = true;
			return 0;
		}
	}
}