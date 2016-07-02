#include<stdio.h>

int main(void){
    int zero = 0, one = 0;
    int temp;
    int i, num;
    
    scanf("%d", &num);
    for(i = 0; i < num; i++){
        scanf("%d", &temp);
        if(temp == 0){
            zero++;
        }
        else{
            one++;
        }
    }
    
    if(one < zero){
        printf("Junhee is not cute!\n");
    }
    else{
        printf("Junhee is cute!\n");
    }
}