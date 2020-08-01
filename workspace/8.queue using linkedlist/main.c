#include <stdio.h>
#include <stdlib.h>
#define N 5
int s1[N],s2[N],top1=-1,top2=-1,count=0;
void push1(int);
void push2(int);
int pop1();
int pop2();
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
    push1(x);
    count++;
}
void dequeue()
{
    int i,a,b;
    if(top1==-1)printf("queue is empty\n");
    else{
        for(i=0;i<count;i++)
        {
            a=pop1();
            push2(a);
        }
        b=pop2();
        printf("%d\n",b);
        count--;
        for(i=0;i<count;i++)
        {
            a=pop2();
            push1(a);
        }
    }
}
void peek()
{
    printf("%d",s1[top1]);
}
void display()
{
    for(int i=0;i<=top1;i++)
    {
        printf("%d\n",s1[i]);
    }
}
void push1(int x)
{
    if(top1==N-1){printf("overflow\n");}
    else{
        top1++;
        s1[top1]=x;
    }
}
int pop1()
{
    return s1[top1--];
}
int pop2()
{
    return s2[top2--];
}
void push2(int x)
{
    if(top2==N-1){printf("overflow\n");}
    else{
        top2++;
        s2[top2]=x;
    }
}
