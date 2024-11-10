#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int visited[MAX_NODES];
int values[MAX_NODES];
int adj_matrix[MAX_NODES][MAX_NODES];

int vertices;

void createGraph() {
    int i, j;
    int value, data;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    //  Taking Input for Values
    printf("Enter values for each node: \n");
    for(i=0; i < vertices; i++) {
        scanf("%d", &data);
        values[i] = data;
    }

    printf("Values: ");
    for(i=0; i<vertices; i++) {
        printf("%d ", values[i]);
    }

    //  Taking Input for Adjacency Matrix
    printf("Enter values for Adjacency Matrix: \n");
    for(i=0; i<vertices; i++) {
        for(j=0; j<vertices; j++) {
            scanf("%d", &value);
            adj_matrix[i][j] = value;
        }
    }

    //  Diplaying Graph in Adjacency Matrix
    printf("Graph Representation - Adjacency Matrix\n");
    for(i=0; i<vertices; i++) {
        for(j=0; j<vertices; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }

    //  Initializing visited array to 0's
    for(i=0; i<vertices; i++) {
        visited[i] = 0;
    }
}

void dfs(int vertex) {
    int i;

    printf("%d ", values[vertex]);
    visited[vertex] = 1;
    for(i=0; i<vertices; i++) {
        if((adj_matrix[vertex][i] == 1) && (visited[i] == 0)) {
            visited[i] = 1;
            dfs(i);
        }
    }
}

void main() {
    createGraph();
    dfs(0);
}