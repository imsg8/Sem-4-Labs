#include <stdio.h>

int graph[10][10];
int vertices;
int visited[10];
int q[10], front = 0, rear = 0;

void enqueue(int vertex) {
    q[rear++] = vertex;
}

int dequeue() {
    if (front == rear)
        return -1;
    return q[front++];
}

void bfs_visit(int vertex) {
    printf("Visiting %d\n", (vertex + 1));
    visited[vertex] = 1;
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i] && graph[vertex][i] && i != vertex)
            enqueue(i);
    }
}

void bfs() {
    int x;
    enqueue(0);
    do {
        x = dequeue();
        if (x != -1 && !visited[x])
            bfs_visit(x);
    } while (x != -1);
}

int main() {
    printf("Enter the Number of Vertices: \n");
    scanf("%d", &vertices);
    
    printf("Enter the Adjacency Matrix: \n");
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j)
            scanf("%d", &graph[i][j]);
    }	
    
    bfs();
    return 0;
}
