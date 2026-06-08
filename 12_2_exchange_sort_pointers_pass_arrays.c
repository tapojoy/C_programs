#include "stdio.h"

void sort(int *, int);

int main() {
    int i, n;
    printf("Enter number of elements :: ");
    scanf("%d",&n);
    int data[n];
    printf("Enter the numbers :: ");
    for (i = 0; i<n; i++) {
	    scanf("%d", data+i);
    }

    sort(data,n);

    printf("The sorted numbers are :: ");
    for (i = 0; i < n; i++) {
    	printf("%d ", *(data+i));
    }
    printf("\n");
}


// "pointer to an array" definition of function parameters
// int *arr means the content of arr is an int
// and that is good enough for the operations done in this function
void sort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
    	for (j = i+1; j < n; j++) {
		    if (*(arr+i)<*(arr+j)) {
		        temp = *(arr + i);
		        *(arr + i) = *(arr + j);
		        *(arr + j) = temp;
	        }
	    }
    }
}

