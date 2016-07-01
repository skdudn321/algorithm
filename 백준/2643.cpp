#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int, int> aa;
int N;
aa paper[100];
vector<int> ve;

int main(void) {
	int i;
	int a, b;
	
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		paper[i] = aa(max(a, b), min(a, b));
	}
	sort(paper, paper + N);
	ve.reserve(N + 1);
	for (int i = 0; i < N; i++) {
		vector<int>::iterator temp = upper_bound(ve.begin(), ve.end(), paper[i].second);
		if (temp == ve.end()) {
			ve.push_back(paper[i].second);
		}
		else {
			*temp = paper[i].second;
		}
	}

	printf("%d", ve.size());
}