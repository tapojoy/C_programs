#include "stdio.h"
#include "string.h"

void verbose(int, int, int [], int);
void verbose2(int, int, int, int, int, int);

int main(){
    int n, i, j, k, num, count = 0, temp;
    int max, nextmax, pointer, num1, num2;
    int var1, var2;
    printf("\nEnter the number of numbers :: ");
    scanf("%d",&n);
    if (n<=0) {printf("invalid input for n, exiting!"); return 0;}
    
    int m = (2*n-1);
    int arr[m];
    memset(arr, 0, sizeof(arr));
    printf("n = %d, m = %d\n\n",n, m);
    
    printf("Enter the numbers :: \n");
    for(i = n; i<=m; i++){
        scanf("%d", &num);
        arr[i] = num;
    }
    verbose(i, m, arr, n);
        
    for(j=m, k=m; j > 0; j=j-2,k--){
        count++; if (arr[j]>arr[j-1]){
            arr[k-n] = arr[j];
        }
        else{
            arr[k-n] = arr[j-1];
        }
        verbose(i, m, arr, n);
    }

    printf("\n");

    max = arr[1];
    pointer = 1;
    pointer = pointer * 2;
    var1 = pointer; 
    num1 = arr[pointer];
    num2 = arr[pointer+1];
    
    count++; if(num1==max){
        temp = num2;
    }
    else{
        temp = num1;
        pointer = pointer + 1;
    }
    nextmax = temp;
    
    pointer = pointer * 2;
    verbose2(var1, num1, num2, temp, nextmax, pointer);
    
    printf("\nentering loop\n");
    
    while(pointer<=m) {
        var1 = pointer;
        num1 = arr[pointer];
        num2 = arr[pointer+1];
        
        count++; if(num1==max){
            temp = num2;
        }
        else{
            temp = num1;
            pointer = pointer + 1;
        }
        
        count++; if(temp>nextmax){
            nextmax = temp;
        }
        
        pointer = pointer * 2;
        verbose2(var1, num1, num2, temp, nextmax, pointer);
    }
    
    printf("exiting loop\n\n");
    
    printf("Maximum = %d\n", max);
    printf("2nd Max = %d\n", nextmax);
    printf("2(n-1)  = %d\n", 2*(n-1));
    printf("Count   = %d\n", count);
    printf("\n\n");
    return 0;
}

void verbose(int i, int m, int arr[], int n){
    printf("\n");
    printf("Array :: | "); for(i = 1 ; i <= m; i++){
        printf(" %d | ",arr[i]);
    }
    printf("\nIndex :: | "); for(i = 1 ; i <= m; i++){
        printf(" %d | ",i);
    }
    printf("\n");
}

void verbose2(int p, int n1, int n2, int t, int nmax, int np){
    printf("pointer = %d, ", p);
    printf("num1 = %d ", n1);
    printf("num2 = %d ", n2);
    printf("temp = %d ", t);
    printf("nextmax = %d, ", nmax);
    printf("next pointer = %d ", np);
    printf("\n");
}

