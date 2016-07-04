#include<stdio.h>
#include<vector>

using namespace std;

int N, answer = -1, answer1;
int apple[10010];
int start[10010];
vector<int> ve[10010];

int recursion(int index, int pa);

int main(void) {
	int i;
	int temp1, temp2;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &apple[i]);
		start[i] = i;
	}

	for (i = 1; i < N; i++) {
		scanf("%d %d", &temp1, &temp2);
		ve[temp1].push_back(temp2);
		ve[temp2].push_back(temp1);
	}

	recursion(1, 0);

	printf("%d %d", answer, answer1);

	return 0;
}

int recursion(int index, int pa) {
	int i;
	int max1 = 0, max2 = 0;
	int t_start = start[index];
	int temp;

	for (i = 0; i < (int)ve[index].size(); i++) {
		if (ve[index][i] == pa) {
			continue;
		}
		else {
			temp = recursion(ve[index][i], index);
			if (temp > max1) {
				t_start = start[index];
				start[index] = start[ve[index][i]];
				max2 = max1;
				max1 = temp;
			}
			else if (temp == max1) {
				if (start[index] > start[ve[index][i]]) {
					t_start = start[index];
					start[index] = start[ve[index][i]];
					max2 = max1;
					max1 = temp;
				}
				else {
					t_start = start[ve[index][i]];
					max2 = temp;
				}
			}
			else if (temp > max2) {
				t_start = start[ve[index][i]];
				max2 = temp;
			}
		}
	}

	if (max1 + max2 + apple[index] > answer) {
		answer = max1 + max2 + apple[index];
		answer1 = t_start > start[index] ? start[index] : t_start;
	}
	else if (max1 + max2 + apple[index] == answer) {
		temp = t_start > start[index] ? start[index] : t_start;
		answer1 = temp > answer1 ? answer1 : temp;
	}

	return max1 + apple[index];
}
