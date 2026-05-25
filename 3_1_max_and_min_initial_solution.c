#include "stdio.h"

void verbose(int i, int num, int count, int max, int min){
    printf("iter = %d, ",i);
    printf("num = %d, ", num);
    printf("count= %d, ", count);
    printf("c_max = %d, ", max);
    printf("c_min = %d\n\n", min);
}

int main(){
    int i = 0, n, num, count = 0, max, min;
    printf("Enter the number of numbers :: "); scanf("%d",&n);
    printf("n = %d\n",n);
    if (n<=0) {printf("invalid value for n, exiting!\n"); return 0;}
    printf("Enter the numbers :: \n\n"); scanf("%d",&num);
    max = num; min = max;
    verbose(i, num, count, max, min); i++;
    for(; i<n; i++){
        scanf("%d",&num);
        count++; if (num > max){
            max = num;
        }
        else{
            count++; if (num < min){
                min = num;
            }
        }
        verbose(i, num, count, max, min);
    }
    printf("\nMax = %d, ", max);
    printf("Min = %d, ", min);
    printf("count = %d ", count);
    printf("and 2(n-1) = %d\n\n", 2*(n-1));
    return 0;
}

