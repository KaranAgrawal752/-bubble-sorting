#include <stdio.h>
#include <stdlib.h>
void check(int *,int,int);
int main()
{
    int n;
    printf("size of array\n");
    scanf("%d",&n);
    int a[n],i,g=n/2;
    printf("enter elements in array\n");
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(g=n/2;g>=1;g=g/2)
    {
        for(i=0;(i+g)<n;i++)
            check(a,i,g);
    }
    for(i=0;i<n;i++) printf("%d\n",a[i]);
}
void check(int *a, int i, int g)
{
    int t;
    if(a[i]>a[i+g])
    {
        t=a[i];
        a[i]=a[i+g];
        a[i+g]=t;
        if((i-g)>=0) check(a,i-g,g);
    }
}
