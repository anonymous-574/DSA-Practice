#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node * next;
    int vertex;
}node;

typedef struct arr_holding_the_LL
{
    //number of vertices graph has
    int vertices_no;
    //just holds pointer to a node
    struct node * * adj_arr;
}graph;

// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create a graph
graph* createAGraph(int vertices) {
  graph* graph = malloc(sizeof(graph));
  graph->vertices_no = vertices;

  graph->adj_arr = malloc(vertices * sizeof(struct node*));

  int i;
  for (i = 0; i < vertices; i++)
    graph->adj_arr[i] = NULL;

  return graph;
}

// Add edge
void addEdge(graph* graph, int s, int d) {
  // Add edge from s to d
  struct node* newNode = createNode(d);
  newNode->next = graph->adj_arr[s];
  graph->adj_arr[s] = newNode;

  // Add edge from d to s
  newNode = createNode(s);
  newNode->next = graph->adj_arr[d];
  graph->adj_arr[d] = newNode;
}

// Print the graph
//bfs
void printGraph(graph* graph) {
  int v;
  for (v = 0; v < graph->vertices_no; v++) {
    struct node* temp = graph->adj_arr[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}


int main(int argc, char const *argv[])
{
    graph * g =createAGraph(10);
    addEdge(g,0,1);
    printGraph(g);
    return 0;
}
