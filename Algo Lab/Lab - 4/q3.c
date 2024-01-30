#include <stdio.h>

int adjacencyMatrix[10][10];
int vertices;
int visited[10];

void dfs_visit(int vertex) {
    printf("Visiting %d\n", (vertex + 1));
    visited[vertex] = 1;
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i] && adjacencyMatrix[vertex][i] && i != vertex)
            dfs_visit(i);
    }
}

void dfs() {
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i])
            dfs_visit(i);
    }
}

int main() {
    printf("Enter the Number of Vertices: \n");
    scanf("%d", &vertices);
    
    printf("Enter the Adjacency Matrix: \n");
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j)
            scanf("%d", &adjacencyMatrix[i][j]);
    }

    dfs();
    return 0;
}
