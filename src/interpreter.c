#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "../include/arithmetic.h"
#include "../include/condition.h"
#include "../include/interpreter.h"
#include "../include/print.h"
#include "../include/variable.h"

var **variables;

char *string_obtain(char *temp, int a, int j)
{
    char *var_name = malloc(sizeof(char) * 40);
    int x = 0;
    for (++a; a < j; a++)
    {
        if (temp[a] != ' ')
        {
            var_name[x] = temp[a];
            x++;
        }
    }
    for (int l = x; l < strlen(var_name); l++)
    {
        var_name[l] = '\0';
    }
    return var_name;
}

void execute_c_minus_minus(char *code)
{
    int cond = 0;
    variables = (var **)(malloc(sizeof(var *) * 2000));
    for (int i = 0; i < 2000; i++)
    {
        variables[i] = (var *)malloc(sizeof(var));
        variables[i]->a = 0;
    }
    int i = 0;
    while (code[i] != '\0')
    {
        char *temp = malloc(sizeof(char) * 500);
        int j = 0;
        if (code[i] != ' ')
        {
            while (code[i] != ';' && code[i] != '}' && code[i] != '{')
            {
                if (code[i] != '\t')
                {
                    temp[j] = code[i];
                    j++;
                }
                i++;
            }
        }
        char *tool = malloc(sizeof(char) * 100);
        int k = 0;
        int a;
        for (a = 0; a < j; a++)
        {
            if (temp[a] == ' ')
                break;
            tool[k] = temp[a];
            k++;
        }
        for (int l = k; l < strlen(tool); l++)
        {
            tool[l] = '\0';
        }

        if (strcmp(tool, "int") == 0)
        {
            // create_variable(variables);
            char *var_name = string_obtain(temp, a, j);
            int l = 1;
            int s = 0;
            int control=0;
            int y=0;
            char *op=(char *)(malloc(sizeof(char)*4));
            int x=0;
            for (int j = strlen(var_name) - 1; j > 0; j--)
            {
                if (var_name[j] == '=')
                    break;
                else if (isdigit(var_name[j]))
                {
                    if(control ==0)
                    x = x + (var_name[j] - '0') * l;
                    else
                    y = y + (var_name[j] - '0') * l;
                    l = l * 10;
                }
                else if (isalpha(var_name[j]))
                {
                    if(control==0)
                    x= get_variable_value(var_name[j]);
                    else
                    y= get_variable_value(var_name[j]);
                    l = 1;
                }
                else if(var_name[j]=='+' || var_name[j]=='/' || var_name[j]=='*' || var_name[j]== '-')
                {
                    l=1;
                    op[0]=var_name[j];
                    control=1;
                }
            }
            if(x!=0 && y!=0)
            s=perform_arithmetic(y,op,x);
            else if(x==0 && y!=0)
            s=y;
            else
            s=x;
            assign_variable(var_name, s);
        }

        else if (strcmp(tool, "print") == 0)
        {
            char *var_name = string_obtain(temp, a, j);
            print_variable(var_name);
        }

        else if (strcmp(tool, "if") == 0)
        {
            char *var_name = string_obtain(temp, a, j);

            int l = 1, s = 0, i = 0, d = 0;
            char *op = malloc(sizeof(char) * 10);
            int x = 0, y = 0, k = 0;
            while (var_name[i] != ')')
            {
                if (var_name[i] != ' ')
                {
                    if (k == 0)
                    {
                        if (isalpha(var_name[i]))
                        {
                            s += get_variable_value(var_name[i]);
                        }
                        else if (isdigit(var_name[i]))
                        {
                            s += (var_name[i] - '0') * l;
                            l *= 10;
                        }
                        else if (var_name[i] == '>' || var_name[i] == '<')
                        {
                            op[d] = var_name[i];
                            d++;
                            x = s;
                            s = 0;
                            k = 1;
                            l = 1;
                        }
                    }
                    else
                    {
                        if (isalpha(var_name[i]))
                        {
                            s += get_variable_value(var_name[i]);
                        }
                        else if (isdigit(var_name[i]))
                        {
                            s = s * l + (var_name[i] - '0');
                            l *= 10;
                        }
                    }
                }
                i++;
            }
            y = s;
            bool cond_check=evaluate_condition(x,op,y);
            if(!cond_check)
            {
                cond=1;
            }
        }
        i++;
        if(cond==1)
        break;
    }
}