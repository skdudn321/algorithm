#include<stdio.h>
#include<algorithm>
#include<functional>
#include<queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > qu;

int num;

int main(void){
	int N, sum = 0;
	int temp1, temp2;
	long long int cost = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &num);
		qu.push(num);
	}

	for (int i = 0; i < N - 1; i++){
		temp1 = qu.top();
		qu.pop();
		temp2 = qu.top();
		qu.pop();

		sum = (temp1 + temp2);
		cost += sum;
		qu.push(sum);
	}

	printf("%lld\n", cost);
}