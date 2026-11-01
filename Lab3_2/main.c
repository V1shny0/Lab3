#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define eps 0.000001

void EData(double *wa, double *wb, int *wn, int *wvar, int *wlog);
double F(double x);
double Hord(double a, double b, int n, int log, double *wt);
double MidDiv(double a, double b, int n, int log, double *wt);
int Choice(int n, double xi);

int main()
{
    double a, b, x, t;
    int n, var, log;

    EData(&a, &b, &n, &var, &log);

    switch (var)
    {
        case 1:
            x = Hord(a, b, n, log, &t);

            printf("\nx = %lf F(x) = %lf Time-%lf", x, F(x), t);

            break;

        case 2:
            x = MidDiv(a, b, n, log, &t);

            printf("\nx = %lf F(x) = %lf Time-%lf", x, F(x), t);

            break;
    }

    return 0;
}

void EData(double *wa, double *wb, int *wn, int *wvar, int *wlog)
{
    printf("Enter X1:");
    scanf("%lf", wa);
    printf("Enter X2:");
    scanf("%lf", wb);

    while (*wa >= *wb || F(*wa) * F (*wb) > 0)
    {
        printf("X2 must be more and not be equal X1.\n");
        printf("And also cant have the same sign on the graph.\n");
        printf("Enter X1 again:");
        scanf("%lf", wa);
        printf("Enter X2 again:");
        scanf("%lf", wb);
    }

    printf("Enter the number of operations:");
    scanf("%d", wn);

    while (*wn <= 0)
    {
        printf("Operation must be more than 0.\n");
        printf("Enter the number of operations again:");
        scanf("%d", wn);
    }

    printf("Enter the variant:");
    scanf("%d", wvar);

    while (*wvar < 1 || *wvar > 2)
    {
        printf("Here only two variants of calculating.\n");
        printf("Enter the variant again:");
        scanf("%d", wvar);
    }

    printf("Do you wonna see logs 0 - no 1 - yes:");
    scanf("%d", wlog);

    while (*wlog < 0 || *wlog > 1)
    {
        printf("Pleas enter 0 - no or 1 - yes:");
        scanf("%d", wlog);
    }
}

double F(double x)
{
    return  pow(x, 3) / 30 - 4 * pow(x, 2) + 50;
}

double Hord(double a, double b, int n, int log, double *wt)
{
    double x;
    double xi = 0;
    int opt;
    int N = 0;
    clock_t start = clock();

    while (fabs(F(xi)) > eps)
    {
        if (N >= n)
        {
            *wt += (double)(clock() - start) / CLOCKS_PER_SEC;

            opt = Choice(n, xi);

            if (opt == 1)
            {
                n += N;;
            }
            else if (opt == 2)
            {
                n = INT_MAX;
            }
            else if (opt == 3)
            {
                printf("\nx = %lf F(x) = %lf", xi, F(xi));

                break;

            }
        }

        xi = (a*F(b) - b*F(a)) / (F(b) - F(a));

        if (F(a) * F(xi) < 0)
        {
            b = xi;
        }
        else
        {
            a = xi;
        }

        if (log)
        {
            printf("\nn%d x=%.12lf", N, xi);
        }

        N++;
    }

    *wt += (double)(clock() - start) / CLOCKS_PER_SEC;

    return xi;
}

double MidDiv(double a, double b, int n, int log, double *wt)
{
    double x;
    double xi = 0;
    int opt;
    int N = 0;
    clock_t start = clock();

    while (fabs(F(xi)) > eps)
    {
        if (N >= n)
        {
            *wt += (double)(clock() - start) / CLOCKS_PER_SEC;

            opt = Choice(n, xi);

            if (opt == 1)
            {
                n += N;;
            }
            else if (opt == 2)
            {
                n = INT_MAX;
            }
            else if (opt == 3)
            {
                printf("\nx = %lf F(x) = %lf", xi, F(xi));

                break;

            }
        }

        xi = (a + b) / 2;

        if (F(a) * F(xi) < 0)
        {
            b = xi;
        }
        else
        {
            a = xi;
        }

        if (log)
        {
            printf("\nn%d x=%lf", N, xi);
        }

        N++;
    }

    *wt += (double)(clock() - start) / CLOCKS_PER_SEC;

    return xi;
}

int Choice(int n, double xi)
{
    int opt;

    printf("\nIteration limit reached");
    printf("\nHad done %d iterations", n);
    printf("\nCurrent x = %lf, F(x) = %lf", xi, F(xi));
    printf("\nWhat to do next?");
    printf("\n 1 - continue with the same number of iterations");
    printf("\n 2 - run until the root is found (no limit)");
    printf("\n 3 - exit and show the intermediate result");
    printf("\nYour choice:");
    scanf("%d", &opt);

    while (opt < 1 || opt > 3)
    {
        printf("Enter correct choice:");
        scanf("%d", &opt);
    }

    return opt;
}
