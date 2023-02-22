#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node Node_type;


void inorder(Node_type *tree)
{
    if(tree != NULL)
    {
        inorder(tree->llink);
        printf("%d",tree->data);
        inorder(tree->rlink);
    }       
}

void preorder(Node_type *tree)
{
    if(tree != NULL)
    {
        printf("%d", tree->data);
        preorder(tree->llink);
        preorder(tree->rlink);
    }
}

void postorder(Node_type *tree)
{
    if(tree != NULL)
    {
        postorder(tree->llink);
        postorder(tree->rlink);
        printf("%d",tree->data);
    }
}