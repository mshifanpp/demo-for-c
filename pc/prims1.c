#include <stdio.h>

int main() {
    int u, v, n, i, j, ne = 1;
    int visited[11] = {0};   // 1-based indexing
    int cost[11][11];
    int min, mincost = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;   // treat 0 as no edge
        }
    }

    visited[1] = 1;   // Start with node 1

    while (ne < n) {
        min = 999;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (visited[i] && !visited[j] && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        printf("\nEdge %d: (%d -> %d)  cost: %d", ne++, u, v, min);
        mincost += min;
        visited[v] = 1;

        cost[u][v] = cost[v][u] = 999; // block the edge
    }

    printf("\n\nMinimum cost = %d\n", mincost);
    return 0;
}

