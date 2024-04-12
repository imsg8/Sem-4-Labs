#include <stdio.h>

#define max 100
#define inf 999

int cost[max][max];
int parent[max];
int n, ne = 1;

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int i, j, a, b, u, v, min, mincost = 0;
    
    printf("\nNo. of vertices: ");
    scanf("%d", &n);
    
    printf("\nCost adjacency matrix: \n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = inf;
        }
    }
    
    printf("Minimum spanning tree: \n");
    while (ne < n) {
        for (i = 1, min = inf; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = inf;
    }
    printf("\nMinimum cost = %d\n", mincost);
    
    return 0;
}
