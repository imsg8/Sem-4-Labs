#include <stdio.h>

int opcount = 0;

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void copy(int* arr, int* indexArr, int m) {
    for (int i = 0; i < m; i++) {
        arr[i] = indexArr[i] + 1;
    }
}

void minCost(int arr[][10], int* indexArr, int start, int end, int m, int* minArr, int* minSal) {
    if (start == end) {
        int sum = 0;
        for (int i = 0; i < m; i++)
            sum += arr[i][indexArr[i]];
        opcount++;
        if (*minSal == 0 || *minSal > sum) {
            *minSal = sum;
            copy(minArr, indexArr, m);
        }
    } else {
        for (int i = start; i <= end; i++) {
            swap((indexArr + start), (indexArr + i));
            minCost(arr, indexArr, start + 1, end, m, minArr, minSal);
            swap((indexArr + start), (indexArr + i));
        }
    }
}

int main() {
    int m;
    printf("Enter the number of persons/jobs: ");
    scanf("%d", &m);
    int arr[10][10];  

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter the salary for Job %d for Person %d: ", j+1, i+1);
            scanf("%d", &arr[i][j]);
        }
    }

    int indexArr[10];
    int minArr[10];
    int minSal = 0;
    int start = 0, end = m - 1;

    for (int i = 0; i < m; i++)
        indexArr[i] = i;

    minCost(arr, indexArr, 0, m - 1, m, minArr, &minSal);

    printf("Minimum Cost is %d for the array: ", minSal);
    for (int i = 0; i < m; i++)
        printf("%d ", minArr[i]);
    printf("\nOperation Count: %d\n", opcount);

    return 0;
}
