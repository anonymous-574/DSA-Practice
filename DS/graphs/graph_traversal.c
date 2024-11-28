#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node* next;
};



struct queue {
    struct node* f;
    struct node* r;
    int maxSize;
    int size;
};

struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    return n;
}

int isEmpty(struct queue* q) {
    if (q->f == NULL) 
        return 1;
    return 0;
}

int isFull(){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        free(n);
        return 1;

    }
    free(n);
    return 0;
}


void enqueue(struct queue* q, int data) {

    if (isFull(q)) {
        printf("Queue Overflow\n");
    }
    else {
        struct node* n = createNode(data);
        if (isEmpty(q)) {
            q->f = q->r = n;
        }

        else {
            q->r->next = n;
            q->r = n;
        }
        q->size++;
    }
}



int dequeue(struct queue* q) {

    if (!isEmpty(q)) {
        struct node* ptr = q->f;
        q->f = q->f->next;
        int val = ptr->data;
        free(ptr);
        q->size--;
        return val;
    }
    else {
        printf("Queue Underflow\n");
        return -1;
    }

}



struct Graph {

    int numVertices;

    int* visitArr;

    struct node** adjList;

};



struct Graph* createGraph(int num) {

    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    graph->numVertices = num;

    graph->visitArr = (int*)malloc(num * sizeof(int));

    graph->adjList = (struct node**)malloc(num * sizeof(struct node*));



    for (int i = 0; i < graph->numVertices; i++) {

        graph->visitArr[i] = 0;

        graph->adjList[i] = NULL;

    }

    return graph;

}



void addEdge(struct Graph* graph, int src, int dest) {

    struct node* newNode = createNode(dest);

    newNode->next = graph->adjList[src];

    graph->adjList[src] = newNode;



    newNode = createNode(src);

    newNode->next = graph->adjList[dest];

    graph->adjList[dest] = newNode;

}



void BFS(struct Graph* graph, int startVertex) {
    struct queue* exploreQueue = (struct queue*)malloc(graph->numVertices*sizeof(struct queue));
    exploreQueue->f = exploreQueue->r = NULL;
    graph->visitArr[startVertex] = 1;
    enqueue(exploreQueue, startVertex);
    int vertex;
    while (!isEmpty(exploreQueue)) {
        vertex = dequeue(exploreQueue);
        printf("%d ", vertex);
        struct node* ptr = graph->adjList[vertex];

        while (ptr != NULL) {
            if (graph->visitArr[ptr->data] == 0) {
                graph->visitArr[ptr->data] = 1;
                enqueue(exploreQueue, ptr->data);
            }

            ptr = ptr->next;

        }

    }

}

/*
void DFS (struct Graph * graph, int startVertex) {
    printf("%d", startVertex);

    for (int i = 0; i < graph->numVertices; i++)
    {
        struct node * ptr = graph->adjList[i];

        while (ptr != NULL) {
            if (graph->visitArr[ptr->data] == 1) {
                DFS(graph->, graph->visitArr[ptr->data]);
            }
            ptr = ptr->next;
        }
    }
}
*/



int main() {
    struct Graph* graph = createGraph(11);
    addEdge(graph, 0, 10);
    addEdge(graph, 0, 7);
    addEdge(graph, 0, 5);
    addEdge(graph, 7, 5);
    addEdge(graph, 7, 2);
    addEdge(graph, 10, 5);
    addEdge(graph, 2, 5);
    addEdge(graph, 5, 1);
    addEdge(graph, 1, 4);
    BFS(graph, 0);
    printf("\n\n\n\n\n");
    DFS(graph,0);
    return 0;

}

