#include "stdio.h"

int fibo(int n){
    int x, y, val;
    if (n <= 0) {
        // base condition
        val = 0;
    }
    else {
        if (n == 1) {
            // base condition
            val = 1;
        }
        else {
            //recursive condition
            //decompose
            x = fibo(n-1);
            y = fibo(n-2);
            //recompose
            val = x + y;
        }
    }
    return val;
}

int main(){
    int n;
    printf("Enter a number, n =  ");
    scanf("%d",&n);
    if (n < 0) {printf("invalid input for n, exiting!\n\n"); return 0;}
    printf("\nfibonacci(%d) = %d\n\n",n,fibo(n));
    return 0;
}

