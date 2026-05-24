#include "stdio.h"

void indent(int k) {
    for (int i = 1; i<k+1; i++) {printf("-");}
    printf("> ");
}

int factorial(int n, int k) {
    int m = 1;
    k++; //to "k"eep track of reccursive nest running currently
    indent(k); printf("rec  :: n = %d, m = ?\n", n);
    if (n == 1) {
        // this is a base condition
        indent(k); printf("base :: n = %d, m = %d\n", n, m);
        return m;
    }
    else {
        // this is a recursive condition
        m = n * factorial(n - 1, k);
        indent(k); printf("ret  :: n = %d, m = %d\n", n, m);
        return m;
    }
}

int main() {
    int n, k = 0;
    printf("Enter a natural number :: ");
    scanf("%d", &n); printf("\n");
    if (n<=0) {printf("Not a natural number\n");return 0;}
    printf("\nThe factorial of %d = %d\n", n, factorial(n, k));
    return 0;
}

