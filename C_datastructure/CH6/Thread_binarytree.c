#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int rbit;
    int lbit;
    struct node *llink;
    struct node *rlink;
};

typedef struct node Node_type;

//搜尋引線二元樹節點的中序後繼者
Node_type *insuc(Node_type *ptr)
{
    Node_type *current;
    current = ptr->rlink; 
    if(ptr->rbit == 1) //查看thread
        while (current->lbit == 1)
            current = current->llink;
    //else
    return current;
}

//追蹤引線二元數的中序前行者
Node_type *pred(Node_type *ptr)
{
    Node_type *current;
    current = ptr->llink;
    if(ptr->lbit==1)
        while (current->rbit==1)
            current=current->rlink;
    return current;
}

//找到全部（引線二元數追蹤 ）
void tinorder(Node_type *tree,Node_type *ptr)
{
    Node_type *head;
    tree = head;
    printf("%d",tree->data);
    for(;;)
    {
        tree = insuc(tree);
        if(tree == head)
            return;
        printf("%d",tree->data);
    }
}

//node 為要插入的數, node_parent 要被插入的數
void insert_right(Node_type *node_parent,  Node_type *node)
{
    Node_type *w; 
    node->rlink = node_parent->rlink;
    node->rbit = node_parent->rbit;
    node->llink = node_parent;
    node->lbit = 0;
    node_parent->rbit = 1;//用來填入新值
    if(node->rbit == 1)
    {
        w=insuc(node);//追蹤後記者函數
        w->llink = node;
    }
}

void insert_left(Node_type *node_parent, Node_type *node)
{
    Node_type *w;
    node->llink = node_parent->llink;
    node->lbit = node_parent->lbit;
    node->rlink = node_parent;
    node->rbit = 0; // thread 表空可填入
    node_parent->lbit = 1;
    if(node->lbit==1)
    {
        w = pred(node);
        w->rlink = node;
    }    
}

