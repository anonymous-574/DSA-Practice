#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    
    int no;
    printf("Enter number: ");
    scanf("%d" , &no);
    int ans[4];

    int i=0;
    while (no >0)
    {
        ans[i]= (no%2);
        no=no/2;
        i++;
    }
    int size = sizeof(ans) / sizeof(ans[0]);
    
    
    int reversedArr[size];
    for (int i = 0; i < size; i++) {
        reversedArr[i] = ans[size - i - 1];
    }

    // Print reversed array
    printf("Binary number: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", reversedArr[i]);
    }
    

    return 0;
}
