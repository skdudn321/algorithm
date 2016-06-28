#include<stdio.h>
#include<algorithm>

using namespace std;

int L, K, C;
int tree[10010];
int max_size = 0;
int first, last;
int max_value = 1000000000;

bool check_size(int length);
int first_cut(int length);

int main(void) {
	scanf("%d %d %d", &L, &K, &C);
	if (C > K) {
		C = K;
	}

	for (int i = 1; i <= K; i++) {
		scanf("%d", &tree[i]);
	}
	tree[K + 1] = L;
	sort(tree + 1, tree + K + 1);
	for (int i = 0; i <= K; i++) {
		max_size = tree[i + 1] - tree[i] > max_size ? tree[i + 1] - tree[i] : max_size;
	}

	first = 0;
	last = L;

	while (first <= last) {
		int pivot = ((last - first) / 2) + first;
		if (check_size(pivot)) {
			max_value = pivot;
			last = pivot - 1;
		}
		else {
			first = pivot + 1;
		}
	}

	printf("%d %d", max_value, first_cut(max_value));
}

bool check_size(int length) {
	int count = C;
	int start = 0;

	if (max_size > length) {
		return false;
	}

	for (int i = 1; i <= K; i++) {
		while (i + 1 <= K && tree[i + 1] - start <= length) {
			i++;
		}
		start = tree[i];
		count--;
		if (count == 0) {
			if (tree[K + 1] - start <= length) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	if (tree[K + 1] - start <= length) {
		return true;
	}
	else {
		return false;
	}
}

int first_cut(int length) {
	int count = C;
	int start = L;
	int i;

	for (i = K; i >= 1; i--) {
		while (i - 1 >= 1 && start - tree[i - 1] <= length) {
			i--;
		}
		start = tree[i];
		count--;
		if (count == 0) {
			return tree[i];
		}
	}

	return tree[1];
}