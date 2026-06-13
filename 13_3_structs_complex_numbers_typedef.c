#include "stdio.h"

typedef struct {
    float real;
    float imag;
} complex;

complex add_complex(complex, complex);
void read_complex(complex *);
void print_complex(complex);

// to return a user defined type
// typedef is used
// and function declarations are to be done
// in the beginning eg. before main function is defined
// these functions can be defined later after the main
// function definition

int main() {
    complex c1, c2, c;
    read_complex(&c1);
    read_complex(&c2);
    c = add_complex(c1,c2);
    printf("c1 + c2 = ");
    print_complex(c);
        
    printf("\n");
}

complex add_complex(complex a, complex b) {
    complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

void read_complex(complex *var) {
    printf("Enter the real and the imaginary parts :: ");
    scanf("%f%f", &(var->real), &(var->imag));
}

void print_complex(complex var) {
    printf("%5.2f + (%5.2fi)", var.real, var.imag);
}

