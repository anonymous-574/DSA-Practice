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
    //printf("ADDING %d , %d \n",e1,e2);
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

void bfs_with_level(graph * g,int start)
{
    int * visited = init_visited(g);
    queue * q = (queue * )malloc(sizeof(queue));
    int size_o_q=10;
    q->size=size_o_q;
    q->items=(int *)malloc(size_o_q*sizeof(int));
    q->front = -1;
    q->rear = 0;
    int level=0;

    //i IS SAME AS STARTING VERTEX 
    int i=start;
    //printf("%d ",i);
    printf("%d ,Level= %d\n",i,level);
    
    enqueue(q,i);
    printf("Enqueuing %d \n",i);
    visited[i]=1;

    while (!isEmpty(q))
    {
        int node = dequeue(q);
        level++;

        for (int j = 0; j < g->no_of_vertices; j++)
        {
            //if edge is 1 and node not visited
            if (g->arr[node][j]==1 && visited[j]==0)
            {
                //printf("%d \n",j);
                printf("%d ,Level= %d\n",j,level);
                visited[j]=1;
                enqueue(q,j);
                printf("Dequeuing %d \n",j);
            }
            
        }
        level++;
        i++;
        
    }
    free(q->items);
    free(q);
}

void bfs(graph * g,int start)
{
    int * visited = init_visited(g);
    queue * q = (queue * )malloc(sizeof(queue));
    int size_o_q=10;
    q->size=size_o_q;
    q->items=(int *)malloc(size_o_q*sizeof(int));
    q->front = -1;
    q->rear = 0;

    //i IS SAME AS STARTING VERTEX 
    int i=start;
    printf("%d ",i);
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
                printf("%d ",j);
                visited[j]=1;
                enqueue(q,j);
            }
            
        }
        i++;
        
        
    }
    free(q->items);
    free(q);
}

int time=0;
int * start_time;
int * end_time;
void dfs_with_time(graph *g, int start, int * visited ) {

    start_time=(int*)malloc(sizeof(int)*g->no_of_vertices);
    end_time=(int*)malloc(sizeof(int)*g->no_of_vertices);
    for (int i = 0; i < g->no_of_vertices; i++)
    {
        start_time[i]=0;
        end_time[i]=0;
    }
    
    int i=start;
    time++;
    printf("%d ,Entering Time= %d\n",i,time);
    start_time[i]=time;
    visited[i]=1;

    for (int j = 0; j < g->no_of_vertices; j++)
    {
        if (g->arr[i][j]==1 && !visited[j])
        {
            dfs_with_time(g,j,visited);
            time++;
            printf("%d ,Exiting Time= %d\n",j,time);
        }
        
    }    
}

void show_table(graph * g)
{
    printf("Vertex \t Start Time \t End Time \n");
    for (int i = 0; i < g->no_of_vertices; i++)
    {
        printf(" %d \t   %d \t \t  %d \n",i,start_time[i],end_time[i]);
    }
    
}

void dfs(graph *g, int start, int * visited) {
    int i=start;
    printf("%d ",i);
    visited[i]=1;

    for (int j = 0; j < g->no_of_vertices; j++)
    {
        if (g->arr[i][j]==1 && !visited[j])
        {
            dfs(g,j,visited);
        }
        
    }
    
}

void display_graph(graph * g)
{
    for (int i = 0; i < g->no_of_vertices; i++)
    {
        for (int j = 0; j < g->no_of_vertices; j++)
        {
            printf("%d ",g->arr[i][j]);
        }
        printf("\n");
    }
    
}

void choice(graph * g)
{
    int choice=0,num=0;
    printf(" Enter 1 To add vertex \n Enter 2 To add edge \n Enter 3 for BFS \n Enter 4 for DFS \n Enter 5 to print Matrix \n Enter 0 to Exit \n");

    while (true)
    {
    
    printf("Enter choice \n");
        scanf("%d",&choice);
        if (choice==0)
        {
            printf("\nGoodbye\n");
            break;
        } 
    switch (choice)
    {
    case 1:
        {
            printf("Enter new number of vertices: \n");
            scanf("%d", &num);
            expand_graph(g,num);
            printf("\n\n");
            break;
        }
    case 2:
        {
            printf("Enter Edge to Add: \n");
            scanf("%d", &num);
            int num1=num;
            scanf("%d", &num);
            int num2=num;
            add_edge(g,num1,num2);
            printf("\n\n");
            break;
        }
    case 3:
        {
            printf("Enter Start Vertice: \n");
            scanf("%d", &num);
            printf("BFS is: \n");
            bfs(g,num);
            bfs_with_level(g,num);
            printf("\n\n");
            break;
        }
    case 4:
        {
            printf("Enter Start Vertice: \n");
            scanf("%d", &num);
            int * visited=init_visited(g);
            printf("DFS is: \n");
            dfs_with_time(g,num,visited);
            show_table(g);
            printf("\n\n\n");
            visited=init_visited(g);
            dfs(g,num,visited);
            printf("\n\n\n");
            break;
        }
    case 5:
        {
            printf("Graph Matrix is: \n");
            display_graph(g);
            break;
        }
    default:
        {   
            printf("USER IS AN IDTOT!");
            break;
        }
    }
}
}

int main(int argc, char const *argv[])
{
    graph * g = (graph *) malloc(sizeof(graph));
    g->no_of_vertices=8;
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

    //choice(g);

    g=add_edge(g,0,1); 
    g=add_edge(g,0,2);
    g=add_edge(g,0,3);
    g=add_edge(g,1,2);
    g=add_edge(g,1,4);
    g=add_edge(g,1,5);
    g=add_edge(g,2,5);
    g=add_edge(g,4,5);
    g=add_edge(g,3,6);
    g=add_edge(g,3,7);
    g=add_edge(g,6,7);


    //bfs is 01324

    display_graph(g);
    printf("\n\n\n");
    printf("BFS: \n");
    bfs_with_level(g,0);
    printf("\n\n\n");
    bfs(g,0);
    printf("\n\n\n");


    int * visited=init_visited(g);
    printf("DFS: \n");
    dfs_with_time(g,0,visited);
    show_table(g);
    printf("\n\n\n");
    visited=init_visited(g);
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