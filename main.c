

#include <stdio.h>

// declare function prototype (f comes from c-built file)
int f(int a, int b);


int forf_(int* a, int* b);

int main(int argc, char **argv)
{
    int x = 10, y = 20;
    int result = f(x, y);
    printf("The result from C is %d.\n",result);

    int result2 = forf_(&x, &y);
    printf("The result from Fortran is %d.\n",result2);

    return 0;
}