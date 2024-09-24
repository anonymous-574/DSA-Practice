#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial
struct Node {
    int coeff;   // Coefficient
    int pow;     // Power (exponent)
    struct Node* next;
};

// Global variables
struct Node* start1 = NULL; // First polynomial
struct Node* temp1 = NULL;  // Temporary pointer for first polynomial
struct Node* start2 = NULL; // Second polynomial
struct Node* temp2 = NULL;  // Temporary pointer for second polynomial
struct Node* start3 = NULL; // Resultant polynomial
struct Node* temp3 = NULL;  // Temporary pointer for resultant polynomial

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new term into the polynomial
void insert(struct Node** start, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*start == NULL) {
        *start = newNode;
    } else {
        struct Node* temp = *start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the polynomial
void display(struct Node* start) {
    struct Node* temp = start;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->pow);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
void addPolynomials() {
    temp1 = start1;
    temp2 = start2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->pow == temp2->pow) {
            // Same power: Add coefficients
            insert(&start3, temp1->coeff + temp2->coeff, temp1->pow);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->pow > temp2->pow) {
            // Power of temp1 is greater: Copy temp1 to result
            insert(&start3, temp1->coeff, temp1->pow);
            temp1 = temp1->next;
        } else {
            // Power of temp2 is greater: Copy temp2 to result
            insert(&start3, temp2->coeff, temp2->pow);
            temp2 = temp2->next;
        }
    }

    // Copy remaining terms of temp1 (if any)
    while (temp1 != NULL) {
        insert(&start3, temp1->coeff, temp1->pow);
        temp1 = temp1->next;
    }

    // Copy remaining terms of temp2 (if any)
    while (temp2 != NULL) {
        insert(&start3, temp2->coeff, temp2->pow);
        temp2 = temp2->next;
    }
}

int main() {
    // Create first polynomial: 3x^3 + 5x^2 + 6
    insert(&start1, 3, 3);
    insert(&start1, 5, 2);
    insert(&start1, 6, 0);
    printf("Polynomial 1: ");
    display(start1);

    // Create second polynomial: 4x^3 + 2x^1 + 3
    insert(&start2, 4, 3);
    insert(&start2, 2, 1);
    insert(&start2, 3, 0);
    printf("Polynomial 2: ");
    display(start2);

    // Add the two polynomials
    addPolynomials();
    
    // Display the result
    printf("Resultant Polynomial after addition: ");
    display(start3);

    return 0;
}