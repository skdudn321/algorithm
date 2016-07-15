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

int table[102][51];
stack<int> st;

int main(void) {
	freopen("test.txt", "r", stdin);
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 50; j++) {
			scanf("%1d", &table[i][j]);
		}
	}

	for (int i = 50; i > 1; i--) {
		int temp = 0;
		for (int j = 0; j <= 100; j++) {
			temp += table[j][i];
		}
		int num = temp % 10;
		st.push(num);
		table[0][i - 1] = temp / 10;
	}
	int temp = 0;
	for (int i = 0; i <= 100; i++) {
		temp += table[i][1];
	}
	while (temp != 0) {
		st.push(temp % 10);
		temp /= 10;
	}

	for (int i = 1; i <= 10; i++) {
		printf("%d", st.top());
		st.pop();
	}
}