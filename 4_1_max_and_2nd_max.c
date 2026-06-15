#include "stdio.h"

void verbose(int, int, int [], int);
void verbose2(int, int, int, int, int, int);
void build_tournament(int [], int, int, int *);
int get_next_max(int [], int, int *, int);
int get_max(int, int);
int get_min(int, int);

int main(){
    int n, m, i, num, count = 0, max, nextmax;
    printf("\nEnter the number of numbers :: ");
    scanf("%d",&n);
    if (n<=0) {printf("invalid input for n, exiting!"); return 0;}
    
    m = (2*n-1);
    int arr[m];
    printf("n = %d, m = %d\n\n",n, m);
    
    printf("Enter the numbers :: \n");
    for(i = n; i<=m; i++){
        scanf("%d", &num);
        arr[i] = num;
    }
    verbose(i, m, arr, n);
        
    build_tournament(arr, m, n, &count);

    max = arr[1];
    nextmax = get_next_max(arr, max, &count, m);

    printf("Maximum = %d\n", max);
    printf("2nd Max = %d\n", nextmax);
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

void build_tournament(int arr[], int m, int n, int *count){
    for(int i=m; i>0; i=i-2){
        *count = *count + 1; arr[i/2] = get_max(arr[i],arr[i-1]);
        verbose(i, m, arr, n);
    }
    printf("\n");
}


int get_next_max(int arr[], int max, int *count, int m){
    int temp_count = 0;
    int pointer  = 2;
    int init_ptr = pointer; 
    int num1 = arr[pointer];
    int num2 = arr[pointer+1];
    
    temp_count++; if(num1==max){
        pointer = pointer * 2;
    }
    else{
        pointer = (pointer + 1) * 2;
    }
    int temp_max = get_min(num1,num2); 
    int nextmax = temp_max;
    
    verbose2(init_ptr, num1, num2, temp_max, nextmax, pointer);
    
    printf("\nentering loop\n");
    
    while(pointer<=m) {
        init_ptr = pointer;
        num1 = arr[pointer];
        num2 = arr[pointer+1];
        
        temp_count++; if(num1==max){
            temp_max = num2;
            pointer = pointer * 2;
        }
        else{
            temp_max = num1;
            pointer = (pointer + 1) * 2;
        }
        
        temp_count++; nextmax = get_max(temp_max,nextmax);
        verbose2(init_ptr, num1, num2, temp_max, nextmax, pointer);
    }
    
    printf("exiting loop\n\n");
    *count = temp_count + *count;
    return nextmax;
}

int get_max(int a, int b){
    if (a>b) return a;
    else return b;
}

int get_min(int a, int b){
    if (a>b) return b;
    else return a;
}

