

#include <stdio.h>

// declare function prototype
int f(int a, int b);

int main(int argc, char **argv)
{
    int x = 10, y = 20;
    int result = f(x, y);
    printf("The result is %d.\n",result);

    return 0;
}