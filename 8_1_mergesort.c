#include "stdio.h"

void verbose(char [], int [], int);
void verbose2(char [], int, int, int, int, int, int);
void verbose3(char [], int, int, int);
void merge(int [], int, int);
void mergesort(int [], int, int, int, int);

int main() {
    int i, n, num, entry = 0;
    printf ("Enter the number of elements :: ");
    scanf("%d",&n);
    if (n<=0) {printf("invalid value for n, exiting!\n"); return 0;}
    int arr[n];
    printf("Enter the numbers :: \n");
    for(i = 0; i<n; i++){
        scanf("%d", &num);
        arr[i] = num;
    }
    verbose("input_array", arr, n);
    mergesort(arr, 0, n-1, entry, n);
    verbose("output_array", arr, n);
    printf("\n");
    return 0;
}


void mergesort(int arr[], int i, int j, int entry, int full) {
    entry++;
    int mid;
    verbose3("Entered with ", i , j, entry);
    if (i >= j) {
        printf("\nRecursion breaking condition\n");
        verbose("current_array", arr, full);
        return;
    }
    else {
        mid = (i+j)/2;
        mergesort(arr, i, mid, entry, full);
        mergesort(arr, mid+1, j, entry, full);
        merge(arr, i, j);
        verbose("current_array", arr, full);
    }
    verbose3("Exiting with ", i , j, entry);
}


void merge(int arr[], int i, int j) {
    int start = i;
    int end = j;
    int mid = (i + j)/2;
    int k = mid + 1;
    int n = j + 1;
    int sorted[n];
    int p = start;
    verbose2("merge", i, j, mid, k, n, p);
    while (i<= mid && k <= j) {
        if (arr[i] <= arr[k]) {
            sorted[p++] = arr[i++];
        }
        else {
            sorted[p++] = arr[k++];
        }
    }
    if (i > mid ) {
        while(k <= j) {
            sorted[p++] = arr[k++];
        }
    }
    else {
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


void verbose(char func_name[], int arr[], int m) {
    printf("\nVerbose:: %s\n", func_name); int i = 0;
    printf("Array :: | "); for(i = 0 ; i < m; i++){
        printf(" %d | ", arr[i]);
    }

    printf("\nIndex :: | "); for(i = 0 ; i < m; i++){
        printf(" %d | ", i);
    }
    printf("\n");
}


void verbose2(char func_name[], int i, int j, int mid, int k, int n, int p){
    printf("\nVerbose2:: %s ", func_name);
    printf("i = %d, ", i);
    printf("j = %d, ", j);
    printf("mid = %d, ", mid);
    printf("k = %d, ", k);
    printf("n = %d, ", n);
    printf("p = %d ", p);
    printf("\n");
}


void verbose3(char func_name[], int i, int j, int entry){
    printf("\nVerbose3:: %s ", func_name);
    printf("i = %d, ", i);
    printf("j = %d, ", j);
    printf("level = %d ", entry);
    printf("\n");
}

