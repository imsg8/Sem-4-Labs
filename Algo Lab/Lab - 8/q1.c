#include <stdio.h>
int op = 0;

void topdown(int arr[], int curr) {
    int parent = (curr - 1)/2;
    while(parent >= 0) {
	op++;
        if(arr[parent]<arr[curr]) {
            int temp = arr[parent];
            arr[parent] = arr[curr];
            arr[curr] = temp;
            curr = parent;
            parent = (curr - 1)/2;
        }
        else
            return;
    }
}

int main() {
    int h[20], n;
    printf("enter n:\n");
    scanf("%d", &n);
    printf("enter elements:\n");
    for(int i = 0; i<n; i++) {
        scanf("%d", &h[i]);
        topdown(h, i);
		for(int k = 0; k<=i; k++)
			printf("%d ", h[k]);
		printf("\n");
    }
    
    printf("heapified array:\n");
    
    for(int i = 0; i<n; i++)
        printf("%d ", h[i]);
    
    printf("\n");
    printf("OP = %d\n", op);
    exit(0);

    return 0;
}