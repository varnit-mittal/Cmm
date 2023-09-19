#include<stdio.h>
#include<stdlib.h>
#include"../include/interpreter.h"
#include"../include/variable.h"
#include<string.h>

int n=25;
void create_variable(var **temp)
{
    n=n+5;
    temp=(var **)(realloc(temp,sizeof(var *)*n));
}

void assign_variable(char *token, int value)
{
    int j=token[0]-'a';
    variables[j]->a=value;
}

int get_variable_value(char var_name)
{
    return variables[var_name-'a']->a;
}