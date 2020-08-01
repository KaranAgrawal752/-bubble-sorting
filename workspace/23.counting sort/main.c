#include <stdio.h>
#include <stdlib.h>
int maximum(int *,int);
int main()
{
    int n;
    printf("size of array\n");
    scanf("%d",&n);
    int a[n],i,k;
    printf("enter elements in array\nplease enter positive integer\n");
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    k=maximum(a,n);
    int b[n],count[k];
    for(i=0;i<=k;i++)count[i]=0;
    for(i=0;i<n;i++) count[a[i]]++;
    for(i=1;i<=k;i++)count[i]=count[i]+count[i-1];
    for(i=n-1;i>=0;i--)b[--count[a[i]]]=a[i];
    for(i=0;i<n;i++)a[i]=b[i];
    for(i=0;i<n;i++) printf("%d\n",a[i]);
}
int maximum(int *a,int n)
{
    int max;
    max=a[0];
    for(int i=0;i<n;i++)
        if(max<a[i]) max=a[i];
    return max;
}
