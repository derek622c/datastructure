#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int fib_nonrecursive(int);

int main()
{
    char ch;
    int n;
    printf("fibton counting using nonrecursive\n");
    do
    {
        printf("please enter a number show n number");
        scanf("%d",&n);
        if(n<0)
            printf("your input must be >0 \n");
        else
            printf("the %d  item is %d \n",n,fib_nonrecursive(n));
        printf("Continue y/n ?");
        while(getchar() != '\n')
            continue;
        ch= toupper(getchar());
    }while(ch=='Y');
}

int fib_nonrecursive(int a)
{
    int thisnum;
    int back1num;
    int back2num;
    
    if(a==0)
        return 0;
    else if(a==1)
        return 1;
    else
    {
        back1num=1;
        back2num=0;
        int temp;
        for(int i=2; i<=a; i++)
        {
            thisnum = back1num + back2num;
            back2num = back1num;
            back1num = thisnum;
        }
        return thisnum;
    }
}