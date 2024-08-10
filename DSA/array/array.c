#include <stdio.h>
#include <stdlib.h>
struct array
{
    int total_size , used_size;
    int *ptr;
};


void make_arr(struct array*  a, int tot , int use)
{
    a->total_size=tot;
    a->used_size=use;
    a->ptr=(int*)malloc(tot*sizeof(int));
}

void set (struct array* a)
{
    int temp=0;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter info %d: ",i);
        scanf("%d",&temp);
        a->ptr[i]=temp;
    }
    
}

void print (struct array* a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d",a->ptr[i]);
    }
    
}

void end(struct array *a)
{
    free(a);
}





int main(int argc, char const *argv[])
{
    struct array my_array;
    make_arr(&my_array,100,20);
    set(&my_array);
    print(&my_array);
    end(&my_array);
    return 0;
}
