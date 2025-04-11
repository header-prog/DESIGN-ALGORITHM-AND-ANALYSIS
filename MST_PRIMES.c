#include <stdio.h>
#include <limits.h>

#define V 100  // Max number of vertices (change if needed)

int main() {
    int n; // number of vertices
    int graph[V][V]; // adjacency matrix
    int visited[V];  // to track visited nodes
    int key[V];      // to store minimum weight edge to a node
    int parent[V];   // to store MST

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize all keys to infinity and visited to 0
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    key[0] = 0; // Start from the first vertex

    for (int count = 0; count < n - 1; count++) {
        // Find the vertex with the minimum key value from the unvisited set
        int min = INT_MAX, u = -1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        visited[u] = 1;

        // Update key and parent of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST
    int total_weight = 0;
    printf("\nEdge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total_weight += graph[i][parent[i]];
    }

    printf("Total weight of MST: %d\n", total_weight);

    return 0;
}
