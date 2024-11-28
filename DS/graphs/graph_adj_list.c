#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Stack{
    int top;
    Node* arr[N];
} Stack;

typedef struct Queue{
    int front, rear;
    Node* arr[N];
} Queue;

Node* createNode(int data){
    Node* p = malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    return p;
}

Node* addNode(Node* h, int data){
    if(h == NULL){
        return createNode(data);
    }
    Node* t = h;
    while(t->next != NULL){
        t = t->next;
    }
    t->next = createNode(data);
    return h;
}

void push(Stack* s, Node* data){
    s->arr[++(s->top)] = data;
}

void pop(Stack* s){
    (s->top)--;
}

void enqueue(Queue* q, Node* data){
    q->arr[++(q->rear)] = data;
}

void dequeue(Queue* q){
    (q->front)++;
}

void DFS(int v, Node* Graph[v]){
    int visited[v];
    for(int i = 0; i < v; i++){
        visited[i] = 0;
    }
    int start;
    printf("Start vertex: ");
    scanf("%d", &start);
    Stack s;
    s.top = -1;  
    push(&s, Graph[start]);
    visited[start] = 1;
    printf("%d", start);
    
    while(s.top != -1){
        Node* cur = s.arr[s.top];
        int flag = 0;
        for(Node* i = cur; i != NULL; i = i->next){
            if(!visited[i->data]){
                printf(" -> %d", i->data);
                push(&s, Graph[i->data]);
                visited[i->data] = 1;
                flag = 1;
                break;
            }
        }
        if(!flag){
            pop(&s);
        }
    }
}

void BFS(int v, Node* Graph[v]){
    int visited[v];
    for(int i = 0; i < v; i++){
        visited[i] = 0;
    }
    int start;
    printf("Start vertex: ");
    scanf("%d", &start);
    Queue q;
    q.front = 0;  
    q.rear = -1;  
    enqueue(&q, Graph[start]);
    visited[start] = 1;
    printf("%d", start);

    while(q.rear >= q.front){
        Node* cur = q.arr[q.front];
        dequeue(&q);
        while(cur != NULL){
            if(!visited[cur->data]){
                printf(" -> %d", cur->data);
                enqueue(&q, Graph[cur->data]);
                visited[cur->data] = 1;
            }
            cur = cur->next;
        }
    }
}

void printAdjList(int v, Node* arr[v]) {
    for(int i = 0; i < v; i++) {
        printf("Vertex %d: ", i);
        Node* cur = arr[i];
        while(cur != NULL) {
            printf("%d ", cur->data);
            cur = cur->next;
        }
        printf("-> NULL\n");
    }
}

int main(){
    int v;
    printf("Number of vertices: ");
    scanf("%d", &v);
    int e;
    Node* Graph[v];
    for(int i = 0; i < v; i++){
        Graph[i] = NULL;
    }
    printf("Number of edges: ");
    scanf("%d", &e);
    int start, end;
    for(int i = 0; i < e; i++){
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &start, &end);
        if(start >= 0 && start < v && end >= 0 && end < v) {
            Graph[start] = addNode(Graph[start], end);
        } else {
            printf("Invalid edge! Vertex indices must be between 0 and %d\n", v-1);
        }
    }
    
    printAdjList(v, Graph);
    
    printf("\nDFS Traversal:\n");
    DFS(v, Graph);
    
    printf("\n\nBFS Traversal:\n");
    BFS(v, Graph);
    
    return 0;
}