#include <stdio.h>
#define INF 999
int prim(int c[10][10], int n, int s) {
    int v[10] = {0}, ver[10], d[10], sum = 0, i, j, min, u;
    for (i = 1; i <= n; i++) {
        d[i] = c[s][i];
        ver[i] = s;
    }
    v[s] = 1;
    for (i = 1; i < n; i++) {
        min = INF;
        for (j = 1; j <= n; j++)
            if (!v[j] && d[j] < min)
                min = d[u = j];
        v[u] = 1;
        sum += d[u];
        printf("\n%d->%d sum=%d", ver[u], u, sum);
        for (j = 1; j <= n; j++)
            if (!v[j] && c[u][j] < d[j]) {
                d[j] = c[u][j];
                ver[j] = u;
            }
    }
    return sum;
}
void main() {
    int c[10][10], i, j, n, s, res;
    printf("Enter n value: ");
    scanf("%d", &n);
    printf("Enter the graph data:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
    printf("Enter the source node: ");
    scanf("%d", &s);
    res = prim(c, n, s);
    printf("\nCost = %d", res);
}


