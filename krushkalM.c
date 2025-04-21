#include <stdio.h>
#define INF 999
#define MAX 100
int p[MAX], c[MAX][MAX], t[MAX][2];
int find(int v) {
    while (p[v]) v = p[v];
    return v;
}
void union1(int i, int j) {
    p[j] = i;
}
void kruskal(int n) {
    int i, j, k, u, v, min, res1, res2, sum = 0;
    for (k = 1; k < n; k++) {
        min = INF;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (i != j && c[i][j] < min) {
                    u = find(i);
                    v = find(j);
                    if (u != v) {
                        res1 = i;
                        res2 = j;
                        min = c[i][j];
                    }
                }
            }
        }
        union1(find(res1), find(res2));
        t[k][1] = res1;
        t[k][2] = res2;
        sum += min;
    }
    printf("\nCost of spanning tree = %d", sum);
    printf("\nEdges of spanning tree are:\n");
    for (i = 1; i < n; i++)
        printf("%d -> %d\n", t[i][1], t[i][2]);
}
int main() {
    int i, j, n;
    printf("\nEnter the value of n: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) p[i] = 0;
    printf("\nEnter the graph data:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
    kruskal(n);
    return 0;
}
