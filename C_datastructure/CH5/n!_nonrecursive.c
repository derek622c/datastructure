#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int factorial_nonrecursive(int);

int main()
{
    char ch;
    int n;
    printf("factorial counting using iterative\n");
    do
    {
        printf("please enter a number (0<=n<=12) to count n!:");
        scanf("%d",&n);
        if(n<0 || n>12)
            printf("your input is out of range");
        else
            printf("%d! = %d \n",n,factorial_nonrecursive(n));
        printf("Continue (y/n)?");
        while(getchar() != '\n')
            continue;
        ch=toupper(getchar());
    } while (ch=='Y');
}

int factorial_nonrecursive(int a)
{
    int i;
    int sum=1;
    if(a==0)
        return 1;
    else
    {
        for(i=1;i<=a;i++)
            sum*=i;
        return sum;
    }
}