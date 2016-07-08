#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> ii;

ii dp[1000001];

int main(void){
    int N;
    scanf("%d", &N);
    dp[1] = ii(0, 0);
    
    for(int i = 2; i <= N; i++){
        if(i % 2 == 0 && i % 3 ==0){
            if(dp[i / 3] > dp[i / 2]){
                if(dp[i / 2] > dp[i - 1]){
                    dp[i] = ii(dp[i - 1].first + 1, i - 1);
                }
                else{
                    dp[i] = ii(dp[i / 2].first + 1, i / 2);
                }
            }
            else{
                if(dp[i / 3] > dp[i - 1]){
                    dp[i] = ii(dp[i - 1].first + 1, i - 1);
                }
                else{
                    dp[i] = ii(dp[i / 3].first + 1, i / 3);
                }
            }
        }
        else if(i % 2 == 0){
            if(dp[i / 2] > dp[i - 1]){
                dp[i] = ii(dp[i - 1].first + 1, i - 1);
            }
            else{
                dp[i] = ii(dp[i / 2].first + 1, i / 2);
            }
        }
        else if(i % 3 == 0){
            if(dp[i / 3] > dp[i - 1]){
                dp[i] = ii(dp[i - 1].first + 1, i - 1);
            }
            else{
                dp[i] = ii(dp[i / 3].first + 1, i / 3);
            }
        }
        else{
            dp[i] = ii(dp[i - 1].first + 1, i - 1);
        }
    }
    int i = N;
    printf("%d\n", dp[i].first);
    while(i != 0){
        printf("%d ", i);
        i = dp[i].second;
    }
}