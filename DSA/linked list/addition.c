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
struct Node* start2 = NULL; // Second polynomial
struct Node* start3 = NULL; // Resultant polynomial

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
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
    struct Node *temp1 = start1, *temp2 = start2, *temp3 = NULL;
    
    while (temp1 != NULL && temp2 != NULL) {
        struct Node* newNode;

        if (temp1->pow == temp2->pow) {
            // Same power: Add coefficients
            newNode = createNode(temp1->coeff + temp2->coeff, temp1->pow);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->pow > temp2->pow) {
            // Power of temp1 is greater: Copy temp1 to result
            newNode = createNode(temp1->coeff, temp1->pow);
            temp1 = temp1->next;
        } else {
            // Power of temp2 is greater: Copy temp2 to result
            newNode = createNode(temp2->coeff, temp2->pow);
            temp2 = temp2->next;
        }

        // Append the new node to the result list
        if (start3 == NULL) {
            start3 = newNode;  // First node
            temp3 = start3;
        } else {
            temp3->next = newNode;  // Append to the end
            temp3 = newNode;
        }
    }

    // Copy remaining terms of temp1 (if any)
    while (temp1 != NULL) {
        struct Node* newNode = createNode(temp1->coeff, temp1->pow);
        temp3->next = newNode;
        temp3 = newNode;
        temp1 = temp1->next;
    }

    // Copy remaining terms of temp2 (if any)
    while (temp2 != NULL) {
        struct Node* newNode = createNode(temp2->coeff, temp2->pow);
        temp3->next = newNode;
        temp3 = newNode;
        temp2 = temp2->next;
    }
}

int main() {
    // Manually create first polynomial: 3x^3 + 5x^2 + 6
    start1 = createNode(3, 3);
    start1->next = createNode(5, 2);
    start1->next->next = createNode(6, 0);

    // Manually create second polynomial: 4x^3 + 2x^1 + 3
    start2 = createNode(4, 3);
    start2->next = createNode(2, 1);
    start2->next->next = createNode(3, 0);

    // Display both polynomials
    printf("Polynomial 1: ");
    display(start1);
    printf("Polynomial 2: ");
    display(start2);

    // Add the two polynomials
    addPolynomials();

    // Display the result
    printf("Resultant Polynomial after addition: ");
    display(start3);

    return 0;
}