#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct hash
{
    int * arr1;
    int size;
}hash;

typedef struct hash_main
{
    hash ** arr;
    int size;
}hash_main;

int hash_fn (hash_main * h ,int key)
{
    return key%h->size;
}

int hash_fn2 (hash * h ,int key)
{
    return key%h->size;
}

void insert_lin(hash * h, int key)
{
    int rem =hash_fn2(h,key);
    if (h->arr1[rem]==-1)
    {
        h->arr1[rem]=key;
    }
    else 
    {
        //apply probing
        while (h->arr1[rem]!=-1)
        {
            rem= (++rem)%h->size;            
        }
        h->arr1[rem]=key;
    }   
}

void insert(hash_main * h, int key)
{
    int rem =hash_fn(h,key);
    insert_lin(h->arr[rem],key);
}

void print_inception(hash_main *h)
{
    for (int i = 0; i < h->size; i++)
    {
        for (int j = 0; j < h->arr[i]->size; j++)
        {
           printf("%d ",h->arr[i]->arr1[j]);   
        }
        printf("\n");  
    }
}

int main(int argc, char const *argv[])
{
    // Step 1: Allocate memory for hash_main
    hash_main *main_hash = malloc(sizeof(hash_main));
    
    
    // Step 2: Set size and allocate memory for the array of hash pointers
    main_hash->size = 10;
    main_hash->arr = malloc(main_hash->size * sizeof(hash *));
    

    // Step 3: Allocate memory for each hash in the array
    for (int i = 0; i < main_hash->size; i++) {
        main_hash->arr[i] = malloc(sizeof(hash));
        
        // Step 4: Allocate memory for arr1 in each hash
        main_hash->arr[i]->size = 19;  // Set size for arr1
        main_hash->arr[i]->arr1 = malloc(main_hash->arr[i]->size * sizeof(int));
        
    }

    for (int i = 0; i < main_hash->size; i++)
    {
        for (int j = 0; j < main_hash->arr[i]->size; j++)
        {
            main_hash->arr[i]->arr1[j]=-1;
        }  
    }

    print_inception(main_hash);
    printf("\n\n");

    //add logic 
    insert(main_hash,55);
    //insert(main_hash,65);

    print_inception(main_hash);
    printf("\n\n");

    for (int i = 0; i < main_hash->size; i++) {
        free(main_hash->arr[i]->arr1); 
        free(main_hash->arr[i]); 
    }
    free(main_hash->arr); 
    free(main_hash); 
    

    return 0;
}
