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

int ans;
int N, M;
bool check[101];
bool check2[101];
int table[101];
int size_of_concent;

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d", &table[i]);
	}

	int i = 1;
	while (size_of_concent < N && i <= M) {
		if (!check[table[i]]) {
			size_of_concent++;
			check[table[i]] = true;
		}
		i++;
	}

	for (; i <= M; i++) {
		if (!check[table[i]]) {
			int temp = N;
			for (int j = 1; j <= M; j++) {
				check2[j] = check[j];
			}
			for (int j = i + 1; j <= M && temp > 1; j++) {
				if (check2[table[j]]) {
					check2[table[j]] = false;
					temp--;
				}
			}
			for (int j = 1; j <= M; j++) {
				if (check2[j]) {
					check[j] = false;
					check[table[i]] = true;
					ans++;
					break;
				}
			}
		}
	}

	printf("%d", ans);
}