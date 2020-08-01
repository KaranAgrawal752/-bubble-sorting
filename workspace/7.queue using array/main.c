#include <stdio.h>
#include <stdlib.h>
#define N 5
int queue[N];
int front=-1, rear=-1;
void enqueue(int x);
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
    if(rear==N-1){printf("overflow\n");}
    else if(front==-1 && rear==-1){
        front=0, rear=0;
        queue[0]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1){printf("underflow\n");}
    else if(front==rear){printf("%d",queue[front]);front=rear=-1;}
    else{printf("%d\n",queue[front]);front++;}
}
void peek()
{
    int z;
    if(front==-1 && rear==-1){printf("queue is empty\n");}
    else{printf("%d\n",queue[front]);}
}
void display()
{
    if(front==-1 && rear==-1){printf("empty queue\n");}
    else{
        for(int i=front;i<=rear;i++)
            printf("%d\n",queue[i]);
    }
}
