#include "stdio.h"

void verbose(char [], int [], int);
void verbose2(char [], int, int, int, int, int, int);
void verbose3(char [], int, int, int);
void merge(int [], int, int, int);
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
    //printf("Enter for %dth time\n", entry);
    int mid;
    int n = j + 1;
    verbose3("Entered with ", i , j, entry);
    if (i >= j) {
        //do nothing
        //printf("return back :: i = %d, j = %d, arr[i] = %d\n", i, j, arr[i]);
        //verbose("base condition", arr, full);
        printf("\nRecursion breaking condition\n");
        verbose("current_array", arr, full);
        return;
    }
    else {
        //printf("split arr :: i = %d, j = %d, arr[i] = %d\n", i, j, arr[i]);
        //verbose("induction condition", arr, full);
        mid = (i+j)/2;
        mergesort(arr, i, mid, entry, full);
        //verbose("induction condition 1", arr, full);
        mergesort(arr, mid+1, j, entry, full);
        //verbose("induction condition 2", arr, full);
        merge(arr, i, j, full);
        verbose("current_array", arr, full);
    }
    verbose3("Exiting with ", i , j, entry);
}


void merge(int arr[], int i, int j, int full) {
    
    int start = i; // this was important
    int end = j; // this was important
    int mid = (i + j)/2;
    int k = mid + 1;
    int n = j + 1; // this is just for verbose
    int sorted[n]; // issues when array was improperly utilized
    int p = start; // this is also important;
    //verbose("to merge array", arr, n);
    //verbose("full array", arr, full);
    verbose2("merge", i, j, mid, k, n, p);
    while (i<= mid && k <= j) {
        if (arr[i] >= arr[k]) {
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
    //verbose("result_array", arr, n);
    //verbose("full array", arr, full);
}


void verbose(char func_name[], int arr[], int m) {
    printf("\nVerbose:: %s\n", func_name); int i = 0;
    printf("Array :: | "); for(i = 0 ; i < m; i++){
        printf(" %d | ", arr[i]);
    }

    printf("\nIndex :: | "); for(i = 0 ; i < m; i++){
        printf(" %d | ", i);
    }

    //printf("\narr size = %ld",sizeof(arr));
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
    //printf("loop = %d", count);
    printf("\n");
}


void verbose3(char func_name[], int i, int j, int entry){
    printf("\nVerbose3:: %s ", func_name);
    printf("i = %d, ", i);
    printf("j = %d, ", j);
    printf("level = %d ", entry);
    //printf("mid = %d, ", mid);
    //printf("k = %d, ", k);
    //printf("n = %d, ", n);
    //printf("p = %d ", p);
    //printf("loop = %d", count);
    printf("\n");
}

