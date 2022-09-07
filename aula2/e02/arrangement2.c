#include <stdio.h>
#include <stdlib.h>

int main(){
    int x[3];
    x[0] = 1;
    x[1] = 2;
    x[2] = 7;

    int* y = (int*)malloc(sizeof(int)*3);
    y[0] = 4;
    y[1] = 5;
    y[2] = 6;

    printf("y0: %i, y1: %i, y2: %i\n", y[0], y[1], y[2]);
    printf("&y: %p, y: %p, *y: %i\n", &y, y, *y);
    
    *y = *x;
    free(y);
    y = (int*) x;
}