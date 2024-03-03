//using divide and conquer, check if array a has two elements at indexes i and j such that i<j and a[i]>a[j]
//©SG :P
#include<stdio.h>
void pairs(int arr[], int i, int j, int n){

        if(i == n-1){
            return;
        }
        if(j==n){
            pairs(arr,i+1,i+2,n); 
            return; 
        }
        if(arr[i]>arr[j] && i < j){
            printf("Pair: %d %d\n",arr[i],arr[j]);
        }
        pairs(arr,i,j+1,n);
}

int main(){
    int n=0, i=0, j=0;
    int arr[25];
    printf("Enter size of array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nOriginal Array\n");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n \n");
    i = 0;
    j = 1;
    pairs(arr,i,j,n);
}
