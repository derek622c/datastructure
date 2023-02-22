#include <stdio.h>
#include <stdlib.h>

void insert_fun();
void sort_fun();
void delete_fun();
void display_fun();
void modify_fun();
void flush_buffer();

struct student
{
    char name[20];
    int score;
    struct student *next;
};

struct student *ptr, *head, *current, *prev;

int main()
{
    head =(struct student*) malloc(sizeof(struct student));
    head->next = NULL;
    char option;
    while(1)
    {
        printf("\n");
        printf("*****************");
        printf("(1) insert\n");
        printf("(2) delete\n");
        printf("(3) display\n");
        printf("(4) modify\n");
        printf("(5) quit\n");

        option=getchar();
        flush_buffer();
        switch (option)
        {
            case '1':
                insert_fun();
                break;
            case '2':
                delete_fun();
                break;
            case '3':
                display_fun();
                break;
            case '4':
                modify_fun();
                break;
            case '5':
                exit(0);
        }
    }   
}

void insert_fun()
{
    ptr=(struct student*) malloc(sizeof(struct student));
    printf("student name:");
    scanf("%s",ptr->name);
    printf("student score");
    scanf("%d",ptr->score);
    flush_buffer();
    sort_fun();
}

void sort_fun()
{
    prev = head;
    current = head->next;
    while( current->next!=0 && prev->score > ptr->score)
    {
        prev->next=current;
        current=current->next;
    }
    ptr->next=current;
    prev->next=ptr;
}

void delete_fun()
{
    char delName[20];
    printf("Delete student name:");
    scanf("%s",delName);
    flush_buffer();
    
    prev=head;
    current=head->next;
    while( current->next!=0 && prev->score > ptr->score)
    {
        prev->next=current;
        current=current->next;
    }
    if(current != NULL)
    {
        prev->next=current->next;
        free(current);
        printf("student %s has been deleted\n",delName);
    }
    else
        printf("stduent %s is not found\n",delName);
}

void modify_fun()
{
    char nTemp[20],sTemp[4];
    printf("modify student name :");
    scand("%s", nTemp);
    flush_buffer();
    prev=head;
    current = head->next;
    while(current->next != NULL  &&  prev->score > p
}