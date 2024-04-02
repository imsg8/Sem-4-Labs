#include <stdio.h>
#define max 1000

int min(int a, int b) {
    return a < b ? a : b;
}

void Floyd(int M[][max], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter No. of Vertices : \t");
    scanf("%d", &n);
    int adj[max][max];
    printf("\nEnter Weighted Adjacency Matrix : \nEnter -1 for Infinity\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == -1) {
                adj[i][j] = max;
            }
        }
    }
    Floyd(adj, n);
    printf("\nAll Pairs Shortest Path Matrix is :\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}
