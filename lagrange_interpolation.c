#include "./lagrange_interpolation.h"



// n -- the term of the polynomial
// x -- x array
// y -- y array
// a -- the number to be computed in the polynomail
double lagrange_interpolation(int n, double *x, double *y, double a)
{
    double numer = 1,denomi = 1,k = 0;
    int i, j;

    for(i=0;i<n;i++)
    {
        numer = 1;
        denomi = 1;
        for(j=0;j<n;j++)
        {
            if(j!=i)
            {
                numer = numer * (a - x[j]);
                denomi = denomi * (x[i] - x[j]);
            }
        }
        k = k + y[i]*(numer/denomi);
    }

    return k;
}





// int main()
// {
//     int term = 0;
//     printf("enter the term of the polynomial:\n");
//     scanf("%d", &term);

//     srand(time(NULL));
    
//     int i;
//     int *org_coef = malloc(sizeof(int) * term);
//     for(i=0;i<term;i++)
//     {
//         org_coef[i] = rand() % 10;
//     }

//     double *x = malloc(sizeof(double) * term);
//     double *y = malloc(sizeof(double) * term);
//     double const_coef;

//     const_coef = lagrange_interpolation(term, x, y, 0);
    
//     printf("constant coefficient = %lf\n", lagrange_interpolation(term, x, y, 2));
//     return 0;
// }