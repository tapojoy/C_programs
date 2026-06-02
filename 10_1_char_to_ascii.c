#include "stdio.h"
//#include "stdlib.h"

int main() {
    char c;
    int n, i=0;
    printf("Enter the number of characters :: ");
    scanf(" %d", &n); //fflush(stdin); //space before %d worked
    do {
        printf("\nEnter the character :: ");
        scanf(" %c", &c); //fflush(stdin); //space before %c worked
        i++;
        printf("ASCII of %c is %d \n", c, c);
        if (c >= 'A' && c <= 'Z'){
            printf("Lower Case of %c = %c \n", c, c + ('a' - 'A'));
        }
    } while (i<n);
}

