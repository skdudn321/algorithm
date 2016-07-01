#include<stdio.h>
#include<stack>

using namespace std;

stack<int> st;
stack<int> st1;

int student[101];

int main(void) {
	int N, temp;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &temp);
		for (int j = 1; j <= temp; j++) {
			student[j] = st.top();
			st.pop();
		}
		st.push(i);
		for (int j = temp; j >= 1; j--) {
			st.push(student[j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		st1.push(st.top());
		st.pop();
	}
	for (int i = 1; i <= N; i++) {
		printf("%d ", st1.top());
		st1.pop();
	}
}