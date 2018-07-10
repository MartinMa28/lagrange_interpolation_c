#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

struct Node
{
    int coef;
    int exp;
    struct Node *next;
};

double lagrange_interpolation(int n, double *x, double *y, double a);
struct link* create_poly();
int init_poly();
void display_poly();