#include "stdio.h"

void verbose(char [], int [], int, int);
void verbose2(char [], int, int, int, int, int, int, int);
void verbose3(char [], int, int, int, int);
int partition(int [], int, int, int, int);
void quicksort(int, int [], int, int, int, int);
void swap(int *, int *);
void indent(int);

int main() {
    int i, n, num, level = 0;
    printf ("Enter the number of elements :: ");
    scanf("%d",&n);
    if (n<=0) {printf("invalid value for n, exiting!\n"); return 0;}

    int arr[n];
    printf("Enter the numbers :: ");
    for(i = 0; i<n; i++){
        scanf("%d", &num);
        arr[i] = num;
    }
    verbose("input_array", arr, n, level);
    quicksort(0, arr, 0, n-1, n, level);
    verbose("output_array", arr, n, level);
    return 0;
}


void quicksort(int id, int arr[], int i, int j, int n, int level) {
    level++;
    int l;
    verbose3("Entered with ", id, i, j, level);
    if (i >= j){
        indent(level); printf("Recursion breaking condition");
        verbose("returned_array:", arr, n, level);
        return;
    }
    else {
        l = partition(arr, i, j, n, level);
        quicksort(1, arr, i, l, n, level);
        quicksort(2, arr, l+1, j, n, level);
    }
    verbose3("Exiting with ", id, i , j, level);
}


int partition(int arr[], int i, int j, int n, int level) {
    int l;
    int x = arr[i];
    int p = i;
    int q = j;
    while(p<q){
        while ((p<q) && arr[p]<x) p++;
        while ((p<q) && arr[q]>=x) q--;
        if(p<q) swap(&arr[p], &arr[q]);
    }
    if (arr[q] > x) {
        l = q - 1;
    }
    else {
        l = q;
    }
    verbose("partially_sorted_array:", arr, n, level);
    verbose2("partition completed:", i, j, n, p, q, l, level);
    return l;
}


void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}


void verbose(char func_name[], int arr[], int m, int level) {
    indent(level); printf("Verbose:: %s\n", func_name); int i = 0;
    indent(level); printf("Array :: | "); for(i = 0 ; i < m; i++){
        printf(" %d | ", arr[i]);
    }
    indent(level); printf("Index :: | "); for(i = 0 ; i < m; i++){
        printf(" %d | ", i);
    }
    printf("\n\n");
}


void verbose2(char func_name[], int start, int j, int n, int p, int q, int l, int level){
    indent(level);
    printf("Verbose2:: %s ", func_name);
    printf("start = %d, ", start);
    printf("j = %d, ", j);
    printf("n = %d, ", n);
    printf("p = %d, ", p);
    printf("q = %d ", q);
    printf("l = %d ", l);
    printf("\n");
}


void verbose3(char func_name[], int id, int i, int j, int level){
    indent(level);
    printf("Verbose3:: %s ", func_name);
    printf("i = %d, ", i);
    printf("j = %d, ", j);
    printf("level = %d ", level);
    printf("\n");
}


void indent(int l) {
    printf("\n");
    for (int i = 1; i<l+1; i++) {printf(" -");}
    printf("| ");
}

