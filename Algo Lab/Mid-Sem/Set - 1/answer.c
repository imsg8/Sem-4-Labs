//count number of zeros in array using decrease and conquer

#include <stdio.h>
int countZeroes(int arr[], int start, int end) {
    if (start == end) {
        return arr[start] == 0 ? 1 : 0;
    }
    int mid = (start + end) / 2;
    int leftCount = countZeroes(arr, start, mid);
    int rightCount = countZeroes(arr, mid + 1, end);
    return leftCount + rightCount;
}

int main() {
    int size, n, arr[25];
    printf("Enter size of array: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    size = sizeof(arr) / sizeof(arr[0]);
    int zeroCount = countZeroes(arr, 0, size - 1);
    printf("Number of zeroes in the array: %d\n", zeroCount);
    return 0;
}
