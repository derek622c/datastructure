#include <iostream>
using namespace std;

int fibonacci(int);
int nonre_fibonacci(int);

int main()
{
    int f;
    int nf;
    f=fibonacci(10);
    nf=nonre_fibonacci(10);
    cout << f<< endl;;
    cout << nf<< endl;
    
}


int fibonacci(int n)
{
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2); 
}

int nonre_fibonacci(int n)
{
    int prev1=1;
    int prev2=0; 
    int sum;
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    else
    {
        for(int i=2;i<=n;i++)
        {
            sum = prev1+prev2;
            prev2=prev1;
            prev1=sum;
        }
    }
    return sum;

    
}