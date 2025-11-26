#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Node structure for graph
struct node
{
    int data;
    int status;               // 0 = not visited, 1 = visited
    struct node *point, *next; // point → adjacency list, next → next vertex
};

// Global variables
struct node *g = NULL;   // Graph head
struct node *q[SIZE];    // Queue for BFS
int front = 0, rear = 0; // Queue indices

// Function to add a vertex
void addvertex(int n)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = n;
    t->point = NULL;
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

// Function to add an edge u → v
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

// Queue operations
void enque(struct node *s)
{
    int r1 = rear;
    r1 = (r1 + 1) % SIZE;
    if (front == r1)
    {
        printf("Queue is full\n");
        exit(1);
    }
    rear = r1;
    q[rear] = s;
}

int emptyq()
{
    return front == rear;
}

struct node *deque()
{
    if (emptyq())
    {
        printf("Queue is empty\n");
        exit(2);
    }
    front = (front + 1) % SIZE;
    return q[front];
}

// BFS traversal
void bfs(struct node *s)
{
    struct node *t = g, *t1, *u;

    // Initialize all vertices as not visited
    while (t != NULL)
    {
        t->status = 0;
        t = t->next;
    }

    printf("\nBFS Traversal: ");
    s->status = 1;
    printf("%d ", s->data);
    enque(s);

    while (!emptyq())
    {
        u = deque();
        t = u->point;

        while (t != NULL)
        {
            t1 = t->point;
            if (t1->status == 0)
            {
                printf("%d ", t1->data);
                t1->status = 1;
                enque(t1);
            }
            t = t->next;
        }
    }
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

    // Perform BFS
    bfs(find(1));

    return 0;
}

