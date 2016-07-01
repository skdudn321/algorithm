#include<cstdio>
#include<algorithm>
#include<tuple>
using namespace std;
typedef tuple<int, char, int> ii;
int N, A, th, n;
ii s[200013];
int group[200000];

int main(void){
	scanf("%d", &N);

	for (int i = 0, a, b; i<N; i++) {
		scanf("%*d%d%d", &a, &b);
		s[n++] = ii(a, 2, i);
		s[n++] = ii(b, 0, i);
	}

	sort(s, s + n);

	for (int i = 0; i<n; i++) {
		th += get<1>(s[i]) - 1;
		A = max(A, th);
		if (get<1>(s[i]) == 2){
			group[get<2>(s[i])] = th;
		}
	}
	printf("%d\n", A);
	return 0;
}