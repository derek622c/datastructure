#include <iostream>
#define Max 10
using namespace std;
void binserch(int ,int,int[]);

int main()
{
    int A[Max]={1,3,5,7,11,13,17,19,23,29};
    binserch(Max,19,A);
    return 0;
}

void binserch(int n,int num,int A[])
{
    int lower = 1;
    int upper = n;
    int mid;
    while(lower <= upper) 
    {
        mid =(lower+upper)/2;
        if(num > A[mid])
            lower = mid;
        else if (num < A[mid])
            upper = mid;
        else
        {
            cout<< num << " is at A["<<mid<<"]"<<endl;
            return;
        }
    }
}


