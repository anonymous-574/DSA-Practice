#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
    int no_of_edges;
    int no_of_vertices;
    //array of adjacency graph
    int ** arr;
}graph;



int main(int argc, char const *argv[])
{
    graph * g = (graph *) malloc(sizeof(graph));
    g->no_of_edges=5;
    g->no_of_vertices=4;

    // make 2d array
    g->arr= (int **) malloc( sizeof(int)*(g->no_of_vertices*g->no_of_vertices));

    //initialise
    for (int i = 0; i < g->no_of_vertices; i++)
    {
        for (int j = 0; i < g->no_of_vertices; j++)
        {
            g->arr[i][j]=0;
        }
    }

    //take edges
    int r,c;
    for (int i = 0; i < g->no_of_edges; i++)
    {
        printf("Enter Edges data for edge: %d \n", i+1);
        printf("Enter Vertex 1: \n");
        scanf("%d", &r);
        printf("Enter Vertex 2: \n");
        scanf("%d", &c);
        g->arr[r][c]=1;
        g->arr[c][r]=1;
    }
    
    
    return 0;
}
