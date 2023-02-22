/* push item into the stack */
#include <stdio.h>
#include <stdlib.h>
int t[20];
int b[20];
char MS[20][20];
void push(int i,int x)
{
    if (t[i]==b[i+1])
        printf("the stack is full");
    else 
        MS[++t[i]]=x;
}
void pop(int i,char x)
{
    if(t[i]==b[i])
        printf("the stack is empty");
    else
        printf("%d is delete",MS[t[i]--]);
}