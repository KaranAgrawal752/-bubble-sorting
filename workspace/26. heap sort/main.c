#include <stdio.h>
#include <stdlib.h>
void heapsort(int *, int);
void maxheapify(int *,int, int);
int main()
{
    int n;
    printf("size of array\n");
    scanf("%d",&n);
    int a[n],i;
    printf("enter elements in array\nplease enter positive integer\n");
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    heapsort(a,n);
    for(i=0;i<n;i++) printf("%d\n",a[i]);
}
void heapsort(int *a,int n)
{
    int i=0,t;
    for(i=n/2-1;i>=0;i--) maxheapify(a, n,i);
    for(i=n-1;i>=0;i--)
    {
        t=a[i];
        a[i]=a[0];
        a[0]=t;
        maxheapify(a,i,0);
    }
}
void maxheapify(int *a,int n,int i)
{
    int largest=i,t;
    int l=2*i+1,r=(2*i)+2;
    while(l<n && a[l]>a[largest]) largest=l;
    while(r<n && a[r]>a[largest]) largest=r;
    if(largest!=i)
    {
        t=a[largest];
        a[largest]=a[i];
        a[i]=t;
        maxheapify(a,n,largest);
    }
}
