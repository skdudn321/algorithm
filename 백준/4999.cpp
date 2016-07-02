#include<stdio.h>
#include<string.h>

char str1[10000];
char str2[10000];

int main(void){
    int len1, len2;
    scanf("%s\n", str1);
    scanf("%s", str2);
    
    len1 = strlen(str1);
    len2 = strlen(str2);
    
    if(len1 >= len2){
        printf("go\n");
    }
    else{
        printf("no\n");
    }
}