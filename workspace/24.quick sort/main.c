#include <stdio.h>
#include <stdlib.h>
void quicksort(int *,int,int);
int partition(int *,int,int);
int main()
{
    int n;
    printf("size of array\n");
    scanf("%d",&n);
    int a[n],i,lb=0,ub=n-1;
    printf("enter elements in array\n");
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    quicksort(a,lb,ub);
    for(i=0;i<n;i++) printf("%d\n",a[i]);
}
void quicksort(int *a,int lb,int ub)
{
    if(lb<ub)
    {
        int l;
        l=partition(a,lb,ub);
        quicksort(a,lb,l-1);
        quicksort(a,l+1,ub);
    }
}
int partition(int *a,int lb, int ub)
{
    int pivot=a[lb],start=lb,end=ub;
    while(start<end)
    {
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end){
            int t=a[start];
            a[start]=a[end];
            a[end]=t;
        }
    }
    int t=a[lb];
    a[lb]=a[end];a[end]=t;
    return end;
}
