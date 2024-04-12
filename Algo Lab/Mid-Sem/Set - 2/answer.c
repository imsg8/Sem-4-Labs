//From an array of n numbers, find the smallest and largest number using divide and conquer.

#include<stdio.h>
int i, n, arr[25];

int min(int arr[], int n, int start, int end) {
    if (start == end) {
        return arr[start];
    }

    int mid = (start + end) / 2;
    int left_min = min(arr, n, start, mid);
    int right_min = min(arr, n, mid + 1, end);

    return (left_min < right_min) ? left_min : right_min;
}

int max(int arr[], int n, int start, int end) {
    if (start == end) {
        return arr[start];
    }

    int mid = (start + end) / 2;
    int left_max = max(arr, n, start, mid);
    int right_max = max(arr, n, mid + 1, end);

    return (left_max > right_max) ? left_max : right_max;
}

int main() {
    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int minimumnumber = min(arr, n, 0, n - 1);
    int maximumnumber = max(arr, n, 0, n - 1);

    printf("\n \n");

    printf("Minimum is %d\n", minimumnumber);
    printf("Maximum is %d\n", maximumnumber);

    return 0;
}



// CACHE
/*

#include<stdio.h>
int i,n,arr[25];
int min(int arr[], int n, int start, int end, int ans1){
	if(end==n){
		return ans1;
	}
	if(arr[start]<ans1){
		ans1 = arr[start];
	}
	int mid = (start+end)/2;
	min(arr,n,start,mid,ans1);
	min(arr,n,mid+1,end,ans1);
}

int max(int arr[], int n, int start, int end, int ans2){
	if(end==n){
		return ans2;
	}
	if(arr[start]>ans2){
		ans2 = arr[start];
	}
	int mid = (start+end)/2;
	max(arr,n,start,mid,ans2);
	max(arr,n,mid+1,end,ans2);
}


int main(){
	printf("Enter size of array: ");
	scanf("%d",&n);
	printf("Enter elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int tempa = arr[0];
	int maximumnumber = max(arr,n,0,n,tempa);
	int minimumnumber = min(arr,n,0,n,tempa);

	printf("\n \n");

	printf("Minimum is %d\n",minimumnumber);
	printf("Maximum is %d\n",maximumnumber);
}


*/
