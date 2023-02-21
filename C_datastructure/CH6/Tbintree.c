#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*定義資資料結構
rbit=1,rchild為正常指標,rbit = 0,rchild為引線*/

struct tbintree
{
    int number;
    int rbit;
    int lbit;
    struct tbintree *rchild;
    struct tbintree *lchild;
} *root, *ptr, *newnode;

typedef struct tbintree Node_type;
struct tbintree *newtbintree();//配置記憶函數
void insert();
void deleteNode();
void inorderShow(Node_type *);
void insertRight(Node_type *, Node_type *);
void insertLeft(Node_type *, Node_type *);

void flushBuffer(void);
Node_type *insucc(Node_type *);
Node_type *inpred(Node_type *);

int main()
{
    char *MenuPrompt=
    "===Thread Binary Search Program==\n"
    " 1.Insert\n"
    " 2.Delete\n"
    " 4.Show\n"
    " 5.Quit\n"
    " Enter your choice: ";
    int menusele;
    
    
    //初始化
    //根節點不放資料root->number不放data,右鍵結永遠指向本身rbit=1
    root = newtbintree();
    root->lchild = root;//***
    root->rchild = root;
    root->lbit = 0;
    root->rbit = 1;//指向本身


    do
    {   
        printf("\n%s",MenuPrompt);
        scanf("%d",&menusele);
        flushBuffer();
        switch(menusele)
        {
            case'1':
                insert();
                break;
            case '2':
                deleteNode();
                break;
            case '3':
                inorderShow(root);
                break;
            case '4':
                puts("bye ^ ^");
                exit(1);
            default:
                puts("invalid choice");
        }
    } while (1);
    printf("\n");
    return 0;
}

void insert()
{
    newnode = newtbintree();
    printf("\n Enter a number to insert: ");
    scanf("%d", &newnode->number);
    flushBuffer();

    //左邊為引線
    if(root->lchild == root)
    {
        insertLeft(root, newnode);
        printf("Node %d has been inserted",newnode->number);
    }
    
    else
    {
        ptr = root->lchild;
        while(ptr->number != root->number)
        {
            //新節點小於目前節點且lbit=0(lchild為引線),則插入目前節點左方,否則ptr往左搜尋
            if(newnode->number < ptr->number )
            {
                if (ptr->lbit==0)
                {
                    insertLeft(ptr, newnode);
                    break;
                }
            
                else 
                    ptr = ptr->lchild;
            }
            else if (newnode->number > ptr->number)
            {
                if(ptr->rbit == 0)
                {
                    insertRight(ptr,newnode);
                    break;
                }
                else
                    ptr = ptr->rchild;
            }
        }
        if(ptr->number == newnode->number)
        {
            puts("Number existed...!");
            return;
        }
        else
            printf("Node %d has been inserted\n",newnode->number);
    }
}

void insertRight(Node_type *nodeParent, Node_type *node)
{
    Node_type *w;
    node->rchild = nodeParent->rchild;
    node->lchild = nodeParent;
    node->rbit = nodeParent->rbit;
    node->lbit = 0;
    nodeParent->rbit = 1;
    nodeParent->rchild = node;
    if (node->rbit == 1)//node 底下還有tree
    {
        w=insucc(node);
        w->lchild = node;
    }          
}

void insertLeft(Node_type *nodeParent, Node_type *node)
{
    Node_type *w;
    node->lchild = nodeParent->lchild;
    node->rchild = nodeParent;
    node->lbit = nodeParent->lbit;
    node->rbit = 0;
    nodeParent->lbit =1;
    nodeParent->lchild = node;
    
    if(node->lbit==1)// node底下還有tree(在左邊)所以用pred
    {
        w=inpred(node);
        w->rchild =node;
    }
}


//中序追蹤顯示節點函數
void inorderShow(Node_type *node)
{
    if(node->lchild == root)
    {
        puts("no data");
        return;
    }
    puts("\n Inorder display thread binary search tree");
    ptr=root;
    do
    {
        ptr=insucc(ptr);
        if(ptr != root)
            printf("%-5d",ptr->number);
    }while(ptr!=root);
    puts("\n--------");
}