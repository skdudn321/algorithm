#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

bool num[10000001];
int ans;

int main(void){
	int N, M;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++){
		int temp;
		scanf("%d", &temp);
        if(temp <= M){
		    if (num[M - temp]){
		    	ans++;
	    		num[M - temp] = false;
	    	}
	    	else{
    			num[temp] = true;
	    	}
        }
	}
	printf("%d", ans);
}