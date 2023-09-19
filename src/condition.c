#include"../include/variable.h"
#include"../include/interpreter.h"
#include"../include/condition.h"

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdarg.h>

bool evaluate_condition(int x, char *op, int y)
{
    if(op[0]=='>' && x>y)
    {
        return true;
    }
    else if(op[0]=='>' && x<y)
    return false;
}