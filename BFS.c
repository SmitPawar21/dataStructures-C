#include <stdio.h>
#define MAX_NODES 100

int adj_matrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int values[MAX_NODES];

int queue[MAX_NODES];
int front = 0, rear = -1;

int vertices;

void createGraph() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter values for each node: ");
    for(i=0; i<vertices; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter values for adjacency matrix: \n");
    for(i=0; i<vertices; i++) {
        for(j=0; j<vertices; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    for(i=0; i<vertices; i++) {
        visited[i] = 0;
    }
}

void bfs(int vertex) {
    int i;

    for(i=0; i<vertices; i++) {
        if((adj_matrix[vertex][i] == 1) && (visited[i] == 0)) {
            queue[++rear] = i;
            visited[i] = 1;
            printf("%d ", values[i]);
        }
    }
    if(front <= rear) {
        bfs(queue[front++]);
    }
}

void main() {
    int vertex;
    createGraph();

    printf("Enter vertex: ");
    scanf("%d", &vertex);

    printf("%d ", values[vertex]);
    visited[vertex] = 1;
    bfs(vertex);
}