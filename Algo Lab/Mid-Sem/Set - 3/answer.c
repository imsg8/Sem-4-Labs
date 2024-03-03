//print inversion pairs. Inv pairs means given an array a[n], find element pairs at a[i] and a[j] such that
//a[i] > a[j] and i < j.
#include <stdio.h>
int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left; 
    int j = mid; 
    int k = left;
    int inversions = 0;

    while (i < mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            inversions += mid - i;
            temp[k++] = arr[j++];
        }
    }
    while (i < mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }

    return inversions;
}

int mergeSort(int arr[], int temp[], int left, int right) {
    int inversions = 0;
    if (right > left) {
        int mid = (left + right) / 2;
        inversions += mergeSort(arr, temp, left, mid);
        inversions += mergeSort(arr, temp, mid + 1, right);
        inversions += merge(arr, temp, left, mid + 1, right);
    }
    return inversions;
}

void printInversionPairs(int arr[], int n) {
    int temp[n];
    int inversions = mergeSort(arr, temp, 0, n - 1);

    printf("Inversion pairs:\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int arr[] = {5, 2, 8, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printInversionPairs(arr, n);
    return 0;
}
