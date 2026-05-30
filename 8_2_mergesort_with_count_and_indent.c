#include "stdio.h"

void indent(int);
void verbose(char [], int [], int, int);
void verbose2(char [], int, int, int, int, int, int, int);
void verbose3(char [], int, int, int);
void merge(int [], int, int, int, int *);
void mergesort(int [], int, int, int, int, int *);

int main() {
    int i, n, num, level = 0, count = 0;
    printf ("Enter the number of elements :: ");
    scanf("%d",&n);
    if (n<=0) {printf("invalid value for n, exiting!\n"); return 0;}
    int arr[n];
    printf("Enter the numbers :: \n");
    for(i = 0; i<n; i++){
        scanf("%d", &num);
        arr[i] = num;
    }
    verbose("input_array", arr, n, level);
    mergesort(arr, 0, n-1, level, n, &count);
    verbose("output_array", arr, n, level);
    printf("count = %d", count);
    printf("\n");
    return 0;
}

void mergesort(int arr[], int i, int j, int level, int n, int *count) {
    level++;
    int mid;
    int func_count = 0;
    verbose3("Entered with ", i , j, level);
    func_count++; 
    if (i >= j) {
        indent(level); printf("Recursion breaking condition\n");
        verbose("returned_array", arr, n, level);
        return;
    }
    else {
        mid = (i+j)/2;
        mergesort(arr, i, mid, level, n, &func_count);
        mergesort(arr, mid+1, j, level, n, &func_count);
        merge(arr, i, j, level, &func_count);
        verbose("merged_array", arr, n, level);
    }
    verbose3("Exiting with ", i , j, level);
    *count = *count + func_count;
}

void merge(int arr[], int i, int j, int level, int *func_count) {
    int start = i;
    int end = j;
    int mid = (i + j)/2;
    int k = mid + 1;
    int n = j + 1;
    int sorted[n];
    int p = start;
    verbose2("merge", i, j, mid, k, n, p, level);
    while (i<= mid && k <= j) {
        *func_count = *func_count + 1;
        if (arr[i] <= arr[k]) {
            sorted[p++] = arr[i++];
        }
        else {
            sorted[p++] = arr[k++];
        }
    }
    *func_count = *func_count + 1; 
    if (i > mid ) {
        while(k <= j) {
            sorted[p++] = arr[k++];
        }
    }
    else {
        *func_count = *func_count + 1; 
        if (k > j) {
            while(i<=mid) {
                sorted[p++] = arr[i++];
            }            
        }
    }
    for(i = start; i<=end; i++) {
        arr[i] = sorted[i];
    }
}

void indent(int l) {
    printf("\n");
    for (int i = 1; i<l+1; i++) {printf("--");}
    printf("| ");
}

void verbose(char func_name[], int arr[], int m, int level) {
    indent(level); printf("Verbose:: %s\n", func_name); int i = 0;
    indent(level); printf("Array :: | "); for(i = 0 ; i < m; i++){
        printf(" %d | ", arr[i]);
    }
    indent(level); printf("Index :: | "); for(i = 0 ; i < m; i++){
        printf(" %d | ", i);
    }
    printf("\n");
}

void verbose2(char func_name[], int i, int j, int mid, int k, int n, int p, int level){
    indent(level);
    printf("Verbose2:: %s ", func_name);
    printf("i = %d, ", i);
    printf("j = %d, ", j);
    printf("mid = %d, ", mid);
    printf("k = %d, ", k);
    printf("n = %d, ", n);
    printf("p = %d ", p);
    printf("\n");
}

void verbose3(char func_name[], int i, int j, int level){
    indent(level);
    printf("Verbose3:: %s ", func_name);
    printf("i = %d, ", i);
    printf("j = %d, ", j);
    printf("level = %d ", level);
    printf("\n");
}

