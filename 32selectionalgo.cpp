#include<bits/stdc++.h>
using namespace std;
using namespace std:: chrono;
int selection(long long int *,long long int,long long int,long long int );
int partition(long long int *,long long int,long long int);
int main()
{
    long long int n=100,k,val;
    printf("Enter which minimum you want:");
    cin>>k;
    long long int a[n],i,lb=0,ub=n-1;
    for(i=0;i<n;i++) a[i]=rand();
    auto start=high_resolution_clock::now();
    val=selection(a,lb,ub,k-1);
    cout<<k<<"th minimum is "<<val<<"\n";
    auto stop=high_resolution_clock::now();
    auto duration=duration_cast<milliseconds>(stop-start);
    cout<<"Time taken(ms) "<<duration.count()<<"\n";
    //for(int i=0;i<n;i++) cout<<a[i]<<" ";

}
int selection(long long int *a,long long int lb,long long int ub, long long int k)
{
    if(lb==ub) return a[lb];
    else
    {
        long long int l;
        l=partition(a,lb,ub);
        if(l==k) return a[k];
        else if(l>k) return(selection(a,lb,l-1,k));
        else return(selection(a,l+1,ub,k));
    }
}
int partition(long long int *a,long long int lb, long long int ub )
{
    //long long int s, p=(rand()%(ub-lb+1)+lb);
    //s=a[p]; a[p]=a[lb]; a[lb]=s;
    long long int pivot=a[lb],start=lb,end=ub;
    while(start<end)
    {
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end){
            long long int t=a[start];
            a[start]=a[end];
            a[end]=t;
        }
    }
    long long int t=a[lb];
    a[lb]=a[end];a[end]=t;
    return end;
}
