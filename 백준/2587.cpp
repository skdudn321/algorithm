#include<stdio.h>
#include<algorithm>

using namespace std;

int num[5];
int sum;

int main(void){
    for(int i = 0; i < 5; i++){
        scanf("%d", &num[i]);
        sum += num[i];
    }
    sort(num, num + 5);
    printf("%d\n%d", sum / 5, num[2]);
}