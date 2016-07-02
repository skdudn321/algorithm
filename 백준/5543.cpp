#include<stdio.h>
#include<algorithm>

using namespace std;

int ans;

int main(void){
    int t1, t2, t3;
    scanf("%d %d %d", &t1, &t2, &t3);
    ans += min(t1, min(t2, t3));
    scanf("%d %d", &t1, &t2);
    ans += min(t1, t2);
    ans -= 50;
    printf("%d", ans);
}