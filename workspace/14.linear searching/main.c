#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i ,n;
    scanf("%d",&n);
    int a[n];
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter element want to serach");
    int val,pos=-1;
    scanf("%d",&val);
    for(i=0;i<n;i++)
    {
        if(a[i]==val)
        {
            pos=i;
            printf("%d",pos);
            break;
        }
    }
    if(pos==-1)
        printf("this element is not present in array");
}
