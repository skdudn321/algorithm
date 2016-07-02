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
#include<tuple>

using namespace std;

typedef tuple<int, int, int, int> iii;

vector<iii> ve;
queue<int> qu;
int check[600000];
int open[600000];

int ans;

int main(void) {

	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		if (t1 > t2) {
			ve.push_back(iii(t1, 0 - t2 - N, 0, i));
			ve.push_back(iii(t2 + N, 0 - t1, 1, i));
			ve.push_back(iii(t1 - N, 0 - t2, 0, i));
			ve.push_back(iii(t2, 0 - t1 + N, 1, i));
		}
		else {
			ve.push_back(iii(t1, 0 - t2, 0, i));
			ve.push_back(iii(t2, 0 - t1, 1, i));
		}
	}
	
	sort(ve.begin(), ve.end());

	for (unsigned int i = 0; i < ve.size(); i++) {
		if (get<2>(ve[i]) == 0) {
			qu.push(get<3>(ve[i]));
			open[get<3>(ve[i])] = 1;
		}
		else {
			if (qu.front() == get<3>(ve[i])) {
				open[qu.front()] = 0;
				while (!qu.empty() && open[qu.front()] == 0) {
					qu.pop();
				}
			}
			else {
				check[get<3>(ve[i])] = 1;
				open[get<3>(ve[i])] = 0;
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		if (!check[i]) {
			printf("%d ", i);
		}
	}
}