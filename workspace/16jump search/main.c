#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int  i,pos=-1,val,n;
    printf("enter no of elements in array");
    scanf("%d",&n);
    int a[n];
    printf("please enter sorted array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf(" enter element want to search");
    scanf("%d",&val);
    int end=n, beg=0,step;
    step=sqrt(n);
    for(i=0;i<n;i=i+step)
    {
        if(val==a[i])
        {
            pos=i;
            printf("position of element %d",pos);
            break;
        }
        else if(val>a[i])
            beg=i+1;
        else
            end=i-1;
    }
    if(pos==-1)
   {for(i=beg;i<=end;i++)
    {
        if(a[i]==val)
        {
            pos=i;
            printf("%d",pos);
            break;
        }
    }}
    if(pos==-1)
        printf("element is not present");
}
