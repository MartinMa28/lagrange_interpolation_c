#include "lagrange_interpolation.h"
#define GROUP_SIZE 20

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
struct Node * create_node(int coef, int exp, struct Node **temp, struct Node **cur)
{
    struct Node *r;           // r points to a term node
    r = *cur;
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

    return r;
}

double compute(struct Node *node, double x)
{
    double result = 0;
    while(node->next != NULL)
    {
        result += node->coef * pow(x,(double)node->exp);
        node = node->next;
    }
    return result;
}

double * compute_array(struct Node *node, int n, double *x)
{
    int i;
    double *y = malloc(sizeof(double) * n);

    for(i=0;i<n;i++)
    {
        y[i] = compute(node, x[i]);
    }

    return y;
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
    printf("\n");
}

double* generate_normal_distribution(int n)
{
    int i;
    int m = n + n % 2;
    double* values = (double*)calloc(m,sizeof(double));
    double average, deviation;
 
    if ( values )
    {
        for ( i = 0; i < m; i += 2 )
        {
            double x,y,rsq,f;
            do {
                x = 2.0 * rand() / (double)RAND_MAX - 1.0;
                y = 2.0 * rand() / (double)RAND_MAX - 1.0;
                rsq = x * x + y * y;
            }while( rsq >= 1. || rsq == 0. );
            f = sqrt( -2.0 * log(rsq) / rsq );
            values[i]   = x * f;
            values[i+1] = y * f;
        }
    }
    return values;
}



double buffer[GROUP_SIZE];         // shared buffer for broadcasting
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; // mutex for shared buffer

int main()
{
    
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *cur = NULL;

    // Create first list of 5x^2 + 4x^1 + 2x^0
    cur = create_node(5,2,&poly1, &cur);
    cur = create_node(4,1,&poly1, &cur);
    cur = create_node(2,0,&poly1, &cur);

    show(poly1);
    double r = compute(poly1, 1);
    printf("\n%f\n", r);
    return 0;
}


//int main()
//{
//    int term = 0;
//    printf("enter the term of the polynomial:\n");
//    scanf("%d", &term);
//
//    srand(time(NULL));
//    
//    int i;
//    int coef;
//    struct Node *poly = NULL;
//    struct Node *cur = NULL;
//
//    for(i=0;i<term;i++)
//    {
//        coef = rand() % 10;
//        cur = create_node(coef, term-1-i, &poly, &cur);
//    }
//    show(poly);
//    double *x = generate_normal_distribution(term);
//    double *y = compute_array(poly, term, x);
//    for(i=0;i<term;i++)
//    {
//        printf("x: %f, y: %f\n", x[i], y[i]);
//    }
//    double const_coef;
//
//    const_coef = lagrange_interpolation(term, x, y, 0);
//    
//    printf("constant coefficient = %lf\n", lagrange_interpolation(term, x, y, 0));
//    return 0;
//}
