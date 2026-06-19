#include "stdio.h"

void permute(char[], int, int, char[], int, int);
void del_string(char[], int, int, char[]);
void vrbs(char [], int, int, char [], int, char[], int);

int main () {
    int n, r;
    printf("\nEnter n :: ");
    scanf("%d", &n);
    printf("\nEnter r :: ");
    scanf("%d", &r);
    
    int path = 0, level = 0;
    char in_str[n], path_str[r];
    printf("\nEnter the inputs :: ");
    scanf("%s", in_str);
    permute(in_str, n, r, path_str, path, level);
    printf("\n");
}


void permute(
    char in_str[],
    int n,
    int r,
    char path_str[],
    int p,
    int l
){
    l++;
    if (r == 0) {
        printf("--\nRESULT :: <%s> \n--",path_str);
        //return;
    }
    else {
        char new_str[n];
        for (int i = 0; i < n; i++) {
            path_str[p] = in_str[i];
            //p++;
            del_string(in_str, i, n, new_str);
            vrbs(in_str, n, i, path_str, p, new_str, l);
            permute(new_str, n-1, r-1, path_str, p+1, l);
            //p--;
        }
        //return;
    }
}


void del_string(
    char in_str[],
    int i,
    int n,
    char new_str[]
){
    int j = 0;
    while(j < i) {
        new_str[j] = in_str[j];
        j++;
    }
    while(j < n-1){
        new_str[j] = in_str[j+1];
        j++;
    }
}


void vrbs(
    char in_str[],
    int n,
    int i,
    char path_str[],
    int path, 
    char new_str[],
    int level
){
    printf("\nVerbose:: | ");
    printf("instr = %s, ", in_str);
    printf("n = %d, ", n);
    printf("i = %d, ", i);
    printf("pstr = %s, ", path_str);
    printf("p = %d, ", path);
    printf("ntr = %s, ", new_str);
    printf("l = %d |", level);
    printf("\n");
}

