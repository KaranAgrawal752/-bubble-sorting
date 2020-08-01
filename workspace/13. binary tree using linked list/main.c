#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *create();
void preorderdisplay(struct node *);
void postorderdisplay(struct node *);
void inorderdisplay(struct node *);
int main()
{
    int n;
    struct node *root;
    root=NULL;
    printf("1 to create(in preorder manner)\n");
    printf("2 to display(in preorder manner)\n");
    printf("3 to display(in postorder manner)\n");
    printf("4 to display(in inorder manner)\n");
    printf("5 to exit\n");
    scanf("%d",&n);
    while(n!=5)
    {
        switch(n)
        {
            case 1:root=create();
                    break;
            case 2:preorderdisplay(root);
                    break;
            case 3:postorderdisplay(root);
                    break;
            case 4:inorderdisplay(root);
                    break;
        }
        scanf("%d",&n);
    }
    return 0;
}
struct node *create()
{
    struct node *newnode;
    int x;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter data(-1 to stop)\n");
    scanf("%d",&x);
    if(x==-1)return 0;
    newnode->data=x;
    printf("enter left child %d\n ",x);
    newnode->left=create();
    printf("enter right child %d\n ",x);
    newnode->right=create();
    return newnode;
}
void preorderdisplay(struct node *node)
{
    printf("->%d\n",node->data);
    if(node->left==NULL){}
    else{
        preorderdisplay(node->left);
    }
    if(node->right==NULL){}
    else{
        preorderdisplay(node->right);
    }
}
void inorderdisplay(struct node *node)
{
    if(node==NULL){return;}
    inorderdisplay(node->left);
    printf("->%d\n",node->data);
    inorderdisplay(node->right);
}
void postorderdisplay(struct node *node)
{
    if(node==NULL){return;}
    postorderdisplay(node->left);
    postorderdisplay(node->right);
    printf("->%d\n",node->data);
}
