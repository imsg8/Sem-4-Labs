#include <stdio.h>
#define MAX_ITEMS 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void KnapSack(int KS[][MAX_ITEMS], int n, int w, int V[], int W[]) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= w; j++) {
            if (j - W[i] >= 0) {
                KS[i][j] = max(KS[i - 1][j], V[i] + KS[i - 1][j - W[i]]);
            } else {
                KS[i][j] = KS[i - 1][j];
            }
        }
    }
}

int main() {
    int w, n, i, j, l = 0, cost = 0;
    printf("Enter No. of Items: ");
    scanf("%d", &n);
    printf("Enter Capacity: ");
    scanf("%d", &w);
    int W[n + 1], V[n + 1], subset[n + 1];
    V[0] = W[0] = 0;
    printf("Enter Weights of Items: \n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &W[i]);
    }
    printf("Enter Prices of Items: \n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &V[i]);
    }
    int KS[n + 1][MAX_ITEMS];
    KnapSack(KS, n, w, V, W);
    printf("\nKnapSack Table:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= w; j++) {
            printf("%d\t", KS[i][j]);
        }
        printf("\n");
    }
    printf("\nKnapSack Items: ");
    for (i = n; i > 0; i--) {
        if (KS[i][w] != KS[i - 1][w]) {
            cost += V[i];
            subset[l++] = i;
            w -= W[i];
        }
    }
    for (i = l - 1; i >= 0; i--) {
        printf("%d ", subset[i]);
    }
    printf("\n\nCost: %d\n", cost);
    return 0;
}
