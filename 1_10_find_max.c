#include <stdio.h>
#include <stdlib.h>

int findMax(int a, int b){
    return ((a+b) + abs(b-a))/2;
}

int main(){
    int a,b;
    printf("Enter two numbers:");
    scanf("%d%d",&a,&b);
    printf("Max = %d\n",findMax(a,b));
}