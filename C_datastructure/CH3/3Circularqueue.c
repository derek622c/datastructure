#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 5
void enqueue_fun(void);
void dequeue_fun(void);
void list_fun(void);
char item[Max][20];
int front = Max-1;
int rear = Max-1;
int flag = 0;
int i = 0;

int main()
{
    char option;
    while(1)
    {
        printf("\n\n--------------\n");
        printf("(1)insert (enqueue)\n");
        printf("(2)delete (dequeue)\n");
        printf("(3)list \n");
        printf("(4)quit \n");
        printf("**************\n");
        printf("please enter your choice:");
        option = getchar();

        while(getchar() != '\n')
            continue;
        switch(option)
        {
            case '1':
                enqueue_fun();
                break;
            case '2':
                dequeue_fun();
                break;
            case '3':
                list_fun();
                break;
            case '4':
                exit(0);
        }
    }
}

void enqueue_fun(void)
{
    if(front==rear && flag==1)
        printf("stack is full\n");
    else
    {
        rear=(rear+1)%Max;
        printf("\nplease enter item to insert:");
        scanf("%s",item[rear]);
        while(getchar() != '\n')
            continue;
        if(front==rear)
            flag=1;
    }
}

void dequeue_fun(void)
{
    if(front == rear && flag==0)
        printf("stack is empty");
    else
    {   
        front = (front+1)%Max;
        printf("\n item %s deleted",item[front]);
        strcpy(item[front],"\0");//複製結束\0到front的位置(要刪除的位置)表示結束
        if(front == rear)
            flag=0;
    }

}

void list_fun(void)
{
    int count = 0;
    int i;
    if (front==rear && flag==0)
        printf("queue is empty\n");
    else
    {
        printf("\n**item**\n");
        printf("------------\n");

        i = (front+1)%Max;
        while(i != front || i==rear)
        {
            if(strcmp(item[i],"\0") != 0 )
            {
                printf(" %-20s\n", item[i]);
                count++;
            }
            if(count >= Max)
                break;
            ++i;
            i=i%Max;
        }
        printf("-----------\n");
        printf("total item:%d\n",count);
    }
}