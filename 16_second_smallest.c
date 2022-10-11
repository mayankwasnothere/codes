#include <stdlib.h>
#include <stdio.h>

int main(){
    srand(time(0));
    int n;
    printf("Enter the value of n: \n");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) a[i]=rand()/1e7;

    printf("The array with random values: \n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");

    int max=a[0],secMax=a[0],min=max,secMin=max;

    for(int i=1;i<n;i++){
        if(max<a[i]){
            secMax=max;
            max=a[i];
        }
        if(min>a[i]){
            secMin=min;
            min=a[i];
        }
    }

    printf("Second largest = %d, Second smallest = %d\n",secMax,secMin);
}