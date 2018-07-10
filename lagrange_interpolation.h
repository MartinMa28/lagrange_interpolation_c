#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<pthread.h>

struct Node
{
    int coef;
    int exp;
    struct Node *next;
};

double lagrange_interpolation(int n, double *x, double *y, double a);
struct Node * create_node(int x, int y, struct Node **temp, struct Node **cur);
void show(struct Node *node);
double compute(struct Node *node, double x);
double * compute_array(struct Node *node, int n, double *x);
