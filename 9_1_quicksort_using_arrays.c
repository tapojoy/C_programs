#include "stdio.h"

void verbose(char [], int [], int);
void verbose2(char [], int, int, int, int, int, int);
void verbose3(char [], int, int, int);
int partition(int [], int, int, int);
void quicksort(int [], int, int, int, int);

int main() {
    int i, n, num, level = 0;
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
    quicksort(arr, 0, n-1, n, level);
    verbose("output_array", arr, n);
    return 0;
}


void quicksort(int arr[], int i, int j, int n, int level) {
    level++;
    int l;
    verbose3("Entered with ", i , j, level);
    if (i >= j){
        printf("\nRecursion breaking condition");
        verbose("returned_array:", arr, n);
        return;
    }
    else {
        l = partition(arr, i, j, n);
        quicksort(arr, i, l, n, level);
        quicksort(arr, l+1, j, n, level);
    }
    verbose3("Exiting with ", i , j, level);
}


int partition(int arr[], int i, int j, int n) {
    int start = i;
    int p = 0, q = 0;
    int x = arr[start];
    int b1[n], b2[n];
    int l;
    while (i<=j) {
        if (arr[i]>x){
            b1[p++] = arr[i++];
        }
        else {
            b2[q++] = arr[i++];
        }
    }
    for (i = 0; i<p; i++){
        arr[start+i] = b1[i];
    }
    for (i = 0; i<q; i++){
        arr[start+p+i] = b2[i];
    }
    l = start + p;
    verbose("partially_sorted_array:", arr, n);
    verbose2("partition completed:", start, j, n, p, q, l);
    return l;
}


void verbose(char func_name[], int arr[], int m) {
    printf("\nVerbose:: %s\n", func_name); int i = 0;
    printf("Array :: | "); for(i = 0 ; i < m; i++){
        printf(" %d | ", arr[i]);
    }
    printf("\nIndex :: | "); for(i = 0 ; i < m; i++){
        printf(" %d | ", i);
    }
    printf("\n\n");
}


void verbose2(char func_name[], int start, int j, int n, int p, int q, int l){
    printf("\nVerbose2:: %s ", func_name);
    printf("start = %d, ", start);
    printf("j = %d, ", j);
    printf("n = %d, ", n);
    printf("p = %d, ", p);
    printf("q = %d ", q);
    printf("l = %d ", l);
    printf("\n");
}


void verbose3(char func_name[], int i, int j, int level){
    printf("\nVerbose3:: %s ", func_name);
    printf("i = %d, ", i);
    printf("j = %d, ", j);
    printf("level = %d ", level);
    printf("\n");
}

