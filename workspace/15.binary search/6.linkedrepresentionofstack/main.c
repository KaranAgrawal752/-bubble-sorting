#include <stdio.h>
#include <malloc.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *start=NULL;
struct stack *push(struct stack *,int);
struct stack *pop(struct stack *);
int peek(struct stack *);
struct stack *display(struct stack *);
int main()
{
    int option ,val;
    printf("****MENU****\n");
    printf("enter 1:to add top element\n");
    printf("enter 2:to delete top element\n");
    printf("enter 3:to display top element\n");
    printf("enter 4:to display all element\n");
    printf("enter 5:to exit\n");
    scanf("%d",&option);
    while(option!=5)
    {
        switch(option)
        {
            case 1:printf("enter the value\n");
                    scanf("%d",&val);
                    start=push(start,val);
                    break;
            case 2:start=pop(start);
                    break;
            case 3:val=peek(start);
                    if(val!=-1)
                        printf("the top value is %d \n",val);
                    else
                        printf("stack is empty\n");
                    break;
            case 4:start=display(start);
                    break;
        }
        scanf("%d",&option);
    }
    return 0;
}
struct stack *push(struct stack *start, int val)
{
    struct stack *ptr;
    ptr = (struct stack*)malloc(sizeof(struct stack));
    ptr->data=val;
    if(start==NULL)
    {
        start=ptr;
        ptr->next=NULL;
    }
    else
    {
        ptr->next=start;
        start=ptr;
    }
    return start;
}
struct stack *pop(struct stack *start)
{
    struct stack *ptr;
    ptr=start;
    if(ptr==NULL)
        printf("stack is underflow\n");
    else{
        start=ptr->next;
        printf("%d is deleted\n",ptr->data);
        free(ptr);
    }
    return start;
}
int peek(struct stack *start)
{
    if(start==NULL)
        return -1;
    else
        return start->data;
}
struct stack *display(struct stack *start)
{
    struct stack *ptr;
    ptr=start;
    if(ptr==NULL)
        printf("stack is empty \n");
    else
    {
        while(ptr!=NULL)
        {
            printf("->%d",ptr->data);
            ptr=ptr->next;
        }
    }
    return start;
}
