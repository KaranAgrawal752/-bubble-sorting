#include<bits/stdc++.h>
using namespace std;
void create();
void deleteElement(struct node *, int);
void insertElement(struct node *, struct node * );
void inorderdisplay(struct node *);
struct node
{
    int data;
    struct node * left, *right;
};
struct node * parent=NULL;
int flag;
struct node *root=NULL;
int main()
{
    int n,x;
    printf("1 to create\n");
    printf("2 to delete\n");
    printf("3 to insert\n");
    printf("4 to display(in inorder manner)\n");
    printf("5 to exit\n");
    scanf("%d",&n);
    while(n!=5)
    {
        switch(n)
        {
            case 1:create();
                    break;
            case 2:{cout<<"Enter elemnt want to be delete";
                    cin>>x;
                    parent=NULL; 
                    deleteElement(root,x);
                    break;}
            case 3:{cout<<"Enter element";cin>>x;
                    struct node *ptr=new node();
                    ptr->data=x;
                    ptr->left=NULL; ptr->right=NULL;
                    insertElement(root, ptr);}
                    break;
            case 4:inorderdisplay(root), cout<<"\n";
                    break;
        }
        scanf("%d",&n);
    }
    return 0;
}
void create()
{
    int d,x;
    cout<<"Enter root element ";
    cin>>d;
    root=(struct node *)malloc(sizeof(struct node));
    root->data=d;
    root->left=NULL;
    root->right=NULL;
    cout<<"Enter more elemnts and -1 to stop\n";
    while(1)
    {
        cin>>x;
        if(x==-1) break;
        struct node *ptr=new node();
        ptr->data=x;
        ptr->left=NULL, ptr->right=NULL;
        insertElement(root, ptr);
    }
}
void deleteElement(struct node *ptr, int x)
{
    if(ptr==NULL) { cout<<"element is not present in tree\n"; return;}
    if(ptr->data==x)
    {
        if(ptr->left==NULL && ptr->right==NULL) 
        {
            if(parent==NULL) root=NULL;
            else
            {if(flag==0) parent->right=NULL;
            else parent->left=NULL;}
            free(ptr);
            return;
        }
        if(ptr->right==NULL)
        {
            if(parent==NULL) root=ptr->left;
            else
            {if(flag==0) parent->right=ptr->left;
            else parent->left=ptr->left;}
            free(ptr);
            return;
        }
        if(ptr->left==NULL)
        {
            if(parent==NULL) root=ptr->right;
            else
            {if(flag==0) parent->right=ptr->right;
            else parent->left=ptr->right;}
            free(ptr);
            return;
        }
        if((ptr->right)->left==NULL) 
        {
            (ptr->right)->left=ptr->left;
            if(parent==NULL) root=ptr->right;
            else
            {if(flag==0) parent->right=ptr->right;
            else parent->left=ptr->right;}
            free(ptr);
            return;
        }
        struct node * temp=(ptr->right)->left, * pre=ptr->right;
        while(temp->left!=NULL) pre=pre->left, temp=temp->left;
        pre->left=temp->right;
        temp->right=ptr->right, temp->left=ptr->left;
        if(parent==NULL)   root=temp;
        else
        {if(flag==0) parent->right=temp;
        else parent->left=temp;}
        free(ptr);
        return;
    }
    else
    {
        parent=ptr;
        if(ptr->data < x) flag=0, deleteElement(ptr->right,x);
        else flag=1, deleteElement(ptr->left,x);
    }
}
void insertElement(struct node * var, struct node * ptr)
{
    if(ptr->data > var->data) 
    {
        if(var->right ==NULL)  var->right=ptr;
        else   insertElement(var->right, ptr);
    }
    else 
    {
        if(var->left==NULL)  var->left=ptr;
        else  insertElement(var->left, ptr);
    }
}
void inorderdisplay(struct node * ptr)
{
    /*if(ptr==NULL){return;}
    inorderdisplay(ptr->left);
    cout<<ptr->data<<" ";
    inorderdisplay(ptr->right);*/
    stack<node *> s;
    s.push(ptr);
    int t=0;
    while(!s.empty())
    {
        struct node *var=s.top();
        node * lt=var->left;
        if(lt != NULL && t==0)
        {
            s.push(lt);
            t=0;
            continue;
        }
        if(t==0 ||t==2) cout<<var->data<<" ";
        node * rt=var->right;
        if(rt != NULL && (t==0|| t==2))
        {
            s.push(rt);
            t=0;
            continue;
        }
        s.pop();
        if(!s.empty())
        {node *k=s.top();
        if(k->left==var) t=2;
        else t=1;}
    }
}