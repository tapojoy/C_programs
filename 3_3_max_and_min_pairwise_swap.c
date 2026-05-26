#include "stdio.h"

void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

int main(){
    int n, m, num1, num2, max, min;
    
    printf("Enter the number of numbers :: "); scanf("%d",&n);
    printf("n = %d\n",n);
    if (n<=0) {printf("invalid input for n, exiting!\n"); return 0;}
    
    printf("\nEnter the numbers :: \n");
    scanf("%d",&num1);

    m = n;
    int i = 0, count = 0, odd = 0;

    if (n%2==0) {
        scanf("%d",&num2);
        count++; if(num1<num2) {
            swap(&num1,&num2);
        }
        max = num1;
        min = num2;
        printf("pair %d = [%d,%d] ", i, num1, num2);
        printf("c_max = %d, c_min = %d\n", max, min);
        i++;
    }
    else {
        odd = 1;
        max = num1;
        min = max;
        printf("extra = [%d] ", num1);
        printf("c_max = %d, c_min = %d\n", max, min);
        m--;
    }

    for(; i<m/2; i++) {
        scanf("%d%d",&num1, &num2);
        count++; if (num1 < num2) {
            swap(&num1, &num2);
        }
        count++; if (num1>max) {
            max = num1;
        }
        count++; if (num2<min) {
            min = num2;
        }
        printf("pair %d = [%d,%d] ",i, num1, num2);
        printf("c_max = %d, c_min = %d\n", max, min);
    }
    
    printf("\nMax = %d, ", max);
    printf("Min = %d, ", min);
    printf("2(n-1) = %d, ", 2*(n-1) );
    if(odd == 0){
        printf("3n/2-2 = %d, ", (((3*n)/2)-2) );
    }
    else{
        if(odd == 1){
            printf("3(n-1)/2 = %d ", ((3*(n-1))/2) );
        }
    }
    printf("and count = %d\n\n", count);
    return 0;
}

