#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];

void initMat(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void addWeights(int u, int v, int w, int n) {
    graph[u][v] = w;
    graph[v][u] = w;
}

void printmat(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void prims(int n, int source) {
    int parent[MAX], key[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        key[i] = MAX;
    }
    key[source] = 0;
    parent[source] = -1;

    for (int count = 0; count < n - 1; count++) {
        int min = MAX, u;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalCost = 0;
    printf("Output:\n");
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            printf("\n %d to %d costs %d", parent[i], i, graph[i][parent[i]]);
            totalCost += graph[i][parent[i]];
        }
    }
    printf("\nTotal cost of MST: %d\n", totalCost);
}

int main() {
    int u, v, w, n, e, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);
    initMat(n);

    printf("Enter the weights as follows (u v w):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addWeights(u, v, w, n);
    }

    printf("Enter the source node: ");
    scanf("%d", &source);

    prims(n, source);

    return 0;
}
