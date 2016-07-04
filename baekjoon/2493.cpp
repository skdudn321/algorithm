#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>

using namespace std;

typedef pair<int, int> ii;

stack<ii> st;

int main(void){
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++){
		int temp;
		scanf("%d", &temp);
		while (!st.empty() && st.top().first < temp){
			st.pop();
		}
		if (st.empty()){
			printf("0 ");
		}
		else{
			printf("%d ", st.top().second);
		}
		st.push(ii(temp, i));
	}
}