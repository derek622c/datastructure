#include <stdio.h>
#include <stdlib.h>
int *  twoSum ( int *  nums , int  numsSize , int  target , int *  returnSize );
int returnSize;
int main(void)
{
    int nums[]={2,7,11,15};
    int target=9;
    returnSize=2;
    int *ptr=&returnSize;
    int a[2];
    int *ptr2=a;
    ptr2=twoSum(nums,2,target,ptr);
    printf("%d\n",ptr2);
}

int *  twoSum ( int *  nums , int  numsSize , int  target , int *  returnSize ) 
{ 
static  int  result [ 2 ] = { 0 }; //static修飾後，return的地址才能被main接收
for ( int  i  =  0 ; i  <  numsSize  -  1 ; i ++ ) 
    { 
for ( int  j  =  i+ 1 ; j  <  numsSize ; j ++ ) 
        { 
if ( nums [ i ] +  nums [ j ] ==  target ) 
            { 
result [ 0 ] =  i ; 
result [ 1 ] =  j ; 
//* returnSize  =  2 ; //這個不能刪除
return  result ; 
            } 
        } 
    } 
return 0 ; 
}