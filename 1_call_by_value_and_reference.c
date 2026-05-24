#include "stdio.h"

int call_by_value_sum(int a1, int b1){
    return (a1 + b1);
}

void call_by_reference_sum(int *a2, int *b2, int *c2){
    *c2 = *a2 + *b2;
}

int main(){
    int a,b,c;
    printf("Enter a : ");
    scanf("%d", &a);
    printf("Enter b : ");
    scanf("%d", &b);
    printf("a = %d, b = %d\n", a, b);
    call_by_reference_sum(&a, &b, &c);
    printf("Call by reference sum = %d\n", c);
    printf("    Call by value sum = %d\n", call_by_value_sum(a,b));
}

