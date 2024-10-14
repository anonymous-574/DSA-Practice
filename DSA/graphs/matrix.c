#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph
{
    int no_of_edges;
    int no_of_vertices;
    //array of adjacency graphs
    int ** arr;
}graph;

graph* expand_graph(graph * g ,int vertices) {
  int old_vertices_no= g->no_of_vertices;
  g->no_of_vertices=vertices;

    g->arr= realloc(g->arr,g->no_of_vertices * sizeof(int*)); 
    for(int i = 0; i < g->no_of_vertices; i++)
    {
        g->arr[i] = realloc(g->arr[i],g->no_of_vertices * sizeof(int));
    }

  //set new nodes to null
  for (int i = old_vertices_no; i <vertices ; i++)
  {
    for (int j = 0; j < vertices; j++)
    {
        g->arr[i][j]=0;
        g->arr[j][i]=0;
    }
  }

  return g;
}

graph * add_edge (graph * g ,int e1,int e2)
{
    printf("ADDING %d , %d \n",e1,e2);
    g->no_of_edges++;
    g->arr[e1][e2]=1;
    g->arr[e2][e1]=1;
    return g;
}

typedef struct queue{
    int* items;
    int front;
    int rear;
    int size;
} queue;

bool isEmpty(queue* q) { return (q->front == q->rear - 1); }

bool isFull(queue* q) { return (q->rear == q->size); }

void enqueue(queue* q, int value)
{
    if (isFull(q)) {
        printf("queue is full\n");
        return;
    }
    q->items[q->rear] = value;
    q->rear++;
}

int dequeue(queue* q)
{
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return -1;
    }
    q->front++;
    return q->items[q->front]; 
}

int * init_visited(graph  * g)
{
int * visited = (int *) malloc(g->no_of_vertices * sizeof(int));
    for (int i = 0; i < g->no_of_vertices; i++)
    {
        visited[i]=0;
    }
return visited;
}

void bfs (graph * g)
{
    int * visited = init_visited(g);
    queue * q = (queue * )malloc(sizeof(queue));
    int size_o_q=10;
    q->size=size_o_q;
    q->items=(int *)malloc(size_o_q*sizeof(int));
    q->front = -1;
    q->rear = 0;
    int time=1;

    //i IS SAME AS STARTING VERTEX 
    int i=0;
    //printf("%d ",i);
    printf("%d ,Entering Time= %d\n",i,time);
    enqueue(q,i);
    visited[i]=1;

    while (!isEmpty(q))
    {
        int node = dequeue(q);
        

        for (int j = 0; j < g->no_of_vertices; j++)
        {
            //if edge is 1 and node not visited
            if (g->arr[node][j]==1 && visited[j]==0)
            {
                time++;
                printf("%d ,Entering Time= %d\n",j,time);
                //printf("%d \n",j);
                visited[j]=1;
                enqueue(q,j);
            }
            
        }
        time++;
        i++;
        printf("%d ,Exiting Time= %d\n",i,time);
        
    }
    free(q->items);
    free(q);
}

int time=0;
void dfs(graph *g, int start, int * visited) {


    int i=start;
    printf("%d ,Entering Time= %d\n",i,time);
    //printf("%d ",i);
    visited[i]=1;

    for (int j = 0; j < g->no_of_vertices; j++)
    {
        if (g->arr[i][j]==1 && !visited[j])
        {
            dfs(g,j,visited);
            printf("%d ,Exiting Time= %d\n",j,time);
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    graph * g = (graph *) malloc(sizeof(graph));
    g->no_of_vertices=5;
    g->no_of_edges=0;

    // make 2d array
    g->arr= malloc(g->no_of_vertices * sizeof(int*)); 
    for(int i = 0; i < g->no_of_vertices; i++)
    {
        g->arr[i] = malloc(g->no_of_vertices * sizeof(int));
    }
    
    for (int i = 0; i < g->no_of_vertices; i++)
    {
        for (int j = 0; j < g->no_of_vertices; j++)
        {
            g->arr[i][j]=0;
        }
    }

    //g=init(g);
    g=add_edge(g,0,1); 
    g=add_edge(g,0,2);
    g=add_edge(g,1,2);
    g=add_edge(g,1,3);
    g=add_edge(g,2,4);
    g=add_edge(g,3,4);
    printf("\n\n\n");
    bfs(g);
    printf("\n\n\n");
    int * visited=init_visited(g);
    dfs(g,0,visited);
    printf("\n\n\n");

    for(int i = 0; i < g->no_of_vertices; i++)
    {
    free(g->arr[i]);
    }

    free(g->arr);
    free(g);
    
    return 0;
}

/*
#include <stdio.h>

#define MAX_VERTICES 10

void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int vertices, int start, int start_time[MAX_VERTICES], int end_time[MAX_VERTICES], int *time) {
    visited[start] = 1;  // Mark the current vertex as visited
    start_time[start] = ++(*time);  // Record the start time
    printf("%d ", start);  // Print the current vertex

    // Visit all adjacent vertices
    for (int i = 0; i < vertices; i++) {
        if (graph[start][i] == 1 && visited[i] == 0) {  // Only visit unvisited nodes
            DFS(graph, visited, vertices, i, start_time, end_time, time);  // Recursive DFS call
        }
    }

    end_time[start] = ++(*time);  // Record the end time when fully explored
}

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};  // Initialize the adjacency matrix
    int visited[MAX_VERTICES] = {0};              // Initialize the visited array
    int start_time[MAX_VERTICES] = {0};           // Initialize start time array
    int end_time[MAX_VERTICES] = {0};             // Initialize end time array


    // Validate the number of edges
    if (edges < 0 || edges > vertices * (vertices - 1) / 2) {
        printf("Invalid number of edges. Exiting...\n");
        return 1;
    }

    // Input edges and construct the adjacency matrix
    for (int i = 0; i < edges; i++) {
        int start, end;
        printf("Enter edge %d (start end): ", i + 1);
        scanf("%d %d", &start, &end);

        // Validate edge input
        if (start < 0 || start >= vertices || end < 0 || end >= vertices) {
            printf("Invalid vertices. Try again.\n");
            i--;
            continue;
        }

        graph[start][end] = 1;  // Add edge from start to end
        graph[end][start] = 1;  // For undirected graph, also add edge from end to start
    }

    // Input the starting vertex for DFS traversal
    int startVertex;
    printf("Enter the starting vertex for DFS traversal: ");
    scanf("%d", &startVertex);

    // Validate starting vertex
    if (startVertex < 0 || startVertex >= vertices) {
        printf("Invalid starting vertex. Exiting...\n");
        return 1;
    }

    int time = 0;  // Initialize time counter
    printf("DFS Traversal Order: ");
    DFS(graph, visited, vertices, startVertex, start_time, end_time, &time);  // Call DFS

    // After traversal, print the start and end times for each vertex
    printf("\n\nVertex\tStart Time\tEnd Time\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t\t%d\t\t%d\n", i, start_time[i], end_time[i]);
    }

    return 0;
}


*/
