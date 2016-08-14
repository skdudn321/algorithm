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
int N;
bool graph[101][101];
int group[101];
vector<int> member[101];
int num_of_group;

bool check(int group_num);

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp;
			scanf("%d", &temp);
			if (temp == 0) {
				graph[i][j] = true;
			}
			else {
				graph[i][j] = false;
			}
		}
	}

	num_of_group = 1;
	for (int i = 1; i <= N; i++) {
		if (group[i] != 0) {
			continue;
		}
		for (int j = 1; j <= N; j++) {
			if (graph[i][j]) {
				group[j] = num_of_group;
				member[num_of_group].push_back(j);
			}
		}
		if (member[num_of_group].size() == 1 || !check(num_of_group)) {
			printf("0");
			return 0;
		}
		num_of_group++;
	}

	printf("%d\n", num_of_group - 1);
	for (int i = 1; i < num_of_group; i++) {
		for (int j = 0; j < member[i].size(); j++) {
			printf("%d ", member[i][j]);
		}
		printf("\n");
	}
}

bool check(int group_num) {
	for (int i = 0; i < member[group_num].size(); i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[member[group_num][i]][j] ^ (group[j] == group_num)) {
				return false;
			}
		}
	}
	return true;
}