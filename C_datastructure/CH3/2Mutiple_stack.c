#include <stdio.h>
#include <stdlib.h>

#define MAX 10 
#define Unit 5
void push_function(int number1);
void pop_function(int number2);
void listfunction(int number3);

char MS[MAX][20];
int t[(MAX/Unit)],b[(MAX/Unit)];

int main()
{
    int option,i;
    int number1,number2,number3;
    for(i=0;i<=Unit-1;i++)
    {
        if(Unit-1==1)
        {
            t[i+1] = MAX-1;
            b[i+1] = MAX-1;;
            t[i] = i*(MAX/Unit)-1;
            b[i] = i*(MAX/Unit)-1;
        }
        else
        {
            t[i]=i*(MAX/Unit)-1;
            b[i]=i*(MAX/Unit)-1;
        }
    }
    while(1)
    {
        printf("\n*****************\n");
        printf("   (1)insert (push)\n");
        printf("   (2)delete (pop) \n");
        printf("   (3)list \n");
        printf("   (4)quit \n");
        printf("*******************\n");
        printf("please enter your chioce...");
        //option=getchar();
        scanf("%d",&option);
        //gets(option);
        switch(option)
        {
            case 1:
                printf("the total number of stack is %d \n",Unit);
                printf("please enter the number of stack? ");
                //gets(number1);
                scanf("%d",&number1);
                if(number1>Unit)
                    printf("the number is out of stack total number");
                else
                    push_function(number1);
                break;
            case 2:
                printf("\n please enter a number of stack");
                scanf("%d",&number2);
                if (number2 > Unit)
                    printf("the number is out of stack total number");
                else    
                    pop_function(number2);
                break;
            case 3:
                printf("\n please enter a number of stack");
                scanf("%d",&number3);
                if (number3 > Unit)
                    printf("the number is out of stack total number");
                else
                    listfunction(number3);
                break;
            case 4:
                printf("\n");
                return 0;
        }
    }
}

void push_function(int number1)
{
    if( t[number1-1] == b[number1] )
    {   
        printf("stack %d is full\n");
        printf("please choose another stack to insert");
    }
    else
    {
        printf("please enter item to insert:");
        scanf("%s", &MS[++t[number1-1]] );
        printf("you insert %s to %d stack!!\n",MS[t[number1-1]], number1);
    }
}

void pop_function(int number2)
{
    if(t[number2-1] == b[number2-1])
        printf("\n stack%d is empty",number2);
    else
    {
        printf("the item %s on stack%d is deleted",MS[t[number2-1],number2]);
        t[number2-1]--;
    }
}

void listfunction(int number3)
{
    int count=0,i,startnumber;
    if(t[number3-1] == b[number3-1])
        printf("\n no item,stack is empty");
    else 
    {
        startnumber = (number3-1)*(MAX/Unit)-1;
        printf("\n  Item\n");
        printf("-------------\n");
        for(i=startnumber+1; i<t[number3-1]; i++)
        {    
            printf("   %-20s \n",MS[i]);
            count++;
        }
        printf("-----------");
        printf("total item: %d",count);


    }

}
