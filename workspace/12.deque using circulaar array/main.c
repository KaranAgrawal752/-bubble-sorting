#include <stdio.h>
#include <stdlib.h>
#define N 5
int deque[N],f=-1,r=-1;
void enqueuefront(int);
void enqueuerear(int);
void dequeuefront();
void dequeuerear();
void display();
void getfront();
void getrear();
int main()
{
    int n,x;
    printf("1 to insert at front\n");
    printf("2 to insert at rear\n");
    printf("3 to delete at front\n");
    printf("4 to delete at rear\n");
    printf("5 to display\n");
    printf("6 to get front value\n");
    printf("7 to get rear value\n");
    printf("8 to exit\n");
    scanf("%d",&n);
    while(n!=8)
    {
        switch(n)
        {
        case 1:scanf("%d",&x);
               enqueuefront(x);
               break;
        case 2:scanf("%d",&x);
               enqueuerear(x);
               break;
        case 3:dequeuefront();
                break;
        case 4:dequeuerear();
                break;
        case 5:display();
                break;
        case 6:getfront();
                break;
        case 7:getrear();
                break;
        }
        scanf("%d",&n);
    }
    return 0;
}
void enqueuefront(int x)
{
    if((f==0&&r==N-1)||(f==r+1))printf("overflow\n");
    else if(f==-1 && r==-1){f=r=0;deque[f]=x;}
    else if(f==0){f=N-1;deque[f]=x;}
    else{f--;deque[f]=x;}
}
void enqueuerear(int x)
{
    if((f==0&&r==N-1)||(f==r+1))printf("overflow\n");
    else if(f==-1 && r==-1){f=r=0;deque[r]=x;}
    else if(r==N-1){r=0;deque[r]=x;}
    else{r++;deque[r]=x;}
}
void dequeuefront()
{
    if(f==-1&&r==-1)printf("deque is empty\n");
    else if(f==r){f=-1;r=-1;}
    else if(f==N-1){f=0;}
    else{f++;}
}
void dequeuerear()
{
    if(f==-1&&r==-1)printf("deque is empty\n");
    else if(f==r){f=-1;r=-1;}
    else if(r==0){r=N-1;}
    else{r--;}
}
void display()
{
    int i=f;
    while(i!=r)
    {
        printf("%d\n",deque[i]);
        i=(i+1)%N;
    }
    printf("%d",deque[r]);
}
void getfront()
{
    if(f==-1&& r==-1)printf("empty deque\n");
    else printf("%d\n",deque[f]);
}
void getrear()
{
    if(f==-1&& r==-1)printf("empty deque\n");
    else printf("%d\n",deque[r]);
}
