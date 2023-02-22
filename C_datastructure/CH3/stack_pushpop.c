#include <stdio.h>
#include <stdlib.h>

void push_f()
{
    int top,Max;
    int stack[10];
    if(top >= Max-1)
        printf("\n\n stack is full");
    else
    {
        top++;
        printf("\n\n please enter an item to stack:");
        scanf("%d",&stack[top]);   
    }
}

void push_f1()
{
    int top,Max;
    int stack[10];
    if(top >= Max)
        printf("\n\n is full");
    else
        top++;
        printf("");
        scanf("%d",&stack[top-1]);
}

void pop_f1()
{
    int top,Max;
    int stack[10];
    if(top<=0)
        printf("is empty");
    else    
        top--;
        printf("%d is delete",stack[top]);


}