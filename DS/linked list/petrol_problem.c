#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int petrol_at_station;
    int distance_to_next_node;
    struct node* next;
};

struct node* insert_at_end(struct node * head, int pet , int dist)
{
    struct node * new_end = malloc(sizeof(struct node));
    struct node * ptr =head;
    new_end->petrol_at_station=pet;
    new_end->distance_to_next_node=dist;

    while(ptr->next!= head)
    {
        ptr = ptr->next;
    }
    ptr->next=new_end;
    new_end->next=head;
    return head;
}

// all get insered at end anyways
void insert_all_pumps(struct node * head)
{
    int no=0;
    printf("Enter number of pumps: ");
    scanf("%d",&no);
    printf("\n\n");
    int temp_pet=0;
    int temp_dist=0;
    for (int i = 0; i < no; i++)
    {
        printf("Enter fuel you found at pump number %d: ",i+1);
        scanf("%d",&temp_pet);
        printf("\n");
        printf("Enter distance to next pump: ");
        scanf("%d",&temp_dist);
        printf("\n");
        head=insert_at_end(head,temp_pet,temp_dist);
    }
}

int length_of_cl(struct node *head)
{
    int length=0;
    struct node * ptr = head;
    do
    {
        length++;
        ptr = ptr->next;
    }
    while (ptr!=head);
    printf("\n\n");
    free(ptr);
    return length;
}

void check_for_fuel(struct node * head,struct node * ptr_current,int pump_no)
{
    int current_fuel=0;
    int distance_to_travel=0;
    struct node * ptr = ptr_current;
    do
    {
        current_fuel+=ptr->petrol_at_station;
        distance_to_travel+=ptr->distance_to_next_node;
        if (current_fuel-distance_to_travel<=0)
        {
            printf("Trip not possible for pump no %d",pump_no);
            free(ptr);
            return;
        }
        ptr=ptr->next;
        
    } while (ptr->next!=ptr_current);

    if (ptr->next==ptr_current && ptr->petrol_at_station-ptr->distance_to_next_node<=0)
    {
        printf("Trip possible: for pump no %d",pump_no);
        free(ptr);
    }
    else
    {
       printf("Trip not possible for pump no %d",pump_no);
        free(ptr);
        return; 
    }
    
    
}

void simulate (struct node * head)
{
    int pump_no=0;
    struct node * ptr=head;
    for (int i = 0; i < length_of_cl(head)-1; i++)
    {
        ptr=ptr->next;
        check_for_fuel(head,ptr,pump_no);
        pump_no++;
    }
    
    
}

void free_list(struct node* head)
{
    struct node * ptr = head;
    do
    {
        ptr=head;
        head = head->next;
        free(ptr);
    }
    while (ptr!=head);
    free(head);

}

int main(int argc, char const *argv[])
{
    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * intial_location = (struct node *)malloc(sizeof(struct node));
    head->next=intial_location;
    //to make circular
    printf("Enter fuel you found at 1st pump: ");
    scanf("%d",&intial_location->petrol_at_station);
    printf("\n");
    printf("Enter distance to next pump: ");
    scanf("%d",&intial_location->distance_to_next_node);
    printf("\n");
    intial_location->next=head;


    insert_all_pumps(head);
    simulate(head);
    free_list(head);
    return 0;
}
