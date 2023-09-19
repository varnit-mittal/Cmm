#include"../include/arithmetic.h"

int perform_arithmetic(int x, char *op, int y)
{
    if(op[0]=='+')
    return x+y;

    if(op[0]=='-')
    return x-y;

    if(op[0]=='*')
    return x*y;

    if(op[0]=='/')
    return x/y;
}