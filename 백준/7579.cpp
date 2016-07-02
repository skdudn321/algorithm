#include<stdio.h>
#include<algorithm>

using namespace std;

int mem[101];
int cost[101];
int dp[10100];
int cut;

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
	scanf("%d", &mem[i]);
    }
    for(int i = 1; i <= N; i++){
	scanf("%d", &cost[i]);
        cut += cost[i];
    }
    
    dp[cost[1]] = mem[1];
    for(int i = 2 ; i <= N; i++){
        for(int j = cut; j > cost[i]; j--){
            if( dp[j - cost[i]] && dp[j]){ 
                dp[j] = max(dp[j - cost[i]] + mem[i], dp[j]);
            }
            else if(dp[j - cost[i]]){
                dp[j] = dp[j - cost[i]] + mem[i];
            }
            else{
                dp[j] = dp[j];
            }
        }
        dp[cost[i]] = max(mem[i] + dp[0], dp[cost[i]]);
    }
    
    for(int i = 0; i <= cut; i++){
        if(dp[i] >= M){
            printf("%d", i);
            return 0;
        }
    }
}