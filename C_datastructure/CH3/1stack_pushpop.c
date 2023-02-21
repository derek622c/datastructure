#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void push_function(void);
void pop_function(void);
void list_function(void);
char item[MAX][20];
int top = -1;

int main(void)
{
    char option;
    while(1)
    {
        printf("\n*****************\n");
        printf("   (1)insert (push)\n");
        printf("   (2)delete (pop) \n");
        printf("   (3)list \n");
        printf("   (4)quit \n");
        printf("*******************\n");
        printf("please enter your chioce...");
        option=getchar();

        while(getchar()!='\n')
            continue;
        
        switch(option)
        {
            case '1':
                push_function();
                break;
            case '2':
                pop_function();
                break;
            case '3':
                list_function();
                break;
            case '4':
                printf("\n");
                return 0;
        }
    }
}


void push_function(void)
{
    if(top >= MAX-1)
        printf("\n\n stack is full ");
    else
    {
        top++;
        printf("\n\nplease enter a item: ");
        //scanf("%s",item[top][20]);
        gets(item[top]);
    }
}

void pop_function(void)
{
    if(top<0)
        printf("\n\nstack is empty\n");
    else
    {    
        printf("\n\n %s in stack is deleted\n",item[top]);
        top--;
    }
}

void list_function(void)
{
    int i;int count=0;
    if (top<0)
        printf("stack is empty\n1");
    else 
    {
        printf("\n\n  item");
        printf("---------------\n");
        for(i=0;i<=top;i++)
        {
            printf("  %-20s\n",item[i]);
            count++;
        }
        printf("----------\n");
        printf("total item=%d\n",count);
    }
}   