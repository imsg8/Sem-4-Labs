#include <stdio.h>
#define maxv 10
int adjmat[maxv][maxv];
int vertices;
int visited[maxv];
int stack[maxv];
int top = -1;

void push(int vertex) {
    printf("Pushed: %d\n", (vertex + 1));
    stack[++top] = vertex;
}

int pop() {
    return stack[top--];
}

int isStackEmpty() {
    return top == -1;
}

void dfs_visit(int startv) {
    push(startv);
    visited[startv] = 1;

    while (!isStackEmpty()) {
        int currv = pop();
        printf("Popped: %d\n", (currv + 1));

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i] && adjmat[currv][i] && i != currv) {
                push(i);
                visited[i] = 1;
            }
        }
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
            scanf("%d", &adjmat[i][j]);
    }

    dfs();
    return 0;
}
