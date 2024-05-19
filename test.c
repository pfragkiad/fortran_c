#include <stdio.h>
#include <stdlib.h>

// pure real(8) function myfunc(x)

// gcc -o main.out test.c a.so
// gcc -o main.out test.c a.so flib_path/a2.a
// gcc -o main.out test.c a3.a

//it is best to use static libraries instead!

// a.so is a dll, so before calling main.out we should ensure that the .so is used
// LD_LIBRARY_PATH=/home/cliff/mycode/fortran/for_lib
// export LD_LIBRARY_PATH

// to see if the current library path is loaded:
// echo $LD_LIBRARY_PATH

// typically the LD_LIBRARY_PATH should point to LD_LIBRARY_PATH=/usr/local/lib
// to permanently use the export add to the ~/.bashrc the following line:
// export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/library
// to reload the bash:
// source ~/.bashrc
// or
//. ~/.bashrc
// or
// exec bash
extern double myfunc_(double *x);

extern void mysub_(int *a, int *b);

extern int myintfunc_(int *x);

// pure real(8) function mystaticfunc(x)
extern double mystaticfunc_(double *x);

#define sz 10
typedef struct t_gasMix
{
    int m_CO2;
    double s;
    int n;
    double a[sz];
    double *v;
} gasMix, *pgasMix;

// extern void teststruct_(pgasMix gas);
extern void teststruct_(gasMix *gas);
// extern void teststruct_(struct t_gasMix* gas);

extern double getsum_(int *n, double **a);

int main(int argc, char **argv)
{
    // double value = 10.0;
    // double v = myfunc_(&value);

    // printf("The value is %lf.\n",v);

    // double v2 = mystaticfunc_(&value);
    // printf("The value static is %lf.\n",v2);
    int a = 1000;
    int b = myintfunc_(&a);
    printf("The value is: %d\n", b);

    int x = 30, y;
    mysub_(&x, &y);
    printf("The value of y is: %d\n", y);

    gasMix g;
    g.m_CO2 = 10;
    g.n = 10;
    g.v = malloc(g.n * sizeof(double));

    for (int i = 0; i < g.n; i++)
    {
        g.v[i] =  g.a[i] = (double)(i + 1);
    }

    teststruct_(&g);


    printf("The sum of the elements is %lf.\n", g.s);
    printf("The m_CO2 is %d.\n", g.m_CO2);

    // printf("The v[0] is %lf.\n", g.v[0]);
    free(g.v);

    int count = 10;
    double *arr = malloc(count * sizeof(double));
    for (int i = 0; i < count; i++)
        arr[i] = i + 1;
    double s = getsum_(&count, &arr);
    printf("The sum2 is %lf!\n", s);
    free(arr);

    return 0;
}
