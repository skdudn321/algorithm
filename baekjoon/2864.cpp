#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    char num1[10];
    char num2[10];
    int i, n1, n2, sum;
    char temp;
    
    for( i = 0; ; i++){
        temp = getchar();
        if(temp == ' '){
            num1[i] = 0;
            break;
        }
        if(temp == '6'){
            num1[i] = '5';
        }
        else{
            num1[i] = temp;
        }
    }
    for( i = 0; ; i++){
        temp = getchar();
        if(temp == '\n'){
            num2[i] = 0;
            break;
        }
        if(temp == '6'){
            num2[i] = '5';
        }
        else{
            num2[i] = temp;
        }
    }
    
    n1 = atoi(num1);
    n2 = atoi(num2);
    sum = n1 + n2;
    printf("%d ", sum);
    
    for( i = 0; i < 10 ; i++ ){
        if(num1[i] == '5'){
            num1[i] = '6';
        }
        if(num2[i] == '5'){
            num2[i] = '6';
        }
    }
    
    n1 = atoi(num1);
    n2 = atoi(num2);
    sum = n1 + n2;
    printf("%d\n", sum);
}