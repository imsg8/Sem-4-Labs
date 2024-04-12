#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int minDist(int dist[], bool visited[], int n) {
    int min = INT_MAX, minIndex;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printSolution(int dist[], int n) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] != INT_MAX) {
            printf("%d \t\t\t %d\n", i, dist[i]);
        } else {
            printf("%d \t\t\t %s\n", i, "Infinity");
        }
    }
}

void dijkstra(int adj[MAX_VERTICES][MAX_VERTICES], int n, int src) {
    int dist[n];
    bool visited[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = minDist(dist, visited, n);
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && adj[u][v] && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
    printSolution(dist, n);
}

int main() {
    int n;
    printf("Enter No. of Vertices: ");
    scanf("%d", &n);
    int adj[MAX_VERTICES][MAX_VERTICES];
    printf("Enter Adjacency Weight Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    int src;
    printf("Enter Start Vertex: ");
    scanf("%d", &src);
    dijkstra(adj, n, src);
    return 0;
}
