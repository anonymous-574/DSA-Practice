#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node *next;
} Node;

Node* createNode(int coeff, int exp) {
    Node* p = malloc(sizeof(Node));
    p->coeff = coeff;
    p->exp = exp;
    p->next = NULL;
    return p;  // Always return the created node.
}

Node* addNode(Node* head, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (head == NULL) {
        return newNode;  // If list is empty, newNode becomes the head.
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;  // Add new node at the end of the list.
    return head;
}

void swap(Node* a, Node* b) {
    int coeff = a->coeff;
    int exp = a->exp;
    a->coeff = b->coeff;
    a->exp = b->exp;
    b->coeff = coeff;
    b->exp = exp;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {

        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void sort(Node* head) {
    for (Node* i = head; i != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->exp < j->exp) {
                swap(i, j);
            }
        }
    }
}

void removeDuplicates(Node* head) {
    sort(head);
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->exp == temp->next->exp) {
            temp->coeff += temp->next->coeff;
            temp->next = temp->next->next;
        } else {
            temp = temp->next;
        }
    }
}

Node* poly(Node* h1, Node* h2, int a) {
    if (a==0 && (h1 == NULL || h2 == NULL)) {
        return NULL;
    }

    Node* res = NULL;

    if (a == 0) {  // Addition
        Node* t1 = h1;
        while (t1 != NULL) {
            res = addNode(res, t1->coeff, t1->exp);
            t1 = t1->next;
        }
        Node* t2 = h2;
        while (t2 != NULL) {
            res = addNode(res, t2->coeff, t2->exp);
            t2 = t2->next;
        }
    } 



    
    else if (a == 1) {  // Multiplication
        for (Node* i = h1; i != NULL; i = i->next) {
            for (Node* j = h2; j != NULL; j = j->next) {
                int newCoeff = i->coeff * j->coeff;
                int newExp = i->exp + j->exp;
                if (newCoeff != 0) {
                    res = addNode(res, newCoeff, newExp);
                }
            }
        }
    }

    removeDuplicates(res);  // Remove duplicates after addition or multiplication
    return res;
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* h1 = NULL;
    Node* h2 = NULL;

    printf("List 1((-1)terminate)\n");
    for (int i = 1;; i++) {
        int coeff, exp;
        printf("Node %d(coeff, exp): ", i);
        scanf("%d %d", &coeff, &exp);
        if (coeff == -1 || exp == -1) {
            break;
        }
        h1 = addNode(h1, coeff, exp);
    }

    removeDuplicates(h1);  // Remove duplicates in h1
    printf("List 1 after removing duplicates: ");
    printList(h1);

    printf("List 2((-1)terminate)\n");
    for (int i = 1;; i++) {
        int coeff, exp;
        printf("Node %d(coeff, exp): ", i);
        scanf("%d %d", &coeff, &exp);
        if (coeff == -1 || exp == -1) {
            break;
        }
        h2 = addNode(h2, coeff, exp);
    }

    removeDuplicates(h2);  // Remove duplicates in h2
    printf("List 2 after removing duplicates: ");
    printList(h2);

    printf("Addition: ");
    Node* addResult = poly(h1, h2, 0);
    printList(addResult);

    printf("Multiplication: ");
    Node* mulResult = poly(h1, h2, 1);
    printList(mulResult);

    // Free the memory used by the lists
    freeList(h1);
    freeList(h2);
    freeList(addResult);
    freeList(mulResult);

    return 0;
}