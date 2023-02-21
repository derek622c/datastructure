#include <stdio.h>
#include <stdlib.h>

int fibonacci(int);
int nonre_fibonacci(int);

int main(void)
{   
    int f;
    int nf;
    //f=fibonacci(40);
    //printf("%d\n",f);
    nf=nonre_fibonacci(10);
    f=fibonacci(10);
    
    printf("%d \n",nf);
    printf("%d \n",f);
    return 0;
}

//recursive
int fibonacci(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else 
        return fibonacci(n-1) + fibonacci(n-2);
}


//non-recursive
int nonre_fibonacci(int n)
{
    int prev1,prev2,item,i;
    if(n==0)
        return 0;
    else if (n==1)
        return 1;
    else
    {
        prev2=0;
        prev1=1;
        for(i=2;i<=n;i++)
        {
            item=prev1+prev2;
            prev2=prev1;
            prev1=item;
        }
    }
    return item ;
}