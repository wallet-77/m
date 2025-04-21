#include <stdio.h>
#define INF 999
int p[100], c[100][100], t[100][2];
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
                        min = c[i][j];
                        res1 = i;
                        res2 = j;
                    }
                }
            }
        }
        union1(find(res1), find(res2));
        t[k][0] = res1;
        t[k][1] = res2;
        sum += min;
    }
    printf("Cost of spanning tree: %d\nEdges:\n", sum);
    for (i = 1; i < n; i++)
        printf("%d -> %d\n", t[i][0], t[i][1]);
}
int main() {
    int i, j, n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
    for (i = 1; i <= n; i++)
        p[i] = 0;
    kruskal(n);
    return 0;
}

