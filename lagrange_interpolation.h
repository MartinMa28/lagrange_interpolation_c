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
void create_node(int x, int y, struct Node **temp);