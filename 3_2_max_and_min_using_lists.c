#include "stdio.h"

void verbose(char info[], int i, int count, int max, int min){
    printf("info = %s, ",info);
    printf("iter= %d, ",i);
    printf("count= %d, ", count);
    printf("c_max = %d, ", max);
    printf("c_min = %d\n", min);
}

int main(){
    int i, n, num1, num2, count = 0, max, min;
    int extra;
    int odd = 0;
    
    printf("Enter the number of numbers :: "); scanf("%d",&n);
    if (n<=0) {printf("n is invalid, exiting!"); return 0;}
    if (n%2!=0) {
        printf("n = %d is odd\n",n);
        odd = 1;
    }
    else {
        printf("n = %d is even\n",n);
    }

    int k = n/2;
    int large[k], small[k];
    
    for(i=0; i<k; i++){
        printf("Enter the numbers :: \n");
        scanf("%d%d",&num1, &num2);
        printf("pair %d = [%d,%d]\n",i, num1, num2);
        count++; if (num1 > num2){
            large[i] = num1;
            small[i] = num2;
        }
        else {
            large[i] = num2;
            small[i] = num1;
        }
        verbose("1st loop",(i+1),count,large[i],small[i]);
    }
    if (odd == 1){
        printf("Enter the numbers :: \n");
        scanf("%d", &extra);
        printf("extra: %d (since n is odd) \n\n", extra);
    }
    
    max = large[0];
    for(i = 1; i < n/2; i++){
        count++; if(large[i]>max){
            max = large[i];
        }
        verbose("2nd loop", i, count, max, large[i-1]);
    }
    
    min = small[0];
    for(i = 1; i < n/2; i++){
        count++; if(small[i]<min){
            min = small[i];
        }
        verbose("3rd loop", i, count, small[i-1], min);
    }
    
    if(odd == 1){
        count++; if(extra>max) {max = extra;}
        else {count++; if(extra<min) min = extra;}
        verbose("after 3rd loop", 0 ,count,max,min);
    }
    
    printf("\nMax = %d, ", max);
    printf("Min = %d, ", min);
    printf("2(n-1) = %d, ", 2*(n-1));
    if(odd == 0){
        printf("3n/2-2 = %d, ", (((3*n)/2)-2));
    }
    else{
        if(odd == 1){
            printf("3(n-1)/2 = %d ", ((3*(n-1))/2) );
        }
    }
    printf("and count  = %d\n\n", count);
    return 0;
}

