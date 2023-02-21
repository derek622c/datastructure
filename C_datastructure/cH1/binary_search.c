#include <stdio.h>
#include <stdlib.h>
#define Max 10
void binsrch(int *,int ,int);
int main()
{
    int A[Max]={1,3,5,7,11,13,17,19,23,29};//binary search 只用在排好順序的陣列(可先用氣泡排序法排列)
    binsrch(A,Max,19);
}
void binsrch(int A[],int n,int x)
{
    int lower=1;
    int upper=n;
    int mid;
    while(lower <= upper)
    {
        mid=(lower+upper)/2;
        if(x>A[mid])
            lower=mid+1;
        else if(x<A[mid])
            upper=mid-1;
        else
        {
            printf("%d is at A[%d]\n",x,mid);
            return;
        }
    }
}