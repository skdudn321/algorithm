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

stack<int> st;

int main(void) {
	int N;
	char temp;
	int a;

	scanf("%d\n", &N);

	for (int i = 0; i < N; i++) {
		temp = getchar();
		if (temp == 'p') {
			temp = getchar();
			if (temp == 'u') {
				getchar();
				getchar();
				getchar();
				scanf("%d\n", &a);
				st.push(a);
			}
			else {
				getchar();
				getchar();
				if (st.empty()) {
					printf("-1\n");
				}
				else {
					printf("%d\n", st.top());
					st.pop();
				}
			}
		}
		else if (temp == 's') {
			getchar();
			getchar();
			getchar();
			getchar();
			printf("%d\n", st.size());
		}
		else if (temp == 'e') {
			getchar();
			getchar();
			getchar();
			getchar();
			getchar();
			if (st.empty()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else {
			getchar();
			getchar();
			getchar();
			if (st.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", st.top());
			}
		}
	}
}