#include <stdio.h>
#include <stdlib.h>

int main()
{
    int  i,pos=-1,val, a[10];
    for(i=0;i<10;i++)
        a[i]=3*i+8;
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n enter element want to search");
    scanf("%d",&val);
    int end=9, beg=0,med;
    while(beg<=end)
    {
        med=beg+(end-beg)*((val-a[beg])/(a[end]-a[beg]));
        if(a[med]==val)
        {
            pos=med;
            printf("position is %d",pos);
            break;
        }
        else if(val<a[med])
            end=med-1;
        else
            beg=med+1;
    }
    if(pos==-1)
        printf("element is not present");
}
