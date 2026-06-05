#include "stdio.h"

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
    	    //pointers can be used to access the content this way too
		    if (*(data+i)<*(data+j)) {
		        temp = *(data + i);
		        *(data + i) = *(data+j);
		        *(data+j) = temp;
	        }
	    }
    }

    printf("The sorted numbers are :: ");
    for (i = 0; i < n; i++) {
    	printf("%d ", *(data+i));
    }
    printf("\n");
}

