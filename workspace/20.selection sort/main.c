#include <stdio.h>
#include <stdlib.h>
int min(int *a,int n,int i);
int main()
{
    printf("size of array\n");
    int n,i,j,pos,k;
    scanf("%d",&n);
    int a[n];
    printf("enter elements of array\n");
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        pos=min(&a[0],n,i);
        j=a[i];
        a[i]=a[pos];
        a[pos]=j;
    }
    printf("sorted array is:\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    return 0;
}
int min(int *a,int n,int i)
{
    int m=a[i],j,pos=i;
    for(j=i+1;j<n;j++)
    {
        if(a[j]<m)
        {
            m=a[j];
            pos=j;
        }
    }
    return pos;
}
