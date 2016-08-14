#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<math.h>

using namespace std;

typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;
typedef pair<ii, int> jj;

int max_tree[150000];
ii lor[150000];
vector<jj> ve;
int N, M;

void make_lor(int ind, int left, int right);
void change(int ind, int value);
int max_value(int ind, int left, int right);

int main(void) {
	freopen("test.txt", "r", stdin);
	make_lor(1, 1, 65536);
	scanf("%d", &N);
	ve.push_back(jj(ii(-1000000001, 0), 0));
	for (int i = 1; i <= N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		ve.push_back(jj(ii(t1, t2), 0));
	}
	ve.push_back(jj(ii(1000000001, 0), 0));
	for (int i = 0; i <= N + 1; i++) {
		ve[i].second = i + 1;
		change(65536 + i, ve[i].first.second);
	}

	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		vector<jj>::iterator temp1 = lower_bound(ve.begin(), ve.end(), jj(ii(t1, 0), 0));
		vector<jj>::iterator temp2 = lower_bound(ve.begin(), ve.end(), jj(ii(t2, 0), 0));

		int X, Y, Z;
		bool check = false;
		if (t1 == (*temp1).first.first) {
			Y = (*temp1).first.second;
			temp1++;
		}
		else {
			Y = 1000000002;
			check = true;
		}

		if (t2 == (*temp2).first.first) {
			X = (*temp2).first.second;
		}
		else {
			X = Y;
			check = true;
		}
		temp2--;

		if ((*temp1).second > (*temp2).second) {
			Z = -1000000001;
			check = true;
		}
		else {
			Z = max_value(1, (*temp1).second, (*temp2).second);
		}

		if ((*temp2).second - (*temp1).second + 1 != t2 - t1 - 1) {
			check = true;
		}

		if (Y >= X && X > Z) {
			if (check) {
				printf("maybe\n");
			}
			else {
				printf("true\n");
			}
		}
		else {
			printf("false\n");
		}
	}
}

void make_lor(int ind, int left, int right) {
	lor[ind] = ii(left, right);
	if (left == right) {
		return;
	}

	int mid = (left + right) / 2;
	make_lor(ind * 2, left, mid);
	make_lor(ind * 2 + 1, mid + 1, right);
}
void change(int ind, int value) {
	max_tree[ind] = value;
	ind /= 2;
	while (ind != 0) {
		max_tree[ind] = max(max_tree[ind * 2], max_tree[ind * 2 + 1]);
		ind /= 2;
	}
}
int max_value(int ind, int left, int right) {
	if (lor[ind].first == left && lor[ind].second == right) {
		return max_tree[ind];
	}

	int mid = (lor[ind].first + lor[ind].second) / 2;
	int ret;

	if (left > mid) {
		ret = max_value(ind * 2 + 1, left, right);
	}
	else if (right <= mid) {
		ret = max_value(ind * 2, left, right);
	}
	else {
		ret = max_value(ind * 2, left, mid);
		ret = max(ret, max_value(ind * 2 + 1, mid + 1, right));
	}

	return ret;
}