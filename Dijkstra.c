#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int minDistance(int dist[], int sptSet[], int n) {
    int min = INF, min_index;
    for (int v = 0; v < n; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int src, int dest, int n) {
    int dist[MAX];
    int sptSet[MAX];
    int parent[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF, sptSet[i] = 0, parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    if (dist[dest] == INF) {
        printf("No path from source to destination.\n");
        return;
    }

    printf("Shortest path cost: %d\n", dist[dest]);
    printf("Shortest path: ");
    
    int path[MAX], pathIndex = 0, current = dest;
    while (current != -1) {
        path[pathIndex++] = current;
        current = parent[current];
    }

    for (int i = pathIndex - 1; i >= 0; i--) {
        printf("%c ", path[i] + 'A');
    }
    printf("\n");
}

int main() {
    int n, src, dest;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 for no connection):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    src = 0;  // Node A
    dest = 5; // Node F

    dijkstra(graph, src, dest, n);

    return 0;
}
