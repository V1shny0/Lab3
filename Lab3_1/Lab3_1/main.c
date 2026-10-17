#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PrintHeader(double x, double x2, double delta, int W);

void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

int main()
{
    int N, W, var, n, lines, page, first;
    double x1, x2, delta, x, Fx, preFx, Gx, Hx;
    n = 1;
    lines = 0;
    page = 11;
    W = 15;
    first = 1;

    printf("Enter your variant:");
    scanf("%d", &var);

    while(var != 1 && var != 2)
    {
        printf("\nYou enter incorrect variant, try again:");
        scanf("%d", &var);
    }

    printf("\nEnter first x:");
    scanf("%lf", &x1);
    printf("\nEnter final x:");
    scanf("%lf", &x2);

    while (x1 == x2)
    {
        printf("\nThe values cannot be the same, try again");
        printf("\nEnter first x:");
        scanf("%lf", &x1);
        printf("\nEnter final x:");
        scanf("%lf", &x2);
    }

    x = x1;

    switch (var)
    {
        case 1:
            printf("\nEnter the number of rows:");
            scanf("%d", &N);

            while(N < 2)
            {
                printf("\nHere must be more then 1 row, try again:");
                scanf("%d", &N);
            }

            delta = (x2 - x1) / (N - 1.0);

            system("cls");

            PrintHeader(x, x2, delta, W);

            while ((delta > 0 && x1 <= x2) || (delta < 0 && x1 >= x2))
            {
                Fx = ((pow(x1, 3) / 30) - (4 * pow(x1, 2)) + 50);
                Gx = ((pow(x1, 2)/ 10) - (8 * x1));
                Hx = (pow(x1 + 0.01, 3) / 30 - 4 * pow(x1 + 0.01, 2) + 50 - (pow(x1, 3) / 30 - (4 * pow(x1, 2)) + 50)) / 0.01;
                if(!first && ((preFx >= 0 && Fx <= 0) || (preFx <= 0 && Fx >= 0)))
                {
                    SetColor(12);
                    printf(" <--- Here is the x-intercept");
                    SetColor(7);
                }

                printf("\n|%*d|%*.2lf|%*.2lf|%*.2lf|%*.2lf|", W, n, W, x1, W, Fx, W, Gx, W, Hx);
                printf("\n+---------------+---------------+---------------+---------------+---------------+");

                first = 0;
                preFx = Fx;
                lines ++;
                x1 = x1 + delta;
                n ++;

                if (lines > page)
                {
                    printf("\nPress any button to continue...");
                    getch();
                    system("cls");
                    lines = 0;
                }

                if (lines == 0 && x1 <= x2)
                {
                    PrintHeader(x, x2, delta, W);
                }
            }
            break;

        case 2:
            printf("\nEnter delta:");
            scanf("%lf", &delta);

            while(delta == 0)
            {
                printf("\nDelta cannot be 0, try again:");
                scanf("%lf", &delta);
            }

            N = (((x2 - x1) / delta) + 1);

            system("cls");

            PrintHeader(x, x2, delta, W);

            while ((delta > 0 && x1 <= x2) || (delta < 0 && x1 >= x2))
            {
                Fx = ((pow(x1, 3) / 30) - (4 * pow(x1, 2)) + 50);
                Gx = ((pow(x1, 2)/ 10) - (8 * x1));
                Hx = (pow(x1 + 0.01, 3) / 30 - 4 * pow(x1 + 0.01, 2) + 50 - (pow(x1, 3) / 30 - (4 * pow(x1, 2)) + 50)) / 0.01;
                if(!first && ((preFx >= 0 && Fx <= 0) || (preFx <= 0 && Fx >= 0)))
                {
                    SetColor(12);
                    printf(" <--- Here is the x-intercept");
                    SetColor(7);
                }

                printf("\n|%*d|%*.2lf|%*.2lf|%*.2lf|%*.2lf|", W, n, W, x1, W, Fx, W, Gx, W, Hx);
                printf("\n+---------------+---------------+---------------+---------------+---------------+");

                first = 0;
                preFx = Fx;
                lines ++;
                x1 = x1 + delta;
                n ++;

                if (lines > page)
                {
                    printf("\nPress any button to continue...");
                    getch();
                    system("cls");
                    lines = 0;
                }

                if (lines == 0 && x1 <= x2)
                {
                    PrintHeader(x, x2, delta, W);
                }
            }
    }

    return 0;
}

void PrintHeader(double x, double x2, double delta, int W)
{
    printf("*X1 = %.2lf     X2 = %.2lf     Delta = %.2lf", x, x2, delta);
    printf("\n*********************************************************************************");
    printf("\n*%*s*%*s*%*s*%*s*%*s*", W, "N", W, "X", W, "Fx", W, "Gx-an", W, "Gx-oz");
    printf("\n*********************************************************************************");
    printf("\n+---------------+---------------+---------------+---------------+---------------+");
}
