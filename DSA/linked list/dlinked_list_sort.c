#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* addNode(int data) {
    Node* p = malloc(sizeof(Node));
    p->data = data;
    p->next = p->prev = NULL;
    return p;
}

Node* createNode(Node* head, int data) {
    if (head == NULL) {
        return addNode(data);
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = addNode(data);
    temp->next->prev = temp;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* reverse(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev = NULL;
    Node* cur = head;
    Node* next = cur->next;
    while (cur != NULL) {
        cur->next = prev;
        cur->prev = next;
        prev = cur;
        cur = next;
        if (cur != NULL) {
            next = cur->next;
        }
    }
    return prev;
}

void swap(Node* i, Node* j) {
    int temp = i->data;
    i->data = j->data;
    j->data = temp;
}

Node* sort(Node* head) {
    if (head == NULL) return head;

    int swapped;
    Node* i;
    Node* j;

    // Bubble sort logic
    for (i = head; i != NULL; i = i->next) {
        swapped = 0;
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data < j->data) {
                swap(i, j);  // Swap only the data
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }

    return head;
}

int main() {
    Node* head = NULL;
    head = createNode(head, 191);
    head = createNode(head, 290);
    head = createNode(head, 921);
    head = createNode(head, 280);
    head = createNode(head, 980);
    head = createNode(head, 480);
    
    printf("Original list: ");
    printList(head);
    
    printf("Sorted list: ");
    head = sort(head);
    printList(head);

    printf("Reversed list: ");
    head = reverse(head);
    printList(head);
    
    return 0;
}