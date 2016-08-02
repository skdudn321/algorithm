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

typedef unsigned int ui;
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int ans;
char str[10010];
stack<char> st;

int main(void) {
	int T;
	scanf("%d\n", &T);
	for (int i = 1; i <= T; i++) {
		gets(str);
		int len = strlen(str);
		ans = 1;
		while (!st.empty()) {
			st.pop();
		}
		for (int j = 0; j < len; j++) {
			if (str[j] == '(' || str[j] == '{' || str[j] == '[') {
				st.push(str[j]);
			}
			else if(str[j] == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else {
					ans = 0;
					break;
				}
			}
			else if (str[j] == '}') {
				if (!st.empty() && st.top() == '{') {
					st.pop();
				}
				else {
					ans = 0;
					break;
				}
			}
			else {
				if (!st.empty() && st.top() == '[') {
					st.pop();
				}
				else {
					ans = 0;
					break;
				}
			}
		}
		if (st.empty() && ans) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}