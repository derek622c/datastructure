#include <stdio.h>
#include <stdlib.h>

int gcd(int m,int n);
int gcdf(int m,int n);

int main()
{
    int a=168;
    int b=200;
    int c;
    c=gcd(a,b);
    printf("%d",c);
}


int gcd(int m,int n)
{
    int temp;
    temp = m%n;
    if(temp==0)
        return n;
    else
    {
        m=n;
        n=temp;
        gcd(m,n);
    }
}