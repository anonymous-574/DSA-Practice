// 4.	Create a data structure kQueues that represents ‘k’ queues. Implementation of kQueues should use only one array, 
// i.e., k queues should use the same array for storing elements. Following functions must be supported by kQueues.
// a.	enqueue(int x, int qn):  adds x to queue number ‘qn’ where qn is from 0 to k-1.
// b.	dequeue(int qn): deletes an element from queue number ‘qn’ where qn is from 0 to k-1.
// c.	displayq( int q ): displays all the elements of the q specified.
// d.	displayAll( ):displays the contents of all the queues

#include <stdio.h>
#include <stdlib.h>
#define n 20
#define k 4

typedef struct Queue{
    int arr[n];
    int front[k];
    int rear[k];
}kQueue;

void initQueues(kQueue * q){
    int front;
    for (int i = 0; i < n; i++)
    {
        q->arr[i]=-1;
    }
    
    printf("Initialize pls\n");
    for(int i =0;i<k;i++){
        printf("%d front:",i+1);
        scanf("%d",&front);
        q->front[i] = front;
        q->rear[i] = front-1;
    }
}

void enqueue(kQueue * q,int x,int qn){
    if(qn == k-1){
        if(q->rear[qn]==n-1){
            printf("Cannot add as limit is reached\n");
            return;
        }
        else{
            q->rear[qn]+=1;
            q->arr[q->rear[qn]] = x;
        }
    }
    else if((q->rear[qn])+1 < q->front[qn+1]){
        q->rear[qn]+=1;
        q->arr[q->rear[qn]] = x;
    }
    else{
        printf("One ahead is blocking way %d\n",(qn+1));
    }    
}

void dequeue(kQueue * q,int qn){
    if(q->rear[qn]<q->front[qn]){
        printf("Queue Empty %d\n",qn);
    }
    else{
        q->front[qn]+=1;
    }    
}

void displayq(kQueue q,int qn){
    if(q.rear[qn] <q.front[qn]){
        printf("Queue Empty\n");
    }
    else{
        while(q.rear[qn] >=q.front[qn]){
            printf("%d ",q.arr[q.front[qn]]);
            q.front[qn]+=1;
        }
        printf("\n");
    }
}

void displayAll(kQueue q){
    for(int i=0;i<n;i++){
        printf("%d ",q.arr[i]);
    }
    printf("\n");
}

int main() {
    kQueue q;
    
    initQueues(&q);

    int choice, x, qn;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Display All Queues\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter queue number (0 to %d): ", k - 1);
                scanf("%d", &qn);
                if (qn < 0 || qn >= k) {
                    printf("Invalid queue number.\n");
                    break;
                }
                printf("Enter element to enqueue: ");
                scanf("%d", &x);
                enqueue(&q, x, qn);
                break;
            case 2:
                printf("Enter queue number (0 to %d): ", k - 1);
                scanf("%d", &qn);
                if (qn < 0 || qn >= k) {
                    printf("Invalid queue number.\n");
                    break;
                }
                dequeue(&q, qn);
                break;
            case 3:
                printf("Enter queue number (0 to %d): ", k - 1);
                scanf("%d", &qn);
                if (qn < 0 || qn >= k) {
                    printf("Invalid queue number.\n");
                    break;
                }
                displayq(q, qn);
                break;
            case 4:
                displayAll(q);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}