#include "stdio.h"

int build_tournament(int [], int, int [], int, int *);
int insert_low(int [], int, int, int, int *);
int update_tournament(int [], int, int, int *);
int get_arr_min(int [], int, int, int *, int *);
int get_max(int, int);
int get_min(int, int);
void verbose(char [], int [], int);
void verbose2(char [], int, int, int, int, int);

int main(){
    int i, n, m, num, count = 0;
    int odd = 1;
    int max, min;
    int low;
    printf("\nEnter the number of numbers :: ");
    scanf("%d",&n);
    
    m = (2*n-1);
    int min_m = (n+1)/2;
    int arr[m];
    int sorted[n];
    int min_arr[min_m];
    printf("n = %d, m = %d\n\n",n, m);
    
    printf("Enter the numbers :: \n");
    for(i = n; i<=m; i++){
        scanf("%d", &num);
        arr[i] = num;
    }
    verbose("input_array", arr, m);

    max = build_tournament(arr, m, min_arr, min_m, &count);
    min = get_arr_min(min_arr, n, min_m, &count, &odd);
    
    int index = 1;
    int ptr;
    sorted[index] = max;
    low = min - 1;
    while (max != min){
        ptr = insert_low(arr, m, max, low, &count);
        max = update_tournament(arr, m, ptr, &count);
        sorted[++index] = max;
        printf("\nsorted:\n");
        verbose("sorted", sorted, index);
    }
    printf("Maximum = %d\n", sorted[1]);
    printf("Minimum = %d\n", sorted[index]);
    /*
    if(odd == 0){
        printf("3n/2-2 = %d\n", (((3*n)/2)-2));
    }
    else{
        if(odd == 1){
            printf("3(n-1)/2 = %d\n", ((3*(n-1))/2) );
        }
    }
    */
    printf("n(n+1)/2 = %d\n", ((n*(n+1))/2));
    printf("Count = %d\n", count);
    printf("\n");
}


int build_tournament(int arr[], int m, int min_arr[], int min_m, int *count){
    printf("\nBuilding init tournament\n");
    int min;
    int j=1;
    for(int i=m; i>1; i=i-2){
        *count = *count + 1; if (arr[i]>arr[i-1]) {    
            arr[i/2] = arr[i];
            min = arr[i-1];
        }
        else {
            arr[i/2] = arr[i-1];
            min = arr[i];
        }
        if (j<=min_m) {
            min_arr[j] = min;
            j++;
        }
        verbose("build_tournament", arr, m);
    }
    printf("\nmin_arr\n");
    verbose("build_tournament", min_arr, min_m);
    printf("\nInit tournament built\n\n");
    return arr[1];
}


int insert_low(int arr[], int m, int max, int low, int *count){
    int init_ptr, ptr = 1, next_ptr = 2;
    int num1, num2;
    int temp_count = *count;
    int temp_max;
    arr[ptr] = low;
    
    while(next_ptr <= m){
        ptr = next_ptr;
        init_ptr = ptr;
        num1 = arr[ptr];
        num2 = arr[ptr+1];
        temp_count++; if(num1 == max){
            next_ptr = ptr * 2;
        }
        else {
            ptr = (ptr + 1);
            next_ptr = ptr * 2;
        }
        verbose2("insert_low", init_ptr, num1, num2, ptr, next_ptr);
        arr[ptr] = low;
    }
    verbose("insert_low", arr, m);
    return ptr;
}


int update_tournament(int arr[], int m, int ptr, int *count){
    /*
    for(int i=m; i>1; i=i-2){
        *count = *count + 1; if (arr[i]>arr[i-1]) {    
            arr[i/2] = arr[i];
        }
        else {
            arr[i/2] = arr[i-1];
        }
        verbose("update_tournament", arr, m);
    }
    printf("\ncheck : %d, m = %d, ptr = %d\n",arr[1], m, ptr);
    return arr[1];
    */
    int ptr1, ptr2;
    
    while (ptr != 1) {
        if (ptr%2==0){
            ptr1 = ptr;
            ptr2 = ptr + 1;
        }
        else {
            ptr1 = ptr - 1;
            ptr2 = ptr;
        }
        ptr = ptr/2;
        /*
        *count = *count + 1; if (arr[ptr1]>arr[ptr2]) {
            arr[ptr] = arr[ptr1];
        }
        else {
            arr[ptr] = arr[ptr2];
        }
        */
        *count = *count + 1; arr[ptr] = get_max(arr[ptr1], arr[ptr2]);
        verbose("update_tournament", arr, m);
    }
    printf("\ncheck : %d, m = %d, ptr = %d\n",arr[1], m, ptr);
    return arr[1];
}


int get_arr_min(int min_arr[], int n, int min_m, int *count, int *odd){
    int p = 1;
    int min = min_arr[p];
    if (n%2==0) {
        *odd = 0;
        *count = *count + 1;
        min = get_min(min_arr[p],min_arr[p+1]);
        p = p + 1;
    }
    p = p + 1;
    int temp_min = min;
    for (int i = p; i <= min_m; i = i + 2){
        *count = *count + 1; 
        temp_min = get_min(min_arr[p], min_arr[p+1]);
        *count = *count + 1; 
        min = get_min(temp_min, min);
    }
    return min;
}


int get_max(int a, int b) {
    if (a>b) return a;
    else return b;
}


int get_min(int a, int b) {
    if (a>b) return b;
    else return a;
}


void verbose(char func_name[], int arr[], int m){
    printf("\nVerbose:: %s\n", func_name); int i = 0;
    printf("Array :: | "); for(i = 1 ; i <= m; i++){
        printf(" %d | ", arr[i]);
    }
    printf("\nIndex :: | "); for(i = 1 ; i <= m; i++){
        printf(" %d | ", i);
    }
    printf("\n\n");
}

void verbose2(char func_name[], int ip, int n1, int n2, int cp, int np){
    printf("\nVerbose2:: %s\n", func_name);
    printf("init pointer = %d, ", ip);
    printf("num1 = %d ", n1);
    printf("num2 = %d ", n2);
    printf("cur pointer = %d ", cp);
    printf("next pointer = %d ", np);
    printf("\n");
}

