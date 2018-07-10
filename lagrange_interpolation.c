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

// create new node
void create_node(int coef, int exp, struct Node **temp)
{
    struct Node *r;           // r points to a term node
    if(*temp == NULL)
    {
        r = malloc(sizeof(struct Node));
        r->coef = coef;
        r->exp = exp;
        *temp = r;
        r->next = malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
    else
    {
        r->coef = coef;
        r->exp = exp;
        r->next = malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
}

void show(struct Node *node)
{
    while(node->next != NULL)
    {
        printf(" %dx^%d ", node->coef, node->exp);
        node = node->next;
        if(node->next != NULL)
            printf("+");
    }
}

int main()
{
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;

    // Create first list of 5x^2 + 4x^1 + 2x^0
    create_node(5,2,&poly1);
    create_node(4,1,&poly1);
    create_node(2,0,&poly1);

    show(poly1);
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