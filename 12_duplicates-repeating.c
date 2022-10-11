#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    printf("Enter the value of n: \n");
    scanf("%d",&n);

    int a[n];

    int freq[12];
    for(int i=0;i<12;i++) freq[i]=0;
    for(int i=0;i<n;i++){
        a[i]=rand()%12;
        freq[a[i]]++;
    }

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    printf("\nThe duplicate elements are: \n");
    int maxDuplicate=-1,maxDuplicateCount=-1;

    for(int i=0;i<12;i++){
        if(freq[i]>1){
            if(maxDuplicate<freq[i]){
                maxDuplicate=i;
                maxDuplicateCount=freq[i];
                
            }
            printf("Value: %d, Frequency: %d\n",i,freq[i]);
        }
    }

    printf("\nThe value %d repeats %d times in maximum", maxDuplicate,maxDuplicateCount);




    printf("\n");

}