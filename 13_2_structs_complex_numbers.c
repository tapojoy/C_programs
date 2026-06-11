#include "stdio.h"

struct complex {
    float x;
    float y;
};

struct complex complex_add(struct complex, struct complex);

int main() {
    struct complex c1, c2, c;
    printf("Enter real and imaginary part of 1st number:: ");
    scanf("%f%f",&c1.x,&c1.y);
    
    printf("Enter real and imaginary part of 2nd number:: ");
    scanf("%f%f",&c2.x,&c2.y);
    
    c = complex_add(c1, c2);
        
    printf(
        "Sum of %5.2f + %5.2fi and %5.2f + %5.2fi = %5.2f +%5.2fi\n",
        c1.x,
        c1.y,
        c2.x,
        c2.y,
        c.x,
        c.y
    );
        
    printf("\n");
}

struct complex complex_add(struct complex c1, struct complex c2){
    struct complex c;
    c.x = c1.x+c2.x;
    c.y = c1.y+c2.y;
    return c;
}

