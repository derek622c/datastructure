#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int factorial(int);

int main()
{
    char ch;
    int n;
    printf("---factorial counting using recursive---\n");
    do
    {
        printf("please enter a number (0 <= n <= 12) to accout n!: ");
        scanf("%d",&n);
        while(getchar() != '\n')
            continue;
        if(n<0 || n>12 )
            printf("input out of range");
        else
        {
            printf("%d! = %d \n",n,factorial(n));
        }
        printf("Continue (y/n)?");
        ch=toupper(getchar());
    } while (ch=='Y');
        
}
int factorial(int a)
{
    if(a==0 || a==1)
        return 1;
    else
        return a*factorial(a-1);
}