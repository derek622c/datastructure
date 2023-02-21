#include <stdio.h>
#include <stdlib.h>
//fibon series n0=1, n1=1, n2=2, n3=3, n4=5, n5=8
//求 n5?

int fibon_fun(int);
int fibon_recursive_fun(int);
int fibon(int);

int main()
{
    int n=5;
    printf("%d\n",fibon_fun(n));
    printf("%d\n",fibon_recursive_fun(n));
    printf("%d",fibon(n));
}

int fibon_fun(int a)
{
    int thisitem;
    int back1item;
    int back2item;
    if ( a==0)
        return 0;
    else if (a==1)
        return 1;
    else
    {
        back1item=1;
        back2item=0;
        for(int i; i< a;i++)
        {
            thisitem=back1item+back2item;
            back2item=back1item;
            back1item=thisitem;
        }
        return thisitem;
    }
}

int fibon_recursive_fun(int b)
{
    
    if(b==1 || b==0)
        return 1;
    else
    {
        return fibon_recursive_fun(b-1)+fibon_recursive_fun(b-2);
    }
    
}

int fibon(int n)
{
    int ans;
    if(n == 0 || n==1)
        ans=1;
    else
        ans = fibon(n-1)+fibon(n-2);
    return(ans);
}