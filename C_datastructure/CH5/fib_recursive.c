#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int fibton(int);
int main()
{
    char ch;
    int n;
    printf("fibton counting using recursiive\n");
    do
    {
        printf("please enter a number show n number: ");
        scanf("%d",&n);
        if(n<0)
            printf("your input must be >0 \n");
        else
            printf("the %d item is %d\n",n,fibton(n));
        printf("Continue y/n?");
        while(getchar() != '\n')
            continue;
        ch=toupper(getchar());
    } while (ch=='Y');
    
}

int fibton(int a)
{
    if (a==0)
        return 0;
    else if(a==1||a==2)
        return 1;
    else
        return fibton(a-1)+fibton(a-2);
    
}