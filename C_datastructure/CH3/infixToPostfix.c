#include <stdio.h>
#include <stdlib.h>

#define Max 20
void infixToPostfix(char [],int);
int compare(char,char);

char infixPriority[9] = {'#', ')', '+', '-', '*', '/', '^', ' ','('};
char stackPriority[8] = {'#', '(', '+', '-', '*', '/', '^', ' ',};


int main()
{
    int rear=-1;
    char infix[Max];
    printf("***********\n");
    printf("--usable operator--\n");
    printf("^: Exponentiation\n");
    printf("*: Multiply    /: Divided \n");
    printf("+: Add         -: Substraction \n");
    printf("(: Left Brace  ): Right Brace\n" );
    printf("************");
    printf("please enter infix expression:");
    while(infix[rear] != '\n')
        infix[++rear] = getchar();
    infix[rear] = '#'; // 結束加入＃
    printf("Postfix expression: ");
    infixToPostfix(infix, rear);
    printf("\n");
    return 0;
}

int compare(char stack,char infix)
{
    int indexs=0,indexi=0;
    while(stackPriority[indexs] != stack)
        indexs++;
    while(infixPriority[indexi] != infix)
        indexi++;
    return indexs/2 >= indexi/2 ? 1 : 0;
}

void infixToPostfix(char infix[],int rear)
{
    int top=0,ctr;
    char stackT[Max];//儲存運算子
    stackT[top]='#';//最底下加入
    for(ctr=0;ctr<=rear;ctr++)
    {
        switch (infix[ctr])
        {
            case ')':
                while (stackT[top] != '(')
                {
                    printf("%c", stackT[top--]);
                }
                top--;
                break;
            case '#':
                while(stackT[top] != '#')
                {
                    printf("%c",stackT[top--]);
                }
                break;
            case '(':
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                while(compare(stackT[top], infix[ctr]))
                {    
                    printf("%c",stackT[top--]);
                }
                stackT[++top] = infix[ctr];
                break;
            default:
                printf("%c",infix[ctr]);
                break;
        }
    }
}

