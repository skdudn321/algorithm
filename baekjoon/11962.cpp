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
typedef pair<lli, lli> ll;

int ans;
int N, Q;

ll min_tree[600000];
ll sum_tree[600000];
ii lor[600000];
char str[1000];

void make_lor(int ind, int left, int right);
void min_change(int ind, int left, int right, lli value);
void sum_change(int ind, int left, int right, lli value);
lli min_value(int ind, int left, int right);
lli sum_value(int ind, int left, int right);

int main(void) {
	make_lor(1, 1, 262144);
	scanf("%d %d", &N, &Q);
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		min_change(1, i, i, temp);
		sum_change(1, i, i, temp);
	}
	gets(str);
	for (int i = 1; i <= Q; i++) {
		char temp;
		int t1, t2;
		lli t3;
		gets(str);
		temp = str[0];
		if (temp == 'M') {
			sscanf(str + 1, "%d %d", &t1, &t2);
			printf("%lld\n", min_value(1, t1, t2));
		}
		else if (temp == 'S') {
			sscanf(str + 1, "%d %d", &t1, &t2);
			printf("%lld\n", sum_value(1, t1, t2));
		}
		else {
			sscanf(str + 1, "%d %d %lld", &t1, &t2, &t3);
			min_change(1, t1, t2, t3);
			sum_change(1, t1, t2, t3);
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
void min_change(int ind, int left, int right, lli value) {
	if (lor[ind].first == left && lor[ind].second == right) {
		min_tree[ind].second += value;
		ind /= 2;
		while (ind != 0) {
			min_tree[ind].first = min(min_tree[ind * 2].first + min_tree[ind * 2].second, min_tree[ind * 2 + 1].first + min_tree[ind * 2 + 1].second);
			ind /= 2;
		}
		return;
	}

	int mid = (lor[ind].first + lor[ind].second) / 2;
	if (left > mid) {
		min_change(ind * 2 + 1, left, right, value);
	}
	else if (right <= mid) {
		min_change(ind * 2, left, right, value);
	}
	else {
		min_change(ind * 2, left, mid, value);
		min_change(ind * 2 + 1, mid + 1, right, value);
	}
}
void sum_change(int ind, int left, int right, lli value) {
	if (lor[ind].first == left && lor[ind].second == right) {
		sum_tree[ind].second += value;
		ind /= 2;
		int len = right - left + 1;
		while (ind != 0) {
			sum_tree[ind].first += value * len;
			ind /= 2;
		}
		return;
	}

	int mid = (lor[ind].first + lor[ind].second) / 2;
	if (left > mid) {
		sum_change(ind * 2 + 1, left, right, value);
	}
	else if (right <= mid) {
		sum_change(ind * 2, left, right, value);
	}
	else {
		sum_change(ind * 2, left, mid, value);
		sum_change(ind * 2 + 1, mid + 1, right, value);
	}
}
lli min_value(int ind, int left, int right) {
	if (lor[ind].first == left && lor[ind].second == right) {
		int len = right - left + 1;
		return min_tree[ind].first + min_tree[ind].second;
	}
	lli ret;
	int mid = (lor[ind].first + lor[ind].second) / 2;
	if (min_tree[ind].second != 0) {
		min_tree[ind].first += min_tree[ind].second;
		min_tree[ind * 2].second += min_tree[ind].second;
		min_tree[ind * 2 + 1].second += min_tree[ind].second;
		min_tree[ind].second = 0;
	}
	if (left > mid) {
		ret = min_value(ind * 2 + 1, left, right);
	}
	else if (right <= mid) {
		ret = min_value(ind * 2, left, right);
	}
	else {
		ret = min_value(ind * 2, left, mid);
		ret = min(ret, min_value(ind * 2 + 1, mid + 1, right));
	}

	return ret;
}
lli sum_value(int ind, int left, int right) {
	if (lor[ind].first == left && lor[ind].second == right) {
		int len = right - left + 1;
		return sum_tree[ind].first + sum_tree[ind].second * len;
	}
	lli ret;
	int len = lor[ind].second - lor[ind].first + 1;
	int mid = (lor[ind].first + lor[ind].second) / 2;
	if (sum_tree[ind].second != 0) {
		sum_tree[ind].first += len * sum_tree[ind].second;
		sum_tree[ind * 2].second += sum_tree[ind].second;
		sum_tree[ind * 2 + 1].second += sum_tree[ind].second;
		sum_tree[ind].second = 0;
	}
	if (left > mid) {
		ret = sum_value(ind * 2 + 1, left, right);
	}
	else if (right <= mid) {
		ret = sum_value(ind * 2, left, right);
	}
	else {
		ret = sum_value(ind * 2, left, mid);
		ret += sum_value(ind * 2 + 1, mid + 1, right);
	}

	return ret;
}