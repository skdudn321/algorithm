#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

int month[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

priority_queue<int> pq;
vector<int> flower[400];
int N;
int cur, last;
int ans;

int main(void){

	scanf("%d", &N);

	for (int i = 1; i <= N; i++){
		int x, y;
		int temp1, temp2;
		scanf("%d %d", &x, &y);
		temp1 = month[x] + y;
		scanf("%d %d", &x, &y);
		temp2 = month[x] + y;
		flower[temp1].push_back(temp2);
		if (temp1 <= 60){
			pq.push(temp2);
		}
	}
	if (pq.empty()){
		printf("0");
		return 0;
	}

	last = 60;
	ans = 1;
	while (pq.top() <= 334){
		cur = pq.top();
		if (cur == last){
			printf("0");
			return 0;
		}
		for (int i = last; i <= cur; i++){
			for (int j = 0; j < flower[i].size(); j++){
				pq.push(flower[i][j]);
			}
		}
		last = cur;
		ans++;
	}

	printf("%d", ans);
}