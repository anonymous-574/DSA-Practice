#include <stdio.h>
int a[11]; 
int topA = 0; 
int topB = 10; 

void pushA(int val) {
    if (topA < topB) { 
        a[topA++] = val; 
    } 
    else {
        printf("Stack A is full\n");
    }
}
void pushB(int val) {
    if (topA < topB) { 
        a[topB--] = val; 
    } 
    else {
        printf("Stack B is full\n");
    }
}
int popA()
{
    if(topA==0){
        printf("Error");
        return 0;
    }
    a[topA]=0;
    return a[--topA];
}
int popB()
{
    if(topB==10){
        printf("Error");
        return 0;
    }
    a[topB]=0;
    return a[++topB];
}
void printArr() {
    printf("Current stack contents:\n");
    for (int i = 0; i < 11; i++) {
        printf("Index %d: %d\n", i, a[i]);
    }
    printf("Top A: %d, Top B: %d\n", topA, topB);
}
int main() {
    printf("%d\n", topB);
    pushA(2);
    pushA(3);
    printArr();
    pushA(2);
    pushA(4);
    printArr();
    printf("%d",popA());
    printArr();
    pushA(2);
    pushA(2);
    pushB(9);
    pushB(4);
    printf("%d",popB());
    printArr();
    pushB(9);
    pushB(19);
    printArr();
    printf("%d",popA());
    pushB(9);
    printArr();
    return 0;
}