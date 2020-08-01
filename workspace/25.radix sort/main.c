#include <stdio.h>
#include <stdlib.h>
int maximum(int *a,int n);
void radixsort(int *a,int n);
void countsort(int *a,int n,int pos);
int main()
{
    int n;
    printf("size of array\n");
    scanf("%d",&n);
    int a[n],i;
    printf("enter elements in array\n");
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    radixsort(a,n);
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
void countsort(int *a, int n,int pos)
{
    int b[n],count[10]={},i;
    for(i=0;i<n;i++) count[(a[i]/pos)%10]++;
    for(i=1;i<10;i++)count[i]=count[i]+count[i-1];
    for(i=n-1;i>=0;i--)b[--count[(a[i]/pos)%10]]=a[i];
    for(i=0;i<n;i++)a[i]=b[i];
}
void radixsort(int *a,int n)
{
    int max=maximum(a,n),pos;
    for(pos=1;(max/pos)>0;pos=pos*10)
        countsort(a,n,pos);
}
