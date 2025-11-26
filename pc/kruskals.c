#include <stdio.h>

int i, j, u, v,rv,ru,n, ne = 1;
int min, mincost = 0;
int cost[10][10], parent[10];

//Finds root parent of vertex i
int find(int i) {
    while (parent[i])// Follow parent pointers up to the root
        i = parent[i];
    return i;
}
void union_sets(int i, int j) {
    if (i != j)
        parent[j] = i;// Attach root j under root i
}
//starting of main function
int main() {

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
       // Replace 0 with a large value 
            if (cost[i][j] == 0)
                cost[i][j] = 999;  
        }
    }

    printf("The edges of the Minimum Cost Spanning Tree are:\n");

    while (ne < n) {
        min = 999;
// Find the smallest unused edge
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;// Store vertices
                    v = j;
                }
            }
        }
// Find roots 
        ru = find(u);
        rv = find(v);
        // If adding this edge does NOT form a cycle
        if (ru != rv) {
            union_sets(ru, rv);
            printf("%d edge (%d, %d) = %d\n", ne++, u, v, min);
            mincost += min;
        }
// Remove this edge from future consideration
        cost[u][v] = cost[v][u] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}

