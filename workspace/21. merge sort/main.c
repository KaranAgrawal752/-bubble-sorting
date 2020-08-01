#include <stdio.h>
#include <stdlib.h>
void mergesort(int *,int,int);
void merge(int *,int, int,int);
int main()
{
    int n;
    printf("size of array\n");
    scanf("%d",&n);
    int a[n],i,lb=0,ub=n;
    printf("enter elements in array\n");
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    mergesort(a,lb,ub);
    for(i=0;i<n;i++) printf("%d\n",a[i]);
}
void mergesort(int *a,int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
merge(int *a,int lb,int mid,int ub)
{
    int i=lb, j=mid+1, k=lb,b[ub+1];
    while(i<=mid &&j<=ub)
    {
        if(a[i]<=a[j])
            b[k]=a[i],i++;
        else b[k]=a[j],j++;
        k++;
    }
    if(i>mid)
        while(j<=ub) b[k]=a[j],j++,k++;
    else while(i<=mid) b[k]=a[i],i++,k++;
    for(k=lb;k<=ub;k++) a[k]=b[k];
}
