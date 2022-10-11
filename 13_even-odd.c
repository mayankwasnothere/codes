#include <stdlib.h>
#include <stdio.h>

int main(){
    int n;
    printf("Enter the value of n: \n");

    scanf("%d",&n);

    srand(time(0));

    int a[n];

    for(int i=0;i<n;i++){
        a[i]=rand()/1e7;
    }

    printf("The array is : \n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
    printf("\n");

    int beg=0, end=n-1;

    while(beg<end){
        while(a[beg]%2==0 && beg<end) beg++;
        while(a[end]%2==1 && beg<end) end--;
        
        if(beg<end){
            
            int t=a[beg];
            a[beg]=a[end];
            a[end]=t;
            beg++;
            end--;
        }
    }

    for(int i=0;i<n;i++) printf("%d ",a[i]);
    
}







// 1 2 3 4 5 6 7 8 9 10

