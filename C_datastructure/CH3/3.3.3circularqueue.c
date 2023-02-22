#include <stdio.h>
#include <stdlib.h>

//original queue initial rear=-1,front=0
//rear+1 才能放值 ,front 去值再扣1
void enqueue()
{
    //Max 初值-1
    int rear,front;
    int Max;
    int q[10];
    if(rear >= Max-1)
        printf("is full");
    else
        rear++;
        printf("please enter a item:");
        scanf("%d",&q[rear]);
}

void dequeue()
{
    int rear,front;
    int Max;
    int q[10];
    if(front >= rear)
        printf("is empty");
    else  
        printf("%d is delete",q[front]);
        front++;
}

//環狀佇列加入,front,rear,初值設為=Max-1
//rear 必須先加一再填值
void CQenqueue(void)
{
    int rear,front;
    int Max;
    int cq[10];
    rear=(rear+1)%Max;
    if(rear==front)
        printf("is full");
    else
        printf("enter a item");
        scanf("%d",&cq[rear]);
}

//環狀佇列的刪除
//front 必須先去值在加一
void CQdequeue_f(void)
{
    int front,rear,Max;
    int cq[10];
    if(front == rear)
        printf("\n\n Queue is empty");
    else
        front = (front + 1) % Max;
        printf("\n\n Item %d deleted",cq[front]);         
}