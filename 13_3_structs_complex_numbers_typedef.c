#include "stdio.h"

typedef struct {
    float x;
    float y;
} complex;

void complex_add(complex *,complex *,complex *);

int main() {
    complex c1, c2, c;
    printf("Enter real and imaginary part of 1st number:: ");
    scanf("%f%f",&c1.x,&c1.y);
    
    printf("Enter real and imaginary part of 2nd number:: ");
    scanf("%f%f",&c2.x,&c2.y);
    
    complex_add(&c1, &c2, &c);
    // passing the address of c1 and c2 is not required
    // as only c requires call by value
    // but it works  
            
    printf(
        "Sum of %5.2f + (%5.2fi) and %5.2f + (%5.2fi) = %5.2f + (%5.2fi)\n",
        c1.x,
        c1.y,
        c2.x,
        c2.y,
        c.x,
        c.y
    );
        
    printf("\n");
}

void complex_add(complex *c1, complex *c2, complex *c){
    // using '->' is required in lieu of '.' when addresses are passed
    // as in case of call by value
    c->x = c1->x+c2->x;
    c->y = c1->y+c2->y;
}

