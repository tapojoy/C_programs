#include "stdio.h"

void verbose(int, int, int [], int);
void verbose2(int, int, int, int, int, int);
int get_max(int, int);

int main(){
    int n, m, i, num, count = 0, pointer, init_ptr;
    int max, nextmax, temp_max, num1, num2;
    printf("\nEnter the number of numbers :: ");
    scanf("%d",&n);
    if (n<=0) {printf("invalid input for n, exiting!"); return 0;}
    
    m = (2*n-1);
    int arr[m];
    //arr[0] = -1;
    printf("n = %d, m = %d\n\n",n, m);
    
    printf("Enter the numbers :: \n");
    for(i = n; i<=m; i++){
        scanf("%d", &num);
        arr[i] = num;
    }
    verbose(i, m, arr, n);
    
    for(i=m; i>0; i=i-2){
        /*
        count++; if (arr[i]>arr[i-1]){
            arr[i/2] = arr[i];
        }
        else{
            arr[i/2] = arr[i-1];
        }
        */
        count++;
        arr[i/2] = get_max(arr[i],arr[i-1]);
        verbose(i, m, arr, n);
    }

    printf("\n");

    max = arr[1];
    pointer = 1;
    pointer = pointer * 2;
    init_ptr = pointer; 
    num1 = arr[pointer];
    num2 = arr[pointer+1];
    
    count++; if(num1==max){
        temp_max = num2;
    }
    else{
        temp_max = num1;
        pointer = pointer + 1;
    }
    nextmax = temp_max;
    
    pointer = pointer * 2;
    verbose2(init_ptr, num1, num2, temp_max, nextmax, pointer);
    
    printf("\nentering loop\n");
    
    while(pointer<=m) {
        init_ptr = pointer;
        num1 = arr[pointer];
        num2 = arr[pointer+1];
        
        count++; if(num1==max){
            temp_max = num2;
        }
        else{
            temp_max = num1;
            pointer = pointer + 1;
        }
        
        count++; if(temp_max>nextmax){
            nextmax = temp_max;
        }
        
        pointer = pointer * 2;
        verbose2(init_ptr, num1, num2, temp_max, nextmax, pointer);
    }
    
    printf("exiting loop\n\n");
    
    printf("Maximum = %d\n", max);
    printf("2nd Max = %d\n", nextmax);
    //printf("2(n-1)  = %d\n", 2*(n-1));
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

int get_max(int a, int b){
    if (a>b) return a;
    else return b;
}

