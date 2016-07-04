#include<cstdio>
#include<algorithm>
#include<tuple>
#include<stack>
using namespace std;
typedef tuple<int, char, int> ii;
int N, A, th, n;
ii s[200013];
int group[200000];
stack<int> st;

int main(void) {
	scanf("%d", &N);

	for (int i = 0, a, b, c; i<N; i++) {
		scanf("%d%d%d", &c, &a, &b);
		s[n++] = ii(a, 2, c);
		s[n++] = ii(b, 0, c);
	}

	for (int i = N; i >= 1; i--) {
		st.push(i);
	}

	sort(s, s + n);

	for (int i = 0; i<n; i++) {
		th += get<1>(s[i]) - 1;
		A = max(A, th);
		if (get<1>(s[i]) == 2) {
			group[get<2>(s[i])] = st.top();
			st.pop();
		}
		else {
			st.push(group[get<2>(s[i])]);
		}
	}
	printf("%d\n", A);
	for (int i = 1; i <= N; i++) {
		printf("%d\n", group[i]);
	}
	return 0;
}