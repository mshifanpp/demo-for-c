#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
// Node structure for graph
struct node
{
   int data;
   int status;               
   struct node *point, *next; 
};
// Node structure for topological sort list
struct topsort
{
    int n;
    struct topsort *next;
};
// Global variables
struct node *g = 0;           
struct topsort *tsort = 0;    
// Function to add a vertex
void addvertex(int n)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = n;
    t->point = 0;
    t->next = g;
    g = t;
}
// Function to find vertex node address (linear search)
struct node *find(int n)
{
    struct node *t = g;
    while (t != NULL && t->data != n)
        t = t->next;
    return t;
}
// Function to add an edge u to v
void addedge(int u, int v)
{
    struct node *v1, *v2, *t;
    v1 = find(u);
    v2 = find(v);
    t = (struct node *)malloc(sizeof(struct node));
    t->next = v1->point;
    v1->point = t;
    t->point = v2;
}
// Function to print the graph
void printgraph()
{
    struct node *t1, *t2, *t3;
    printf("\nVertex\tEdgelist\n");
    t1 = g;
    while (t1 != NULL)
    {
        printf("\n%d --> ", t1->data);
        t2 = t1->point;
        while (t2 != NULL)
        {
            t3 = t2->point;
            printf("%d ", t3->data);
            t2 = t2->next;
        }
        t1 = t1->next;
    }
}

// Function to insert nodes in topological order (at beginning)
void topsorting(int n)
{
    struct topsort *z = (struct topsort *)malloc(sizeof(struct topsort));
    z->n = n;
    z->next = tsort;
    tsort = z;
}

// Function to print topological order
void topsortout()
{
    printf("\nTopological Sort Order: ");
    while (tsort != NULL)
    {
        printf("%d ", tsort->n);
        tsort = tsort->next;
    }
}

// DFS Visit (recursive)
void dfs_visit(struct node *u)
{
    struct node *t, *t1;
    u->status = 1; // mark as visited
    printf("%d ", u->data);

    t = u->point;
    while (t != NULL)
    {
        t1 = t->point;
        if (t1->status == 0) // if not visited
            dfs_visit(t1);
        t = t->next;
    }


    topsorting(u->data);
}

// DFS traversal
void dfs(struct node *g1)
{
    struct node *t = g;
    while (t != NULL)
    {
        t->status = 0; 
        t = t->next;
    }
    printf("\nDFS Traversal: ");
    dfs_visit(g1);
}

// Main function
int main()
{
 // Build graph
addvertex(1);
addvertex(2);
addvertex(3);
addvertex(4);
addvertex(5);
addedge(1, 2);
addedge(1, 4);
addedge(2, 3);
addedge(2, 4);
addedge(4, 3);
addedge(4, 5);
// Display graph 
printf("Graph structure:");
printgraph();
printf("\nDfs tranverse:");
dfs(find(1));
topsortout();
return 0;
}

