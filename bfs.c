#include <stdio.h>

#define MAX 10  // maximum number of vertices

int queue[MAX];
int front = -1, rear = -1;

// Function to add an element to the queue
void enqueue(int vertex) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = vertex;
    }
}

// Function to remove an element from the queue
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// BFS function
void BFS(int adj[MAX][MAX], int visited[MAX], int start, int n) {
    int i, current;
    
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        current = dequeue();
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
int main() {
    int n, i, j, start;
    int adj[MAX][MAX];
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    BFS(adj, visited, start, n);

    return 0;
}
