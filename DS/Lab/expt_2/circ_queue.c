#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct circular_queue
{
    int * arr;
    int f,r,size;
};

bool is_full(struct circular_queue * q)
{
    if ((q->r+1)%q->size==q->f)
    {
        return true;
    }
    return false;
}

bool is_empty(struct circular_queue * q)
{
    if (q->f==q->r)
    {
        return true;
    }
    return false;
}

void enqueue(struct circular_queue * q, int data)
{
    if (is_full(q))
    {
        printf("FAIL\n");
        return;
    }

    q->r=(q->r+1)%q->size;
    q->arr[q->r]=data;
    return;
}

int dequeue(struct circular_queue * q)
{
    int num=0;
    if (is_empty(q))
    {
        printf("EMPTY\n");
        return -1;
    }
    q->f=(q->f+1)%q->size;
    num = q->arr[q->f];
    q->arr[q->f]=0;
    return num;
}


void display(struct circular_queue * q)
{
    printf("Queue is: \n");
    for (int i = q->f+1; i != q->r; i=(i+1)%q->size)
    {
        printf("%d\n",q->arr[i]);
    }
    printf("%d",q->arr[q->r]);
    printf("\n\n");

}


void take_input(struct circular_queue * q)
{
    int choice=0;
    int d=0;
    printf("Enter 1 to enqueue\n 2 to dequeue\n 3 to print\n 0 to quit\n\n");

    while (true)
    {
        printf("Enter Choice: ");
        scanf("%d",&choice);
        printf("\n\n");
     if (choice==0)
     {
        printf("Goodbye\n");
        return;
     }
        

    switch (choice)
    {
    case 1:
        {
            printf("Enter number to enqueue: ");
            scanf("%d",&d);
            printf("\n");
            enqueue(q,d);
            break;
        }
    case 2:
        {
            d=dequeue(q);
            printf("Dequeue is: %d",d);
            printf("\n");
            break;
        }
    case 3:
        {
            display(q);
            break;
        }
    
    default:
    {
        printf("USER IS AN IDIOT");
        break;
    }
        
    }
    }
}

int main(int argc, char const *argv[])
{
    int s;
    printf("Enter size of queue: ");
    scanf("%d",&s);
    printf("\n\n ");

    struct circular_queue * q = (struct circular_queue *) malloc(sizeof(struct circular_queue));
    q->arr=(int *)malloc(sizeof(int) * s);
    q->f=0;
    q->r=0;
    q->size=s;
    int deq =0;
    take_input(q);


    return 0;
}
