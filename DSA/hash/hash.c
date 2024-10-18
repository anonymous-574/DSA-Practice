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

int hash_fn1 (hash *h , int key)
{
    return 5- (5*(key%h->size));
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
        //apply probing
    }    
}

void insert_doub(hash * h, int key)
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
    }    
}

/*
void search (hash * h , int key)
{
    int rem =hash_fn(h,key);

    if (h->arr[rem]==key && h->status[rem]=='F')
    {
        printf("Found %d \n",key);
    }
    else
    {
        printf("Key not found \n");
    }
}
*/
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
    
    insert(h,99);
    insert(h,15);
    insert(h,10);
    insert(h,3);
    //search(h,10);
    print_hash(h);

    free(h->arr);
    free(h->status);
    free(h);
    return 0;
}
