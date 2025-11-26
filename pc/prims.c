//prims algorithm to find minimum cost for mst

#include <stdio.h>

void main() {
    int u, v, n, i, j, ne = 1;
    int visited[10] = {0}, min, mincost = 0, cost[10][10];
//read number of nodes
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
//read adjacency matrix
    printf("\nEnter the adjacency matrix:\n");
    
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            //if cost is 0,treat it as no edge by assigning very large value
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
//start from node 1
    visited[1] = 1;

    printf("\n");
    //repeat until mst has (n-1) edges
    while(ne < n) {
        min = 999;//reset minimum value for each iteration
        
        for(i = 1; i <= n; i++)//scan all edge to find minimum visited to unvisited
        
            for(j = 1; j <= n; j++)
            
                if(cost[i][j] < min)//check for smallest cost edge
                //ensure edge connects visited to unvisited
                    if(visited[i] != 0 && visited[j] == 0) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
//print selected edge
        printf("\nEdge %d:(%d %d) cost:%d", ne++, u, v, min);
        mincost += min;//add selected edge's cost to total MST cost
        visited[v] = 1;//mark new node as visited
        cost[u][v] = cost[v][u] = 999;//block this edge so its wont be selected again
    }

    printf("\nMinimum cost = %d\n", mincost);
}

