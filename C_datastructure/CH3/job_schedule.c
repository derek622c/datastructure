#include <stdio.h>
#include <stdlib.h>

void infix_to_postfix(char infix_q[], int rear)
{
    int top=0,ctr,MAX,front;
    char stack_t[MAX];
    stack_t[top]='#';

    for(ctr=0;ctr<=rear;ctr++)
    {
        switch(infix_q[ctr])
        {
            case ')':
                while(stack_t[top] != '(' )
                    printf("%c",stack_t[top--]);
                top--;
                break;
            case '#':
                while(stack_t[top] != '#' )
                    printf("%c",stack_t[top--]);
                break;
            case '(':
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                while(compare(stack_t[top], infix_q[ctr]))
                    printf("%c",stack_t[top--]);
                stack_t[++top]=infix_q[ctr];
                break;
            default:
                printf("%c",infix_q[ctr]);
                break;
        }
    }



}