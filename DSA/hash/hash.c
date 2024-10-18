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
    if (h->status[rem]=='E')
    {
        h->arr[rem]=key;
        h->status[rem]='F';
    }
    else 
    {
        //apply probing
        while (h->status[rem]!='E')
        {
            rem= (++rem)%h->size;            
        }
        h->arr[rem]=key;
        h->status[rem]='F';
    }    
}

void insert_quad(hash * h, int key)
{
    int rem =hash_fn(h,key);

    if (h->status[rem]=='E')
    {
        h->arr[rem]=key;
        h->status[rem]='F';
    }
    else 
    {
        int temp=1;
        while (h->status[rem]!='E')
        {
        rem=(rem + (temp*temp))%h->size;
        temp++;
        }
        h->arr[rem]=key;
        h->status[rem]='F';
    }    
}

int hash_fn1 (hash *h , int key)
{
    return 5- (5*(key%h->size));
}

void insert_doub(hash * h, int key)
{
    int rem =hash_fn(h,key);
    int rem2 = hash_fn1(h,key);

    if (h->status[rem]=='E')
    {
        h->arr[rem]=key;
        h->status[rem]='F';
    }
    else 
    {
        //apply probing
        int temp=0;
        while (h->status[rem]!='E')
        {
            rem= (rem + temp*rem2) %h->size;
            temp++; 
        }
        h->arr[rem]=key;
        h->status[rem]='F';
    }    
}


void search_lin(hash * h , int key)
{
    int rem =hash_fn(h,key);

    if (h->arr[rem]==key && h->status[rem]=='F')
    {
        printf("Found %d \n",key);
    }
    else if (h->status[rem]=='D' || h->status[rem]=='F')
    {
        while ( h->status[rem]!='F' && h->arr[rem]!=key)
        {
            rem= (++rem)%h->size;
        }
        printf("Found %d after probe \n",key);
    }
    else
    {
        printf("Key not found \n");
    }
}



/*

GPTTT
void search_lin(hash * h , int key)
{
    int rem =hash_fn(h,key);

    if (h->arr[rem]==key && h->status[rem]=='F')
    {
        printf("Found %d \n",key);
    }
    else if (h->status[rem]=='D' || h->status[rem]=='F')
    {
        while ( h->status[rem]!='F' && h->arr[rem]!=key)
        {
            rem= (++rem)%h->size;
        }
        printf("Found %d after probe \n",key);
    }
    else
    {
        printf("Key not found \n");
    }
}
*/

void search_quad(hash * h , int key)
{
    int rem =hash_fn(h,key);
    

    if (h->arr[rem]==key && h->status[rem]=='F')
    {
        printf("Found %d \n",key);
    }
    else if (h->status[rem]=='D' || h->status[rem]=='F')
    {
        int temp=1;
        while (h->status[rem]!='E' && h->arr[rem]!=key)
        {
        rem=(rem + (temp*temp))%h->size;
        temp++;
        }
        printf("Found %d after probe \n",key);
    }
    else
    {
        printf("Key not found \n");
    }
}

void search_doub(hash * h , int key)
{
    int rem =hash_fn(h,key);
    int rem2 = hash_fn1(h,key);

    if (h->arr[rem]==key && h->status[rem]=='F')
    {
        printf("Found %d \n",key);
    }
    else if (h->status[rem]=='D' || h->status[rem]=='F')
    {
        int temp=0;
        while (h->status[rem]!='E'&& h->arr[rem]!=key)
        {
            rem= (rem + temp*rem2) %h->size;
            temp++; 
        }
        printf("Found %d after probe \n",key);
    }
    else
    {
        printf("Key not found \n");
    }
}



void delete_lin(hash* h , int key)
{
    int rem =hash_fn(h,key);

    if (h->arr[rem]==key && h->status[rem]=='F')
    {
        h->status[rem]='D';
    }
    else if (h->status[rem]=='D' || h->status[rem]=='F')
    {
        while (h->status[rem]!='F' && h->arr[rem]!=key)
        {
            rem= (++rem)%h->size;
        }
        h->status[rem]='D';
    }
    else
    {
        printf("Key not found \n");
    }
}


/*
GPT
void delete_lin(hash* h, int key) {
    int rem = hash_fn(h, key);
    int original_rem = rem; // To track the original index for looping

    // Check if the key is at the hashed position
    if (h->status[rem] == 'F' && h->arr[rem] == key) {
        h->status[rem] = 'D'; // Mark as deleted
        return;
    }

    // Search for the key in the table
    while (h->status[rem] != 'F') {
        if (h->status[rem] == 'F') {
            break; // Stop if we find an empty slot
        }
        if (h->arr[rem] == key) {
            h->status[rem] = 'D'; // Mark as deleted
            return;
        }
        rem = (rem + 1) % h->size; // Move to the next index

        // Check for wrap around to avoid infinite loop
        if (rem == original_rem) {
            break; // We've looped back to the start
        }
    }

    printf("Key not found\n");
}
*/


void delete_quad(hash* h , int key)
{
    int rem =hash_fn(h,key);
    

    if (h->arr[rem]==key && h->status[rem]=='F')
    {
        h->status[rem]='D';
    }
    else if (h->status[rem]=='D' || h->status[rem]=='F')
    {
        int temp=1;
        while (h->status[rem]!='E' && h->arr[rem]!=key)
        {
        rem=(rem + (temp*temp))%h->size;
        temp++;
        }
        h->status[rem]='D';
    }
    else
    {
        printf("Key not found \n");
    }
}

void delete_doub(hash* h , int key)
{
    int rem =hash_fn(h,key);
    int rem2 = hash_fn1(h,key);

    if (h->arr[rem]==key && h->status[rem]=='F')
    {
        h->status[rem]='D';
    }
    else if (h->status[rem]=='D' || h->status[rem]=='F')
    {
        int temp=0;
        while (h->status[rem]!='E'&& h->arr[rem]!=key)
        {
            rem= (rem + temp*rem2) %h->size;
            temp++; 
        }
        h->status[rem]='D';
    }
    else
    {
        printf("Key not found \n");
    }
}

void print_hash(hash* h)
{
    for (int i = 0; i < h->size; i++)
    {
        printf("%d , %d \n",i , h->arr[i]);
    }   
}

int main(int argc, char const *argv[])
{
    hash * h = (hash * ) malloc(sizeof(hash));
    int hash_size=10;
    h->size=hash_size;
    h->arr=(int *)malloc(h->size *sizeof(int));
    h->status=(char *)malloc(h->size *sizeof(char));
    for (int i = 0; i < h->size; i++)
    {
        h->status[i]='E';
        h->arr[i]=-1;
    }
    
    

    //insert_lin(h,99);
    //insert_lin(h,15);
    //insert_lin(h,10);
    //insert_lin(h,3);
    //insert_lin(h,33);
    //insert_lin(h,43);
    //print_hash(h);
    //search_lin(h,43);
    //search_lin(h,43);

    //insert_quad(h,99);
    //insert_quad(h,15);
    //insert_quad(h,10);
    //insert_quad(h,3);
    //insert_quad(h,33);
    //print_hash(h);
    //search_quad(h,33)

    insert_doub(h,99);
    insert_doub(h,15);
    insert_doub(h,10);
    insert_doub(h,3);
    insert_doub(h,33);
    print_hash(h);
    search_doub(h,33);



    free(h->arr);
    free(h->status);
    free(h);
    return 0;
}
