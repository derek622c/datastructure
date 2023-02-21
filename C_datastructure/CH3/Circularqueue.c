#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 5

void enqueue_fun(void);
void dequeue_fun(void);
void list_fun(void);

char item[Max][20];
int front=Max-1;
int rear=Max-1;
int flag=0;
int i=0;

int main()
{
    char option;
    while(1)
    {
        printf("\n***********\n");
        printf("   (1)insert push)\n");
        printf("   (2)delete (pop) \n");
        printf("   (3)list  \n");
        printf("   (4)(quit)   \n");
        printf("**************");
        printf("please enter your choice...");
        option=getchar();
        
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
    if(front == rear && flag==1)
        printf("nQueue is full\n");
    else
    {
        rear=(rear+1) % Max;
        printf("\nplease enter a item\n");
        scanf("%s",item[rear]);
        while(getchar()!='\n')
            continue;
        if(front == rear) 
            flag=1;
    }

}
void dequeue_fun(void)
{
    if(front==rear && flag==0)
        printf("\n no item, queue is empty\n");
    else
    {    
        front=(front+1)%Max;
        printf("\n %s item is delete ",item[front]);
        strcpy(item[front], "\0");
        if(front == rear)
            flag=0;
    }   
}
void list_fun(void)
{
    int count=0;
    int i;
    if(front==rear && flag==0)
        printf("no item, queue is empty\n");
    else
    {
        printf("\n***Item***\n");
        printf("-----------");
        i=(front+1)%Max;
        while(i !=front || i==rear )
        {
            if(strcmp(item[i], "\0") != 0)
            {
                printf("\n %20s \n",item[i]);
                count++;
            }
            if (count >= Max)
                break;
            ++i;
            i=i%Max;
        }
        printf("-----------");
        printf("total item:%d\n",count);
    }
}