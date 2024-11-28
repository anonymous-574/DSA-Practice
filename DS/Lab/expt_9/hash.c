#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct hash
{
    int * arr;
    int size;
    char * status;
}hash;

int hash_fn (hash * h ,int key)
{
    return key%h->size;
}


void insert_lin(hash * h, int key)
{
    int rem =hash_fn(h,key);
    printf("\n Applying Probe 0: (%d %% %d) %% %d = %d \n", key , h->size, h->size, rem);
    if (h->arr[rem]==key)
    {
        printf("You Have a Duplicate: No need to insert: \n");
        return;
    }
    if (h->status[rem]=='E')
    {
        h->arr[rem]=key;
        h->status[rem]='F';
    }
    else 
    {
        printf("A Collision has occured: \n");
        int probe_no=1;
        //apply probing
        while (h->status[rem]!='E')
        {
            if (h->arr[rem]==key)
            {
                printf("You Have a Duplicate: No need to insert: \n");
                return;
            }
            
            rem= (rem+probe_no)%h->size;     
            printf("Applying Probe %d: (%d+%d) %% %d = %d \n",probe_no, key,probe_no, h->size,  rem);  
            probe_no++;     
        }
        h->arr[rem]=key;
        h->status[rem]='F';
    } 
    printf("Element %d has been inserted at %d \n",key,rem);
}

void insert_quad(hash * h, int key)
{
    int ecount=0;
    int rem =hash_fn(h,key);
    if (h->arr[rem]==key)
    {
        printf("You Have a Duplicate: No need to insert: \n");
        return;
    }
    int orem=rem;
    printf("\n Applying Probe 0: (%d %% %d) %% %d = %d \n", key , h->size, h->size, rem);
    if (h->status[rem]=='E')
    {
        h->arr[rem]=key;
        h->status[rem]='F';
    }
    else 
    {
        printf("A Collision has occured: \n");
        int temp=1;
        while (h->status[rem]!='E'&& ecount<h->size*2)
        {
            if (h->arr[rem]==key)
            {
                printf("You Have a Duplicate: No need to insert: \n");
                return;
            }
        rem=(rem + (temp*temp))%h->size;
        printf("Applying Probe %d: ( %d + %d ) %% %d = %d \n",temp,orem, temp*temp , h->size,  rem); 
        temp++; 
        ecount++;
        }
        if (ecount>(h->size*2)-2)
        {
        printf("Element %d is going in infinite loop: ",key);
        return;
        }
        h->arr[rem]=key;
        h->status[rem]='F';
    }    
    
    printf("Element %d has been inserted at %d \n",key,rem);
}

int hash_fn1 (hash *h , int key)
{
    return 7- ((key%5));
}

void insert_doub(hash * h, int key)
{
    int rem =hash_fn(h,key);
    int orem=rem;
    int rem2 = hash_fn1(h,key);
    int ecount=0;
    if (h->arr[rem]==key)
    {
        printf("You Have a Duplicate: No need to insert: \n");
        return;
    }
    printf("\n Applying Probe 0: (%d %% %d) %% %d = %d \n", key , h->size, h->size, rem);

    if (h->status[rem]=='E')
    {
        h->arr[rem]=key;
        h->status[rem]='F';
    }
    else 
    {
        //apply probing
        printf("A Collision has occured: \n");
        int temp=1;
        while (h->status[rem]!='E' && ecount<h->size*2)
        {

            rem= (orem + temp*rem2) %h->size;
            if (h->arr[rem]==key)
            {
                printf("You Have a Duplicate: No need to insert: \n");
                return;
            }
            printf("Applying Probe %d: ( %d + %d*%d ) %% %d = %d \n",temp ,orem,temp,rem2,h->size,rem); 
            temp++; 
            ecount++;
        }

        if (ecount>(h->size*2)-2)
        {
        printf("Element %d is going in infinite loop: \n",key);
        return;
        }
        h->arr[rem]=key;
        h->status[rem]='F';
    }

    
    
    printf("Element %d has been inserted at %d \n",key,rem);
}


void print_hash(hash* h)
{
    printf("\n Index  Element Stored  Status \n");
    for (int i = 0; i < h->size; i++)
    {
        printf("%d  \t    %d\t \t %c \n",i , h->arr[i], h->status[i]);
    }   
}

void choice(hash * h)
{
    printf("Enter 1 to Do linear probing \nEnter 2 to do Quadratic probing: \nEnter 3 to do Double Hashing \n");
    int num=0;
    scanf("%d",&num);
    switch (num)
    {
    case 1:
    {
        printf("Welcome to linear probing \n Enter 1 to insert \n Enter 2 to print the entire Table \n Enter 0 to Exit \n");
        while (true)
        {
            int choice=0;
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
                printf("Enter number to insert: ");
                scanf("%d", &num);
                insert_lin(h,num);
                break;
            }
            case 2:
            {
                print_hash(h);
                break;
            }
            
            default:
            {
                printf("Error");
                break;
            }
            } 
        }
        
        break;
    }
    
    case 2:
    {
        printf("Welcome to Quadratic probing \n Enter 1 to insert \n Enter 2 to print the entire Table \n Enter 0 to Exit \n");
        while (true)
        {
            int choice=0;
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
                printf("Enter number to insert: ");
                scanf("%d", &num);
                insert_quad(h,num);
                printf("\n");
                break;
            }
            case 2:
            {
                print_hash(h);
                break;
            }
            
            default:
            {
                printf("Error");
                break;
            }
            } 
        }
        break;

    }
        case 3:
    {
        printf("Welcome to Double Hashing \n Enter 1 to insert \n Enter 2 to print the entire Table \n Enter 0 to Exit \n");
        while (true)
        {
            int choice=0;
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
                printf("Enter number to insert: ");
                scanf("%d", &num);
                insert_doub(h,num);
                printf("\n");
                break;
            }
            case 2:
            {
                print_hash(h);
                break;
            }
            
            default:
            {
                printf("Error");
                break;
            }
            } 
        }
        break;
        
    }

    default:
    {
        printf("Error");
        break;
    }

        
    }   

}

int main(int argc, char const *argv[])
{
    hash * h = (hash * ) malloc(sizeof(hash));

    printf("Enter size of the hash table: ");
    int hash_size=10;
    scanf("%d",&hash_size);
    
    h->size=hash_size;
    h->arr=(int *)malloc(h->size *sizeof(int));
    h->status=(char *)malloc(h->size *sizeof(char));
    for (int i = 0; i < h->size; i++)
    {
        h->status[i]='E';
        h->arr[i]=-1;
    }

    choice(h);

    free(h->arr);
    free(h->status);
    free(h);
    return 0;
}
