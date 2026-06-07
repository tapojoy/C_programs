#include "stdio.h"

void swap(int *, int *);

int main() {
    int n, i, j, temp;
    printf("Enter number of elements :: ");
    scanf("%d",&n);
    int data[n];
    printf("Enter the numbers :: ");
    for (i = 0; i<n; i++) {
        scanf("%d", data+i);
    }

    for (i = 0; i < n-1; i++) {
    	for (j = i+1; j < n; j++) {
            if (*(data+i)<*(data+j)) {
                //temp = *(data + i);
                //*(data + i) = *(data+j);
                //*(data+j) = temp;
                //addresses can be passed to the function this way
                swap((data+i),(data+j));
            }
        }
    }

    printf("The sorted numbers are :: ");
    for (i = 0; i < n; i++) {
    	printf("%d ", *(data+i));
    }
    printf("\n");
}


//swap function is defined in the same way
void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}
