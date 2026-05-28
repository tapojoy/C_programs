#include "stdio.h"

void towers(int n, char from, char to, char via){
    if (n == 1){
        //base condition
        printf("move from %c to %c, i.e. <%c, %c>\n", from, to, from, to);
    }
    else{
        //recursion //decomposition and recomposition are simulatenously
        towers(n-1, from, via, to);
        printf("move from %c to %c, i.e. <%c, %c>\n", from, to, from, to);
        towers(n-1, via, to, from);
    }
}

int main() {
    int n;
    printf("Enter number of discs :: ");
    scanf("%d",&n);
    if (n<=0) {printf("invalid input of n, exiting!\n"); return 0;}
    towers(n, 'A', 'B', 'C');
    return 0;
}

