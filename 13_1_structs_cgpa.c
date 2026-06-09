#include "stdio.h"

int main() {
    int i, n;
    float cg = 0.0;
    struct {
        char name[25];
        char roll[8];
        float sgpa[8];
        float cgpa[8];
    } student;
    
    printf("Enter name of the student :: ");
    scanf("%s", &(student.name));
    
    printf("Enter roll number :: ");
    scanf("%s", &(student.roll));
    
    printf("Enter number of semesters :: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("Enter sgpa for sem %d ::", i+1);
        scanf("%f", &(student.sgpa[i]));
        cg = (cg*i + student.sgpa[i])/(i+1);
        // cg has to be multiplied by i to get the mathematically correct mean
        // cg has to be a float to give the correct result
        student.cgpa[i] = cg;
    }
    
    printf("\nPrint\n");
    printf("Name = %s, roll = %s\n", student.name, student.roll);
    for(i = 0; i < n; i++) {
        printf("Sem %d: SGPA = %5.2f, CGPA = %5.2f\n", i+1, student.sgpa[i], student.cgpa[i]);
    }
    
    printf("\n");
}

