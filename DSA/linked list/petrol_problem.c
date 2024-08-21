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

int simulate (struct node * head)
{
    int initial_dist=0;
    int current_fuel=0;
    int remaining_dist=0;
    struct node * ptr=head;
    do
    {
        ptr=ptr->next;
        current_fuel+=ptr->petrol_at_station;
        remaining_dist+=ptr->distance_to_next_node;
        if (current_fuel-remaining_dist<0)
        {
            printf("TRIP NOT POSSIBLE");
        }
        
    } while (ptr->next!=head);
    return initial_dist;
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
    int initial_fuel=0;
    int initial_dist=0;
    printf("Enter Initial fuel: \n");
    scanf("%d",&initial_fuel);

    struct node * intial_location = (struct node *)malloc(sizeof(struct node));
    head->next=intial_location;
    intial_location->petrol_at_station=initial_fuel;
    //assuming
    intial_location->distance_to_next_node=0;

    //to make circular
    intial_location->next=head;


    insert_all_pumps(head);
    initial_fuel=simulate(head);
    printf("Initial dist required is: %d",initial_dist);
    free_list(head);
    return 0;
}
