#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *front=NULL, *rear=NULL;
void enqueue(int);
void dequeue();
void peek();
void display();
int main()
{
    int n, x;
    printf("enter 1 to insert element\n");
    printf("enter 2 to delete element\n");
    printf("enter 3 to print front element\n");
    printf("enter 4 to display element\n");
    printf("enter 5 to exit\n");
    scanf("%d",&n);
    while(n!=5)
    {
        switch(n)
        {
            case 1:scanf("%d",&x);
                    enqueue(x);
                    break;
            case 2:dequeue();
                    break;
            case 3:peek();
                    break;
            case 4:display();
                    break;
        }
        scanf("%d",&n);
    }
}
void enqueue(int x)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}
void dequeue()
{
    struct node *temp;
    temp=front;
    if(front==NULL && rear==NULL){printf("underflow\n");}
    else if(front==rear){printf("%d",temp->data);front=rear=NULL;free(temp);}
    else{printf("%d\n",temp->data);front=front->next;rear->next=front;free(temp);}
}
void peek()
{
    if(front==NULL && rear==NULL){printf("queue is empty\n");}
    else{printf("%d\n",front->data);}
}
void display()
{
    struct node *temp;
    if(front==NULL && rear==NULL){printf("empty queue\n");}
    else{temp=front;
        while(temp->next!=front)
            {printf("%d\n",temp->data);
            temp=temp->next;}
            printf("%d\n",temp->data);
    }
}
